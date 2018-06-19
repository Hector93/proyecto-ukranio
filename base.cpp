#include "base.h"
#include <stdio.h>
#include "voto.h"
int base::guardar(Voto v){
     FILE *archivo;
  archivo = fopen("votos.txt", "a+");// añadir, lectura y escritura, el cursor se situa al final del fichero. Si el fichero no existe, se crea.
  //printf(" info vot %s",toString(v));
  return fprintf(archivo, "%s", v.toString().c_str());
  fclose(archivo);

}
int base::buscar(char *tel){
  FILE *archivo;
  
}
