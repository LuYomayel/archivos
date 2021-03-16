#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Usuario_fun.h"
#include "Fun_entrenamiento.h"
using namespace std;
#include "Configuracion.h"
#include "ui.h"
#include "rlutil.h"

///Para cada perfil, indicar el porcentaje de usuarios.


void reporte1(){
    float v[3];
    int i;
    int cant =cantidadUsuarios();
    for (i=0;i<3;i++){
        v[i]=0;
    }

    for (i=0;i<cant;i++){
        Usuario reg=leerUsuario(i);
        if(reg.perfilDeActividad=='a' || reg.perfilDeActividad=='A'){
            v[0]++;

        }
        if(reg.perfilDeActividad=='b' || reg.perfilDeActividad=='B'){
            v[1]++;

        }
        if(reg.perfilDeActividad=='c' || reg.perfilDeActividad=='C'){
            v[2]++;

        }

    }

    for (i=0;i<15;i++){
    delline(i);
    }
    title("Reporte 1");
    gotoxy(1,3);

    cout << "Perfil A: " << (v[0]/cant)*100 << "%" << endl;
    cout << "Perfil B: " << (v[1]/cant)*100 << "%" << endl;
    cout << "Perfil C: " << (v[2]/cant)*100 << "%" << endl;


}


///A partir de un ID de usuario que se ingrese por teclado listar Apellido, Nombres y cantidad de entrenamientos realizados en el año 2020.

void reporte2(){
    system("cls");

    Entrenamiento reg;
    int v[5][3]={};
    int i;
    int pos;
    int cant;
    cant = cantidadEntrenamientos();
    for (i=0;i<cant;i++){
    reg=leerEntrenamiento(i);

    pos=buscarUsuario(reg.idUsuario);
    Usuario aux=leerUsuario(pos);
    if (reg.actividad==1){
    if ((aux.perfilDeActividad== 'a' || aux.perfilDeActividad =='A')  ){
        v[0][0]++;
    }
    if (aux.perfilDeActividad== 'b' || aux.perfilDeActividad =='B'){
        v[0][1]++;
    }
    if (aux.perfilDeActividad== 'C' || aux.perfilDeActividad =='c'){
        v[0][2]++;
    }
    }
    if (reg.actividad==2){
        if ((aux.perfilDeActividad== 'a' || aux.perfilDeActividad =='A')  ){
        v[1][0]++;
    }
    if (aux.perfilDeActividad== 'b' || aux.perfilDeActividad =='B'){
        v[1][1]++;
    }
    if (aux.perfilDeActividad== 'C' || aux.perfilDeActividad =='c'){
        v[1][2]++;
    }
    }
    if (reg.actividad==3){
        if ((aux.perfilDeActividad== 'a' || aux.perfilDeActividad =='A')  ){
        v[2][0]++;
    }
    if (aux.perfilDeActividad== 'b' || aux.perfilDeActividad =='B'){
        v[2][1]++;
    }
    if (aux.perfilDeActividad== 'C' || aux.perfilDeActividad =='c'){
        v[2][2]++;
    }
    }
    if (reg.actividad==4){
        if ((aux.perfilDeActividad== 'a' || aux.perfilDeActividad =='A') ){
        v[3][0]++;
    }
    if (aux.perfilDeActividad== 'b' || aux.perfilDeActividad =='B'){
        v[3][1]++;
    }
    if (aux.perfilDeActividad== 'C' || aux.perfilDeActividad =='c'){
        v[3][2]++;
    }
    }
    if (reg.actividad==5){
        if ((aux.perfilDeActividad== 'a' || aux.perfilDeActividad =='A')  ){
        v[4][0]++;
    }
    if (aux.perfilDeActividad== 'b' || aux.perfilDeActividad =='B'){
        v[4][1]++;
    }
    if (aux.perfilDeActividad== 'C' || aux.perfilDeActividad =='c'){
        v[4][2]++;
    }
    }
    }
    system("cls");
    title("Reporte 2");
    gotoxy(1,3);
    int j;
    cout << "\tA\tB\tC"<<endl;
    for (i=0;i<5;i++){
            cout << i+1 << "\t";
            for (j=0;j<3;j++){
            cout << v[i][j] << "\t";
            }
            cout << endl;

    }
}

///Aclaracion: claramente confio en que el 2do reporte se puede hacer de manera mas optima (sin tantos if) pero la verdad que me puse muy nervioso y no se me ocurre otra forma pero parece que asi funciona.
