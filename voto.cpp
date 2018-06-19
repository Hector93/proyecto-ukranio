#include "voto.h"
#include <malloc.h>
#include <string.h>
#include <string>
#include <vector>
Voto::Voto(){
  generaVoto();
}

Voto::Voto(char *num, char *rfc,char partido){
  
  memcpy(v.numero,num,sizeof(char)*10);
  memcpy(v.RFC, rfc,sizeof(char)*13);
  v.partido = partido;
}

Voto::Voto(char *str){
  char *ptr;
  vector <string> aux;
  aux.reserve(3);
  std::string::size_type sz;   // alias of size_t
  ptr = strtok(str," ");
  while(ptr != NULL)
    {
      aux.push_back(ptr);
      ptr = strtok(NULL, " ");
    }
  memcpy(v.RFC, aux.at(0).c_str(),sizeof(char)*13);
  memcpy(v.numero, aux.at(1).c_str(),sizeof(char)*11);
  v.partido= std::stoi (aux.at(2),&sz);
    
}
void Voto::regenera(){
  generaVoto();
}

std::string  Voto::toString(){
  //char *string = (char*)calloc(30,sizeof(char));
  string auxRFC = v.RFC;
  string auxNumero = v.numero;
  std:: string s = auxRFC+" "+auxNumero+" "+to_string(v.partido);
  return s;
}

void Voto::generaVoto(){
  unsigned long int numero = (rand() % 99999999);
  snprintf(v.numero, 11, "%ld", numero + 5500000000);
  v.numero[10] = '\0';
  v.RFC[0] = rand() % 25 + 65;
  v.RFC[1] = rand() % 25 + 65;
  v.RFC[2] = rand() % 25 + 65;
  v.RFC[3] = rand() % 25 + 65;
  sprintf(&v.RFC[4],"%02d", rand() % 99);
  sprintf(&v.RFC[6],"%02d", rand() % 12);
  sprintf(&v.RFC[8],"%02d", (rand() % 30)+1);
  v.partido = rand()%12;
}

string Voto::getRFC(){
  string auxRFC = v.RFC;
  return auxRFC;
}

string Voto::getNum(){
  string auxNumero = v.numero;
  return auxNumero;
}
