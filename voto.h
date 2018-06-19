#ifndef VOTO_H
#define VOTO_H
# include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Voto{
typedef struct{
  char numero[10];
  char RFC[13];
  char partido;
}voto;
private:
  voto v;
  
  public:
  Voto(char *num, char *rfc,char partido);
  
  //char *toString();
  std::string toString();
};
#endif
