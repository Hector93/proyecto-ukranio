#include <stdio.h>
#include <iostream>
#include <random>
#include <atomic>
#include <thread>
#include "voto.h"
#include "Solicitud.h"

using namespace std;

const unsigned int numVotos = 88700000;

Voto asd;
//Solicitud sol;
char *IP;
int puerto;

unsigned int numeroEnvio = 0;
bool listo1(false);
bool listo2(false);
bool listo3(false);

void Hilo1(char *IP, int puerto,bool &ready){
  unsigned int numEnvioActual = 0;
  Solicitud sol = Solicitud();
  cout << IP << endl;
  while(numEnvioActual < numVotos){
    if(numeroEnvio > numEnvioActual && ready == true){
      sol.doOperation(IP, puerto, 0, asd.toString().c_str());
      ready = false;
      numEnvioActual++;
    }
  }
}

int main(int argc, char** argv){
  if (argc != 4){
    cout << "Error en argumentos" << endl; 
    return -1;
  }
  
  IP = argv[1];
  puerto = atoi(argv[2]);
  //sol = Solicitud();
  thread th1(Hilo1,argv[1],puerto,ref(listo1));
  thread th2(Hilo1,argv[2],puerto,ref(listo2));

  srand(time(NULL));

  asd = Voto();

  while(numeroEnvio < numVotos){
    if(listo1 == false && listo2 == false){
      asd.regenera();
      numeroEnvio++;
      listo1 = true;
      listo2 = true;
      listo3 = true;
    }
  }

  /*
    for(numeroEnvio = 0; numeroEnvio < numVotos; numeroEnvio++){
    asd.regenera();
    listo = true;
    //cout << sol.doOperation(IP, puerto, 0, asd.toString().c_str());
    }
  */
  th1.join();
  //  th2.join();
  puts("termino\n");
  return 0;
}
