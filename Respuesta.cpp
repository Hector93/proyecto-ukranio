
#include "Respuesta.h"
#include "PaqueteDatagrama.h"
#include "InterfaceRpc.h"

static unsigned contadorRequest = 0;
static unsigned anteriorRequest = 1;

Respuesta::Respuesta(int pl){
  socketlocal = new SocketDatagrama(pl);
  cout << "creo socket" << endl;
}

struct mensaje* Respuesta::getRequest(){
  PaqueteDatagrama datagrama = PaqueteDatagrama(sizeof(struct mensaje));
  mensaje *temp;
  fptr tempFunc;
  void * resultados;
  char *aux;
  socketlocal->recibe(datagrama);
  aux = datagrama.obtieneDatos(); 
  //cout << "llega\nIP: " << ((mensaje*)aux)->IP << ", puerto: " << ((mensaje*)aux)->puerto << ", operationId: " << ((mensaje*)aux)->operationId << ", arguments: " << ((mensaje*)aux)->arguments << endl; 
  temp = new mensaje();
  memcpy(temp, aux, sizeof(struct mensaje));
  contadorRequest = temp->requestId;
  if(anteriorRequest == contadorRequest){
    	cout << "Se ignoró petición repetida: " << anteriorRequest << endl;
  }
  else{
    tempFunc = selectOp(temp->operationId);
    resultados = tempFunc(temp->arguments);
    temp->messageType = 1; // respuesta
    memset(temp->IP, 0, sizeof(temp->IP));
    memset(temp->arguments, 0, TAM_MAX_DATA);
    memcpy(temp->IP, datagrama.obtieneDireccion(), sizeof(temp->IP));
    temp->puerto = datagrama.obtienePuerto();
    //cout << "sizeof args: " << sizeof(((mensaje*)aux)->arguments) << endl;
    snprintf(temp->arguments,4000, "%s", (char*)resultados);
    anteriorRequest = contadorRequest;
    delete [](char*)resultados;
  }
  return temp; 
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){  
  PaqueteDatagrama datagrama = PaqueteDatagrama(respuesta, sizeof(struct mensaje), ipCliente, puertoCliente);
  //mensaje *aux = (mensaje*)datagrama.obtieneDatos();
  //cout << "sendreply\nIP: " << aux->IP << ", puerto: " << aux->puerto << ", operationId: " << aux->operationId << ", arguments: " << aux->arguments << endl; 
  socketlocal->envia(datagrama);
  //puts("envio");
}

Respuesta::~Respuesta(){
  delete socketlocal;
}
