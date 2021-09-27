#include "ejercicio1.c"
#include "practica4.c"

void servidor(void);
void pideFrasesServidor(int sockfd);

int main(){
	servidor();
	return (0);
}


//Lanza el proceso servidor
void servidor(void){
	int sockfd,newsockfd;
        socklen_t tam;
        struct sockaddr_in servidor,cliente;
	printf("Inicializamos el servidor.\n");

	//Creamos el socket tcp 
	if((sockfd=socket(PF_INET,SOCK_STREAM,0))==-1)
		error("socket");
        //Preparamos la estructura y el socket
        preparaConexion(sockfd,&servidor);

        if(bind(sockfd,(struct sockaddr*)&servidor,sizeof(struct sockaddr))==-1)
		error("bind");

	if(listen(sockfd,MAXCONN)==-1)
		error("listen");
      
	printf("Escuchando en %s:%d\n",inet_ntoa(servidor.sin_addr),PUERTO);
	fflush(stdout);

	tam=sizeof(struct sockaddr_in);
	if((newsockfd=accept(sockfd,(struct sockaddr*)&cliente,&tam))==-1)
		error("accept");
		
        else close(sockfd);

	pideFrasesServidor(newsockfd);
	//Cerramos el socket
	close(newsockfd);
       printf("Cierra el servidor\n");
       fflush(stdout);

}


//Pide una frase al usuario y la envia al lado opuesto
void pideFrasesServidor(int sockfd){
char *linea=calloc(1,TAMBUFFER);
	while(1){
                //Si el usuario introduce Adios, le enviamos al cliente la palabra y salimos
		if(pideFrase("Servidor.Introduce una frase:",linea)){
			envia(sockfd,linea);
			break;
		}
		envia(sockfd,linea);
		linea=recive(sockfd);
		if(compruebaSalida(linea))
                     break;
                printf("%s",linea);
		fflush(stdout);
	}
}
