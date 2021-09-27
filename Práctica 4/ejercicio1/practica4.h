#ifndef __PRACTICA4_H
#define __PRACTICA4_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stddef.h>


#define TAMBUFFER (40)
#define PUERTO    (4001)
#define MAXCONN   (2)
#define SALIDA    "Adios"


int compruebaSalida(char *linea);
int pideFrase(char *msg,char *frase);
void error(char *error);

#endif
