#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>

int32_t main(int argc, char const *argv[]){
	int32_t borra;
	char buffer[512];

	/*getcwd se muete a la bash para el directorio actual*/
	printf("El directorio actual es: %s\n", getcwd(buffer,512));
	/*chir change direc*/
	chdir("/home/karinaflo/Documents/CLinux/carpetas/");
	mkdir("./directorio1", 0755);
	mkdir("./directorio2", 0755);
	printf("\nSe crearon los directorios");
	printf("Deseaa borrar el directorio1? (1.si 2:no)\n");
	scanf("%d",&borra);

	if(borra == 1){
		rmdir("./directorio1");
	}

	return 0;

}
