#ifndef INTERFACE_RPC_H
#define INTERFACE_RPC_H

#include "FuncionesUsuario.h"

typedef void* (*fptr)(void*);

void* nop(void*);

fptr selectOp(int op);

#endif
