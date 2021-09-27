#ifndef __EJERCICIO1_H
#define __EJERCICIO1_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void preparaConexion(int sockfd, struct sockaddr_in *conexion);
char* recive(int sockfd);
void envia(int sockfd,char *linea);

#endif
