#include <stdio.h>
#include <iostream>
#include <random>
#include <atomic>
#include <thread>
#include "voto.h"
#include "Solicitud.h"
#include "semaforo.h"

using namespace std;

const unsigned int numVotos = 88700000;
//const unsigned int numVotos = 10;

Voto asd;
int puerto;

atomic<unsigned int> numeroEnvio(0);

Semaforo sem1;
Semaforo sem2;
Semaforo sem3;

atomic<bool> listo1(false);
atomic<bool> listo2(false);
atomic<bool> listo3(false);

void Hilo1(char *IP, int puerto,atomic<bool> &ready,Semaforo & sem){
  unsigned int numEnvioActual = 0;
  Solicitud sol = Solicitud();
  cout << IP << endl;
  while(numEnvioActual < numVotos){
    sem.wait();
    if(numeroEnvio > numEnvioActual && ready == true){
      sol.doOperation(IP, puerto, 0, asd.toString().c_str());
      
      ready = false;
      numEnvioActual++;
    }
    sem.post();
  }
}

int main(int argc, char** argv){
  if (argc != 5){
    cout << "Error en argumentos" << endl; 
    return -1;
  }

  sem1.init(1);
  sem2.init(1);
  sem3.init(1);
  
  puerto = atoi(argv[4]);
  thread th1(Hilo1,argv[1],puerto,ref(listo1),ref(sem1));
  thread th2(Hilo1,argv[2],puerto+1,ref(listo2),ref(sem2));
  thread th3(Hilo1,argv[3],puerto+2,ref(listo3),ref(sem3));

  srand(time(NULL));
  asd = Voto();

  while(numeroEnvio < numVotos){
    sem1.wait();
    sem2.wait();
    sem3.wait();
    if(listo1 == false && listo2 == false && listo3 == false){
      asd.regenera();

      //cout << asd.toString();
      numeroEnvio++;
      listo1 = true;
      listo2 = true;
      listo3 = true;
    }
    sem1.post();
    sem2.post();
    sem3.post();
  }

  th1.join();
  th2.join();
  th3.join();
  puts("termino\n");
  return 0;
}
