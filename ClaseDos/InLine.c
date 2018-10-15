#include <stdio.h>.h
#include <stdlib.h>

inline int suma(int, int);

struct hora{
	int horas: 5; //5 bits para 24 horas
	int minutos: 6;
	int segundos: 6;
}

int main(int argc, char** argv){
	printf("Tamanio: %d\n", sizeof(struct hora));
	int a,b:
	//Atoi cambia una caddena a un entero
	a =atoi(argv[1]);
	b =atoi(argv[2]);
	printf("La suma de los argumentos es: %d\n", a+b);
	return 0;
}

//Funcion inline
int suma(int a, int b){
	return a + b;
}