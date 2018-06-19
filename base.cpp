#include "base.h"
#include <stdio.h>
#include "voto.h"
# include <string>
using namespace std;
base::base(){}
int base::guardar(char *str){
     FILE *archivo;
     int status;
  archivo = fopen("votos.txt", "a+");// añadir, lectura y escritura, el cursor se situa al final del fichero. Si el fichero no existe, se crea.
  //printf(" info vot %s",toString(v));
  if(!archivo){
    perror("no pude ser creada la base ...");
    fclose(archivo);
    return -1;
  }
  status =  fprintf(archivo, "%s", str);
  fclose(archivo);
  return status;
}

int base::buscar(char *tel){
  FILE *archivo;
  archivo = fopen("voto.txt", "r");
  if(!archivo){
    perror("no pude ser creada la base ...");
    fclose(archivo);
    return -1;
  }
  char *aux = (char*)calloc(50,sizeof(char));
  string cadena;
  while (fscanf(archivo,"%s",aux) != EOF){
    cadena = aux;
  }
  return 1;
}
