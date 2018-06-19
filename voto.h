#ifndef VOTO_H
#define VOTO_H
typedef struct{
  char numero[10];
  char RFC[13];
  char partido;
}voto;
char *toString();
#endif
