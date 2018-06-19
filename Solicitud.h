#ifndef SOLICITUD_H
#define SOLICITUD_H
#include "SocketDatagrama.h"
#include "Mensaje.h"
class Solicitud{
 public:
  Solicitud();
  char * doOperation(char *IP, int puerto, int operationId, char *arguments);
  string to_string();
  ~Solicitud();
private:
  SocketDatagrama *socketlocal;
  mensaje mens;
  unsigned int requestId;
};

#endif
