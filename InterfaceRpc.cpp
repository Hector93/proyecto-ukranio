#include "InterfaceRpc.h"

void* nop(void*){
  return (void*)"funciona?";
}

fptr selectOp(int op){
  switch(op){
  case 0: return guardar;
  case 1: return buscar;
  default: return nop;
  }
}
