#ifndef MENSAJE_H
#define MENSAJE_H
#define TAM_MAX_DATA 4000
#define TAM_CABECERA sizeof(int) * 4 + sizeof(char)*16


struct mensaje{
  int messageType;
  unsigned int requestId;
  char IP[16];
  int puerto;
  int operationId;
  char arguments[TAM_MAX_DATA];
};

#endif
