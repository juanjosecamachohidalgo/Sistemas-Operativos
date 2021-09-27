#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>

main(int argc, char *argv[])
{
  struct stat buf;
  struct passwd *pwd;

  if (argc != 2)
    {
      printf("Debe pasar un parametro al ejecutar el programa\n");
      exit(1);
    }

  if (stat(argv[1], &buf)==-1)
    {
      printf("Ese archivo o directorio no existe\n");
      exit(1);
    }
  
  //S_IFMT= 0170000 -> define tipo de archivo
  if ((buf.st_mode & S_IFMT)==S_IFDIR)
	printf("Se trata de un directorio\n");
  else
	printf ("Se trata de un fichero\n");

  printf("Informacion:\n");
  printf("Permisos para el propietario(owner): ");
  switch(buf.st_mode & 0000700)
    {
    case 0700 : printf("r w x\n");
      break;
    case 0600 : printf("r w -\n");
      break;
    case 0500 : printf("r - x\n");
      break;
    case 0400 : printf("r - -\n");
      break;
    case 0300 : printf("- w x\n");
      break;
    case 0200 : printf("- w -\n");
      break;
    case 0100 : printf("- - x\n");
      break;
    case 0000 : printf("- - -\n");
    }
  printf("Permisos para el grupo(group): ");
  switch(buf.st_mode & 0000070)
    {
    case 0070 : printf("r w x\n");
      break;
    case 0060 : printf("r w -\n");
      break;
    case 0050 : printf("r - x\n");
      break;
    case 0040 : printf("r - -\n");
      break;
    case 0030 : printf("- w x\n");
      break;
    case 0020 : printf("- w -\n");
      break;
    case 0010 : printf("- - x\n");
      break;
    case 0000 : printf("- - -\n");
    }
  printf("Permisos para el resto (others): ");
  switch(buf.st_mode & 0000007)
    {
    case 0007 : printf("r w x\n");
      break;
    case 0006 : printf("r w -\n");
      break;
    case 0005 : printf("r - x\n");
      break;
    case 0004 : printf("r - -\n");
      break;
    case 0003 : printf("- w x\n");
      break;
    case 0002 : printf("- w -\n");
      break;
    case 0001 : printf("- - x\n");
      break;
    case 0000 : printf("- - -\n");
    }

  pwd = getpwuid(buf.st_uid);
  if (pwd != NULL)
	printf ("El propietario es: %d - %s\n", buf.st_uid, 
		pwd->pw_name);
  else
	printf ("El propietario es: %d - desconocido\n", buf.st_uid);
}

