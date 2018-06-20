#include "Solicitud.h"
#include "Mensaje.h"

Solicitud::Solicitud(){
  socketlocal = new SocketDatagrama(0);
  requestId = 0;
}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, const char *arguments){
  mensaje sol; 
  //cout << "solicitud\nIP: " << IP << ", puerto: " << puerto << ", operationId: " << operationId << ", arguments: " << arguments << endl; 
  sol.messageType = 0; //solicitud
  //cout << "reqId: " << requestId << endl;
  sol.requestId = requestId;
  memcpy(sol.IP, IP, sizeof(sol.IP));
  sol.puerto = puerto;
  sol.operationId = operationId;
  memcpy(sol.arguments, arguments, TAM_MAX_DATA);
  PaqueteDatagrama datagrama = PaqueteDatagrama(&sol, sizeof(struct mensaje), IP, puerto);
  mens = *(mensaje*)datagrama.obtieneDatos();
  socketlocal->envia(datagrama); 
  //  socketlocal->recibe(datagrama);
  int i;
  for(i = 0; socketlocal->recibe(datagrama, 1, 0) <= 0 && i < 3; i++){
    if(i >= 6){
      fprintf(stderr, "Servidor no disponible intente mas tarde %s, %d",IP, puerto);
      return NULL;
      exit(EXIT_FAILURE);
    }else{
      socketlocal->envia(datagrama); 
    }
  }
  //cout << "respuesta\nIP: " << test->IP << ", puerto: " << test->puerto << ", operationId: " << test->operationId << ", arguments: " << test->arguments << endl;
  memcpy(&mens, datagrama.obtieneDatos(), sizeof(struct mensaje));
  //  mens = (mensaje*)datagrama.obtieneDatos();
  // cout << "res:"<<mens.arguments<<endl;
  requestId++;
  return mens.arguments;
}

string Solicitud::to_string(){
  //  return "[" + std::to_string(x) + "," + std::to_string(y) + "]" + "[" + std::to_string(r) + "," + std::to_string(theta) + "]";
  return "not implemented";
}

Solicitud::~Solicitud(){
  delete socketlocal;
}
