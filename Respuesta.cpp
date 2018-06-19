
#include "Respuesta.hpp"
#include "SocketDatagrama.h"
#include "mensaje.hpp"

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
}
