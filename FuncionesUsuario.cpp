#include <iostream>

#include <string.h>
#include "FuncionesUsuario.h"
#include "voto.h"

static int nbd=0;

void* guardar(void* Voto){

  voto* temp = (voto*)Voto;
  //  std::cout << temp->numero << ", " << temp->RFC << ", " << (int)temp->partido << std::endl;
  std::cout << (char*) Voto << std::endl;
  return 0;
}


//1
void* buscar(void* numero){
  char* rfc = new char[10];
  std::cout<<"busco: "<<std::endl;
  return rfc;
}
