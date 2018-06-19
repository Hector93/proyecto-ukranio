#include "voto.h"
#include <malloc.h>
#include <string.h>
#include <string>
Voto::Voto(char *num, char *rfc,char partido){
  
  memcpy(v.numero,num,sizeof(char)*10);
  memcpy(v.RFC, rfc,sizeof(char)*13);
  v.partido = partido;
}
std::string  Voto::toString(){
  //char *string = (char*)calloc(30,sizeof(char));
  string auxRFC = v.RFC;
  string auxNumero = v.numero;
  // string auxPartido = v.partido;
  std:: string s = auxRFC+" "+auxNumero+" "+v.partido;
  return s;
}


