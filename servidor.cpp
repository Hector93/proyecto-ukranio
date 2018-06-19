#include <iostream>
#include "Respuesta.h"

using namespace std;

int main (int argc, char* argv[])
{	
  if (argc != 2){
    cout << "Error en argumentos" << endl; 
    return -1;
  }
	
  int puerto = atoi(argv[1]); 
  unsigned contadorRequest = 0;
  unsigned anteriorRequest = 1;

  cout << "Servidor en puerto: " << puerto << endl;
  Respuesta res = Respuesta(puerto);

  while(1){
    mensaje* resultado = res.getRequest(); 
    contadorRequest = resultado->requestId;
    //cout << "id: " << resultado->requestId <<endl; 
    //cout << "contador: " << contadorRequest << endl;
    //cout<<"anterior: "<<anteriorRequest <<endl;
    //cout << "resultado: " << resultado->arguments <<endl;
    if(anteriorRequest == contadorRequest){
      cout << "Se ignoró petición repetida: " << anteriorRequest << endl;
      continue;
    }
    else{
      //cout << "Se ejecutó petición: " << resultado->operationId << endl;
      res.sendReply((char*)resultado, resultado->IP, resultado->puerto);
      anteriorRequest = contadorRequest;
      delete resultado;
    }
  } 
  return 0;
}
