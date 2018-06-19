<<<<<<< HEAD
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
=======

#include "Respuesta.hpp"
#include "SocketDatagrama.h"
#include "Mensaje.h"

Respuesta::Respuesta(int pl) {
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje *Respuesta::getRequest(void) {
    
    /* Para comprobar que recibio un dato */
    int size = sizeof(struct mensaje);
    PaqueteDatagrama pack(size);
    
    socketlocal->recibe(pack);
    cout << "¡Ya conecto!" << endl;
    cout << "Recibio paquete " << endl;
    
    struct mensaje msg;
    
    // Copia los datos recibidos a una estructura
    memcpy(&msg, pack.obtieneDatos(), size);

    memcpy(&msg.IP, pack.obtieneDireccion(),sizeof(char)*16);

    msg.puerto = pack.obtienePuerto();

    // Imprime valores recibidos
    cout << "********** Values **********" << endl;
    cout << "msg.TP: " << msg.messageType << endl;
    cout << "msg.ID: " << msg.requestId << endl;
    cout << "msg.IP: " << msg.IP << endl;
    cout << "msg.PT: " << msg.puerto << endl;
    cout << "msg.OP: " << msg.operationId << endl;
    cout << "msg.AR: " << msg.arguments << endl;
    cout << "****************************" << endl;


    cout << "IP client: " << pack.obtieneDireccion() << endl;
    
	return &msg;
}


void Respuesta::sendReply(char *respuesta, char *ipClient, int puertoCliente) {
    
    cout << "Respuesta: " << respuesta << endl;
    
    int size = strlen(respuesta);
    cout << "Tamaño: " << size << endl;
    
    PaqueteDatagrama paq(respuesta, size, ipClient, puertoCliente);
    socketlocal->envia(paq);
    
    cout << "Enviado" << endl;
>>>>>>> efb64fd6f350525eaf2eeec353904f4801b31ac1
}
