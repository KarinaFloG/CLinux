#include <stdio.h>
#include <stbool.h>//COntiene macros de true y false
#include <stdlib.h>
#include <fcntl.h> // Manejo de archivos en POSIX
#include <>
char* leer(char**);
bool escribir(char*, char**);

int tamanoArchivo;

int main(int argc, char **argv){
	return (!escribir(leer(argv[1]),"r");)
}

char* leer(char** argv){
	char* guardaDatos;

	FILE* fuente = fopen(argv[1], "r");

	if(fuente == NULL){
		printf("Error\n");
		NULL;
	}

	fseek(fuente,0,SEEK_END); //Recorre todo el archivo para determinar todo su tamaño
	tamanoArchivo = ftell(fuente);
	rewind(fuente); //Regresa el cursor al principio del archivo 

	guardaDatos = (char*)malloc(tamanoArchivo*sizeof(char));

	if(guardaDatos == NULL){
		printf("Error al reservar memoria:( ");
		fclose(fuente);
		return NULL;
	}

	//Lee el archiv fuente y lee tantos elementos de el tamaño y los guarda en la cadena
	fread(guardaDatos,sizeof(char),tamanoArchivo,fuente);

	return guardaDatos;
}

bool escribir(char* escribir,char** argv){

	FILE* destino = fopen(argv[2],"w");
	if(destino == NULL){
		printf("Error\n");
		NULL;
	}


	fwrite(escribir, sizeof(char),tamanoArchivo,destino);
	fclose(destino);
	free(escribir);
	return true;

}