
#ifndef Respuesta_hpp
#define Respuesta_hpp

#include <stdio.h>
#include "SocketDatagrama.h"
#include "Mensaje.h"

class Respuesta{
public:
    Respuesta(int pl);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
    SocketDatagrama *socketlocal;
};

#endif /* Respuesta_hpp */
