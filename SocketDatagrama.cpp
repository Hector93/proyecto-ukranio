/*
SocketDatagrama.cpp
Es donde se encuentran los metodos del socket
*/
#include "SocketDatagrama.h" 
#include "PaqueteDatagrama.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <math.h>
#include <errno.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	s = socket(AF_INET, SOCK_DGRAM,0);
	bzero((char *)&direccionLocal,sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr=INADDR_ANY;
	direccionLocal.sin_port = htons(pto);
	bind(s,(struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::SocketDatagrama() {
	s = socket(AF_INET, SOCK_DGRAM,0);
	bzero((char *)&direccionLocal,sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr=INADDR_ANY;
	direccionLocal.sin_port = htons(0);
	bind(s,(struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
  socklen_t lon = sizeof(direccionForanea);
  int aux = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &lon);
  p.inicializaIP(inet_ntoa(direccionForanea.sin_addr));
  p.inicializaPuerto(htons(direccionForanea.sin_port));
return aux;
}

int SocketDatagrama::recibe(PaqueteDatagrama &p, time_t seconds, suseconds_t microsegundos){
  timeout.tv_sec = seconds;
  timeout.tv_usec = microsegundos;
  socklen_t lon = sizeof(direccionForanea);
  setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
  int aux = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &lon);
  if(aux < 0){
    if(errno == EWOULDBLOCK){
      fprintf(stderr, "tiempo para recepcion transcurrido\n");
      return -1;
    }else{
      fprintf(stderr, "Error en recvfrom\n");
      return -1;
    }
  }
  return aux;
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
  bzero((char *)&direccionForanea, sizeof(direccionForanea));
  direccionForanea.sin_family = AF_INET;
  direccionForanea.sin_port = htons(p.obtienePuerto());
  direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
  int aux = sendto(s,(char *)p.obtieneDatos(), p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea,sizeof(direccionForanea));
  return aux;
}
