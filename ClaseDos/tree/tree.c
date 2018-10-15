#include <stdio.h> //snprintf, printf
#include <stdlib.h> //free, calloc,perror
#include <stdint.h>
#include <dirent.h> //opendir,readdir, closedir
#include <string.h> //strlen, strcmp

void listaDir(const char*, int32_t, int32_t*, int32_t*);

int32_t main(int32_t argc, char *argv[]){
	//Se valida la cantidad de argumentos validados
	if(argc == 2){
		int32_t dirs = 0, archs = 0; //Variables donde se cuentan los elementos
		printf("[%s]\n", argv[1]);
		listaDir(argv[1],1,&dirs,&archs); //Se pasan por referencia
		printf("\nDirectorios: %d, Archivos: %d\n", dirs, archs);
		return EXIT_SUCCESS;
	}else{
		printf("Error al ingresar los parametros\n");
		return EXIT_FAILURE;
	}
}

void listaDir(const char *rutaParcial, int32_t nivel, int32_t *d, int32_t *a){
	char *ruta = (char*)calloc(1024, sizeof(char));
	DIR *carpeta;

	struct dirent *contenido;

	if(!ruta){
		perror("Error: ");
		return;
	}	

	if(!(carpeta = opendir(rutaParcial))){
		perror("Error");
		return;
	}

	//Valida contenido
	if(!(contenido = readdir(carpeta))){
		perror("Error");
		return;
	}

	//Muestra los archivos
	do{
		if(contenido -> d_type == DT_DIR){
			snprintf(ruta, 1023, "%s%s", rutaParcial, contenido->d_name);

			if(strcmp(contenido->d_name,".") == 0 || strcmp(contenido->d_name, "..") == 0){
				continue;
			}
			printf("%*s[%s]\n", nivel*4,"", contenido->d_name);
			(*d)++;
			listaDir(ruta,nivel+1,d,a);
		}else{
			printf("%*s- %s\n",nivel*4,"",contenido->d_name);
			(*a)++;
		}
	}while(contenido = readdir(carpeta));

	closedir(carpeta);
	free(ruta);
	return;
}

/*O_RONLY
  O_WONLY
  O_WRONLY*/