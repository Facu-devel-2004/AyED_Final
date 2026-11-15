#include <iostream>
#define N_PS 4
using namespace std;

typedef struct {
  int dia, mes, anio;
} FECHA;

typedef struct {
  char nombre[20];
  //Estructura fecha anidada por valor dentro de persona.
  FECHA nac;
  long int dni;
} persona;


