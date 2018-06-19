#include <iostream>
# include "base.h"
#include <string.h>
#include "FuncionesUsuario.h"
#include "voto.h"

void* guardar(void* Voto){
  base bd = base();
  bd.guardar((char *)Voto);
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
