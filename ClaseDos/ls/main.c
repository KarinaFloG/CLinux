#include <stdio.h>
#include <dirent.h>

/*  ino = #SerialArchivo
	ino_t d_ino

	char d_name[]
*/

//Path el contenido de la ruta que queremos qu nos muestre
int listdir(const char *path){
	struct dirent *entry;
	DIR *dp;
	dp = opendir(path);

	if(dp  == NULL){
		perror("opendir");
		return -1;
	}

	//readdir Lee el contenido del directorio que le estamos pasando
	while((entry == readdir(dp))){
		puts(entry->d_name);
	}
	closedir(dp);
	return 0;
}

int main(int argc, char **argv){
	int counter = 1;

	if(argc == 1){
		listdir(".");
	}

	while(++counter <= argc){
		printf("Listando %s...", argv[counter-1]);
		listdir(argv[counter-1]);
	}
}