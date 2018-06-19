#include <stdio.h>
#include <iostream>
#include <random>
#include "voto.h"
#include "Solicitud.h"

using namespace std;

const unsigned int numVotos = 88700000;



int main(int argc, char** argv){
  if (argc != 3){
    cout << "Error en argumentos" << endl; 
    return -1;
  }
  
  char *IP = argv[1];
  int puerto = atoi(argv[2]);
  Solicitud sol = Solicitud();

  srand(time(NULL));
  voto test;
  Voto asd = Voto();
  for(unsigned int i = 0; i < numVotos; i++){
    asd.regenera();
    cout << sol.doOperation(IP, puerto, 0, asd.toString().c_str());
  }

      puts("termino\n");
  return 0;
}
