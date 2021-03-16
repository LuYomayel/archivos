#ifndef USUARIO_FUN_H_INCLUDED
#define USUARIO_FUN_H_INCLUDED
#include "fecha.h"

struct Usuario{

int id;
char nombre[50];
char apellido[50];
Fecha nac;
float altura;
float peso;
char perfilDeActividad;
bool aptoMedico;
bool estado;

};

Usuario cargarUsuario();
bool guardarUsuario(Usuario reg);
void listarUsuarios();
void mostrarUsuario(Usuario reg);
void modificarUsuario();
int buscarUsuario(int codigo);
Usuario leerUsuario(int codigo);
bool guardarUsuario(Usuario reg, int );
void mostrarUsuarioxID();
void eliminarUsuario();
int cantidadUsuarios();
//void verificarEstado(Usuario reg);




#endif // USUARIO_FUN_H_INCLUDED
