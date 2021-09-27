#include "ejercicio1.h"
#include "practica4.h"

//Lee una cadena del socket
char* recive(int sockfd){
	char *linea=calloc(1,TAMBUFFER); //imporante usar calloc
	if(recv(sockfd,linea,TAMBUFFER,0)==-1)
		error("recv");
	return linea;
}

//Envia una cadena al socket
void envia(int sockfd,char *linea){
	if(send(sockfd,linea,strlen(linea),0)==-1)
		error("send");
}

//Establecemos la structura para utilizarla
void preparaConexion(int sockfd,struct sockaddr_in *conexion){
	int opcion=1;
	//Preparamos la conexion 
	conexion->sin_family=AF_INET;
	conexion->sin_port=htons(PUERTO);
	conexion->sin_addr.s_addr=htonl(INADDR_ANY);
	memset(&conexion->sin_zero,0,sizeof(conexion->sin_zero));
	if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opcion,sizeof(opcion))==-1)
		error("settsockopt");
}
