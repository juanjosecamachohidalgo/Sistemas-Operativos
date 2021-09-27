#include "practica4.h"

//Funcion de tratamiento de errores generica
void error(char *error){
	perror(error);
	printf("\nError detectado.");
	fflush(stdout);
	exit(EXIT_FAILURE);
}

// Comprueba si el usuario ha introducido la palabra de salida
int compruebaSalida(char *linea){
	return strncmp(linea,SALIDA,sizeof(SALIDA))==0;
}


//Pide una frase al usuario por teclado
int pideFrase(char *msg,char *frase){
 printf("\n%s",msg);
 fflush(stdout);
 fgets(frase,TAMBUFFER,stdin);
 if(frase[strlen(frase)-1]!='\n')//Limpiamos el buffer
	 while(getchar()!='\n'); 
 frase[strlen(frase)-1]=0; //Le sustituimos el newline
	return compruebaSalida(frase);
}

