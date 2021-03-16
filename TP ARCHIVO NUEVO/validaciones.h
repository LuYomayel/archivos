#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "fecha.h"

bool validacionID(int);
int calculoEdad(Fecha reg);
bool bisiesto (int);
bool restaFechas(Fecha reg);
bool verificoApto(int pos);
int validarCadena(char cadena[50]);
#endif // VALIDACIONES_H_INCLUDED
