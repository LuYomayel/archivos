#ifndef FUN_ENTRENAMIENTO_H_INCLUDED
#define FUN_ENTRENAMIENTO_H_INCLUDED
#include "fecha.h"

struct Entrenamiento{
int id;
int idUsuario;
Fecha nac;
int actividad;
float calorias;
int tiempo;
};

Entrenamiento cargarEntrenamiento();
bool guardarEntrenamiento(Entrenamiento);
void modificarEntrenamiento();

void mostrarEntrenamiento(Entrenamiento);
void mostrarEntrenamientoxID();
void mostrarEntrenamientoxIDusuario();
void listarEntrenamientos();

int cantidadEntrenamientos();
int buscarID(int codigo);



Entrenamiento leerEntrenamiento(int codigo);
bool guardarEntrenamiento(Entrenamiento, int);
bool buscarIDusuario();


#endif // FUN_ENTRENAMIENTO_H_INCLUDED
