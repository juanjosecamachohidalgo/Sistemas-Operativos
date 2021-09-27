#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 88

void main()
{
	int i,IN,semid;
	char let;
	/*operaciones sobre semaforos*/
	struct sembuf sem_oper;
	union semun
	{
		in vat;
		struct semid_ds *semstat;
		unsigned short *array;
	}arg;

	semid=segmet(SEMKEY, 3, 0777 | IPC_CREAT); /*Inicializacion de los semaforos*/
	
	if (semid == -1)
	printf("Error, no se han creado bien los semaforos");

	arg.array=(unsigned short *) malloc (sieof(short)*3);
	arg.array[0]=15;/*Espacio libre*/
	arg.array[1]=0;/*Elemento disponible*/
	arg.array[2]=1;/*Manipulacion del buffer*/
	semctl (semid, 3, SETALL, arg);

	FILE* archivo;
	archivo = fopen("buffer.txt" , "r+");

	fseekk(archivo, 25, SEEK_SET);/*Movimiento del puntero dentro del fichero*/
	fwrite(&IN, sieof(int), 1, archivo);/*Escribe en la ultima posicion del valor en un hueco libre*/

		for(i=0; i<100; i++){

		/*WAIT espacio libre*/
		sem_oper.sem_num=0/*espacio libre*/
		sem_oper.sem_op=1;
		sem_op.sem_flg=SEM_UNDO;
		semop(semid, &sem_oper, 1);

		fseek(archivo, 25, SEEK_SET);/*movimiento del puntero en el fichero*/
		fread(&IN, sieof (int), 1, archivo); /*lee el valor de la posicion del puntero*/

		letra = `a´ + (i%26);/*Generacion de letras*/
		IN = (IN+1%25);
		fseek(archivo; IN, SEEK_SET);/*Puntero que indica la posicion en la que escribe*/
		fputc(letra, archivo); /*Escritura en el archivo*/
		
		fseek(archivo, 25, SEEK_SET); /*Movimiento del puntero en el fichero*/
		fwrite(&IN, sizeof(int) , 1, archivo);/*Actualiza el valor final del fichero*/

		/*Signal manipulacion del buffer*/
		sem_oper.sem_num=2/*buffer*/
		sem_oper.sem_op=1;
		sem_oper.sem_flg=SEM_UNDO;
		semop(semid, &sem_oper, 1);

		/*Signal elemento disponible*/
		sem_oper.sem_num=1/*elemento disponible*/
		sem_oper.sem_op=1;
		sem_oper.sem_flg=SEM_UNDO;
		semop(semid, &sem_oper, 1);
	}
	semctl(semid, 3,IPC_RMID, 0);
	free(arg.array);
	fclose(archivo);
	return 0;
}

