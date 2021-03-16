#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


struct Fecha{
int dia, mes, anio;
};

void mostrarFecha(Fecha);
Fecha cargarFecha();
Fecha fechaEntrenamiento();
#endif // FECHA_H_INCLUDED
