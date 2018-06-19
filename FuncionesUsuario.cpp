#include <iostream>

#include <string.h>
#include "FuncionesUsuario.h"
#include "voto.h"

static int nbd=0;
/*const std::vector<std::string> explode(const std::string& s, const char& c){
  std::string buff{""};
  std::vector<std::string> v;
  
  for(auto n:s){
    if(n != c) buff+=n; else
      if(n == c && buff != "") { v.push_back(buff); buff = ""; }
  }
  if(buff != "") v.push_back(buff);	
  return v;
}

void * invierteCadena(void * cadena){
  std::string stringCadena((char*)cadena);
  std::vector<std::string> vectorPalabras{explode(stringCadena, ' ')};
	
  for(unsigned int i = 0; i < vectorPalabras.size(); i++){
    if(i == 0)
      continue;
    else
      vectorPalabras[i].append(" "); 
  }
  
  std::string invertida = vectorPalabras[vectorPalabras.size()-1]; 
  vectorPalabras.pop_back();
  for(int i = vectorPalabras.size()-1; i >= 0; i--){
    invertida.append(vectorPalabras[i]);
  }
	
  char * cadenaInvertida = new char[invertida.length()+1];
  strcpy(cadenaInvertida, invertida.c_str());	
  return (void*)cadenaInvertida;
}

void* leeCuenta(void* nada){
  char * cadenaInvertida = new char[20];
  sprintf(cadenaInvertida, "%d", nbd);
  return (char*)cadenaInvertida;
}
void* depositaCuenta(void* entero){
  int valor = atoi((char*) entero);
  nbd += valor;
  return 0;
  }*/

//0
void* guardar(void* Voto){

  voto* temp = (voto*)Voto;
  //  std::cout << temp->numero << ", " << temp->RFC << ", " << (int)temp->partido << std::endl;
  std::cout << (char*) Voto << std::endl;
  return 0;
}


//1
void* buscar(void* numero){
  char* rfc = new char[10];
  std::cout<<"busco: "<<std::endl;
  return rfc;
}
