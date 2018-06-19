#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Respuesta.hpp"
#include "mensaje.h"

using namespace std;

int main() {

    Respuesta res(9091);

    while(true){
        cout << "Esperando conexion" << endl;
        struct mensaje msg = *res.getRequest();
        struct mensaje local;
        memcpy(local,msg, sizeof(msg));
        cout << "IP " << msg.IP << "PT " << msg.puerto << endl; 
        cout << msg.arguments << endl;
        //res.sendReply(msg.arguments, msg.IP, msg.puerto);


    }
    

    return 0;
}
