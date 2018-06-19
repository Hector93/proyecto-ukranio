#include <stdio.h>
#include <iostream>
#include <random>
#include "voto.h"

using namespace std;

const unsigned int numVotos = 88700000;

voto generaVoto(){
  voto Voto;
  unsigned long int numero = (rand() % 99999999);
  snprintf(Voto.numero, 10, "%ld", numero + 5500000000);
  Voto.numero[10] = '\0';
  Voto.RFC[0] = rand() % 25 + 65;
  Voto.RFC[1] = rand() % 25 + 65;
  Voto.RFC[2] = rand() % 25 + 65;
  Voto.RFC[3] = rand() % 25 + 65;
  sprintf(&Voto.RFC[4],"%02d", rand() % 99);
  sprintf(&Voto.RFC[6],"%02d", rand() % 12);
  sprintf(&Voto.RFC[8],"%02d", (rand() % 30)+1);
  Voto.partido = rand()%11;

  return Voto;
}

int main(){
  srand(time(NULL));
  voto test;
  for(unsigned int i = 0; i < numVotos; i++){
    test = generaVoto();
    cout << test.numero << ", " << test.RFC << ", " << (int)test.partido <<endl;
  }

  puts("termino\n");
  return 0;
}
