#ifndef VOTO_H
#define VOTO_H
# include <string.h>
#include <string>
#include <iostream>
typedef struct{
  char numero[11];
  char RFC[13];
  char partido;
}voto;

using namespace std;
class Voto{

private:
  voto v;

  void generaVoto();
  
public:
  Voto();
  Voto (char *str);
  Voto(char *num, char *rfc,char partido);
  void regenera();
  string getRFC();
  string getNum();
  //char *toString();
  std::string toString();
};
#endif
