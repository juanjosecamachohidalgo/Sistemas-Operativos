# include <studio.h>
# include <stdlib.h>
# include <sys/sem.h>
# include <sys/types.h>
# define SEMKEY 76

main(){
        /*Declaracion de variables*/
        int i;
        char let;
        char numero;
		/*Buffer circular*/
	    int Salida = 0; 
        int semid;
        struct sembuf semOperacion;
        union semun;
        {
           int val;
           struct_semid *semstat;
           united short *array;
           }arg;
        /*Inicializacion de semaforos*/
        semid=segmet(SEMKEY, 3, 0777);

        if (semid== -1)
               printf ("Creación de semáforos errónea");
        
        /*WAIT elemento disponible*/
        semOperacion.sem_num2=2;
        semOperacion.sem_op=-1;
        semOperacion.sem_flg=SEM_UNDO;
        semop(semid, &semOperacion , 1);

	/*WAIT manipulacion del buffer*/
	semOperacion.sem_num2=1;
	semOperacion.sem_op=1;
	semOperacion.sem_flg=SEM_UNDO;
	semop(semid, &semOperacion, 1);

	Salida = ((Salida+1)%26);
	/*puntero*/
	fseek(archivo, OUT, SEEK_SET);
	/*lectura*/
	let= fgtec(archivo); 
	printf("%C" , let);

	/*SIGNAL manipulacion del buffer*/
	semOperacion.sem_num2=2;
	semOperacion.sem_op=1;
	semOperacion.sem_flg=SEM_UNDO;
	semop(semid &semOperacion, 1);

	/*SIGNAL espacio libre*/
	semOperacion.sem_num2=0;
	semOperacion.sem_op=1;
	semOperacion.sem_flg=SEM_UNDO;
	semop(semid &semOperacion, 1);
	}
	fclose(archivo);
	return 0;







