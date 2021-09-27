#include "ejercicio1.c"
#include "practica4.c"

void cliente(void);
void pideFrasesCliente(int sockfd);

int main(){
	cliente();
	return (0);
}

//Lanza el proceso cliente
void cliente(void){
	int sockfd;
        struct sockaddr_in servidor;
	printf("Inicializamos el cliente\n");

	//Creamos el socket tcp 
	if((sockfd=socket(PF_INET,SOCK_STREAM,0))==-1)
		error("socket");
        //Preparamos la estructura
        preparaConexion(sockfd,&servidor);
        sleep(2);
	// Nos conectamos al servidor
        if((connect(sockfd,(struct sockaddr *)&servidor,sizeof(struct sockaddr_in)))==-1)
		error("connect");

	pideFrasesCliente(sockfd);
	close(sockfd);
       printf("Cierra el cliente\n");
       fflush(stdout);
}

//Recibe una frase del usuario y pide otra
void pideFrasesCliente(int sockfd){
char *linea=calloc(1,TAMBUFFER);;
	while(1){
		linea=recive(sockfd);
		if(compruebaSalida(linea))
                     break;
                printf("%s",linea);
		fflush(stdout);
		if(pideFrase("Cliente.Introduce una frase:",linea)){
			envia(sockfd,linea);
			break;
		}
		envia(sockfd,linea);
                break;
	}
}
