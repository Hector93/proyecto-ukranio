#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Respuesta.hpp"
#include "Mensaje.h"
#include "voto.h"

using namespace std;

int main() {
    ofstream archivo;

    Respuesta res(9090);

    while(true){

        cout << "Esperando conexion" << endl;
        struct mensaje msg = *res.getRequest();
        struct mensaje local;
        memcpy(&local,&msg, sizeof(msg));
        cout << "IP " << msg.IP << "PT " << msg.puerto << endl; 
        cout << msg.arguments << endl;
        //res.sendReply(msg.arguments, msg.IP, msg.puerto);

        /*if(!archivo.is_open()){
                archivo.open("basededatos.txt", ios::app);
            }
            cout << "Telefono";
            getline(cin, voto.numero);
            cout << "RFC";
            getline(cin, voto.RFC);
            cout << "Partido";
            getline(cin, voto.partido);

            archivo << telefono << "," << rfc << "," << voto << endl;

            system("cls");

            cout << "Registro guardado";

            archivo.close();*/


    }
    

    return 0;
}
