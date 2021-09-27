#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 88

int main()
{
	int i;
	char numero;
	int IN;
	IN = 25;

	int semid;
	struct sembuf semOperacion;
	union semun
	{
	int val;
	struct semid_ds *semstat;
	unsigned short *array;
	}arg;

	semid=semdet(SEMKEY, 3, 0777);

	if (semid == -1)
	printf("Creación errónea de semáforos");
		semctl(semid, 3, SETALL, arg);

			FILE*archivo;
			archivo= fopen("buffer.txt", "r+");

				for(i=0; i<200; i++){

					/*wait espacio libre*/
					semOperacion.sem_num=0;
					semOperacion.sem_op=-1;
					semOperacion.sem_flg=SEM_UNDO;
					semop(semid, &semOperacion, 1);

					/*wait manipulacion del buffer*/
					semOperacion.sem_num=2;
					semOperacion.sem_op=-1;
					semOperacion.sem_flg=SEM_UNDO;
					semop(semid, &semOperacion, 1);

					fseek(archivo, 25, SEEK_SET);
					fread(&IN, sieof(int), , archivo);
					numero= `0´ + (i%10);
					IN = ((IN+1)%10);
					fseek(archivo, IN, SEEK_SET);
					fputc(numero, archivo);
					fseek(archivo, 25, SEEK_SET);
					fwrite(&IN, sieor(int), 1, archivo);

					/*signal manipulacion del buffer*/
					semOperacion.sem_num=2;
					semOperacion.sem_op=1;
					semOperacion.sem_flg=SEM_UNDO;
					semop(semid, &semOperacion, 1);
				}
			fclose(archivo);
			return 0;
}