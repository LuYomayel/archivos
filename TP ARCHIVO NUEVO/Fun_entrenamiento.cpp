#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#include "fecha.h"
#include "validaciones.h"
#include "Fun_entrenamiento.h"
#include "Usuario_fun.h"
#include "rlutil.h"
#include "ui.h"
#include "iomanip"

Entrenamiento cargarEntrenamiento(){
Entrenamiento reg;
system("cls");
title( "Cargar entrenamiento");
gotoxy(1,3);
int cant = cantidadEntrenamientos();
cout << "ID " << cant+1 << endl;
reg.id=cant+1;

cout << "IDusuario: ";
int id;
cin >> id;
while(buscarUsuario(id)==-1){
    cout << "Este ID de usuario no existe, vuelva a ingresar otro ID: ";
    cin >> id;
}
reg.idUsuario=id;

Fecha aux=fechaEntrenamiento();

while(restaFechas(aux)==false){
        cout << "La fecha no puede ser mayor a la fecha actual. Vuelva a ingresarla." << endl;
aux=fechaEntrenamiento();
restaFechas(aux);
}
reg.nac=aux;

int numero;
cout << "Actividad: ";
cin >> numero;
int pos=buscarUsuario(id);
bool  b=true;

while(b){


    if (numero ==1 || numero ==2 || numero ==3){
        b=false;
    }
    if (numero==4 || numero ==5){

             if(leerUsuario(pos).aptoMedico==1){
               b=false;
             }
             else{
                cout << "El usuario no puede realizar esa actividad por no tener el apto fisico."<< endl;

             }
        }
        if(b){
    cout << "Actividad: ";
    cin >> numero;
        }
}
reg.actividad=numero;

int calorias;

cout << "Calorias: ";
cin >> calorias;
while(calorias<0){
    cout << "Calorias: ";
    cin >> calorias;
}
reg.calorias=calorias;

int tiempo;
cout << "Tiempo en minutos: ";
cin >> tiempo;
while (tiempo <0){
    cout << "Tiempo en minutos: ";
cin >> tiempo;
}
reg.tiempo=tiempo;

return reg;
}

bool guardarEntrenamiento(Entrenamiento reg){
FILE *p;
bool b;
p=fopen("Entrenamientos.dat","ab");

if (p==NULL){
    return false;
}

b=fwrite(&reg,sizeof(Entrenamiento),1,p);
fclose(p);
return b;
}

int cantidadEntrenamientos(){

FILE *p;
p=fopen("Entrenamientos.dat","rb");
if (p==NULL){
    return 0;
}
int bytes, cant;
fseek(p,0,SEEK_END);
bytes=ftell(p);
fclose (p);
cant= bytes / sizeof(Entrenamiento);
return cant;
}

void modificarEntrenamiento(){

system ("cls");

title("Modificar Entrenamiento");
gotoxy(1,3);
cout << "ID: " ;
int codigo, pos;
cin >> codigo;
pos = buscarID(codigo);
if (pos == -1){
    msj("El entrenamiento no existe",APP_FORECOLOR,APP_ERRORCOLOR);

    return;
}
Entrenamiento reg=leerEntrenamiento(pos);
cout << "Entrenamiento a modificar: " << endl;
mostrarEntrenamiento(reg);



if (pos >= 0){
    cout << endl;


    cout << endl << "Que desea cambiar?" << endl;
    cout << "1) Calorias";
    cout << endl;
    cout << "2) Minutos";
    cout << endl << "Elija una opcion: ";
    int opc;
    cin >> opc;
    if (opc==1){

    cout << "Calorias: ";
    cin >> reg.calorias;
    if (guardarEntrenamiento(reg,pos)==true){
        msj("Entrenamiento guardado correctamente",APP_FORECOLOR,APP_OKCOLOR);
    }
    else{
        msj("No se guardo el entrenamiento.",APP_FORECOLOR,APP_ERRORCOLOR);
    }
    }
    if (opc==2){
    cout << "Tiempo: ";
    cin >> reg.tiempo;
    if (guardarEntrenamiento(reg,pos)==true){
        msj("Entrenamiento guardado correctamente",APP_FORECOLOR,APP_OKCOLOR);
    }
    else{
        msj("No se guardo el entrenamiento.",APP_FORECOLOR,APP_ERRORCOLOR);
    }
    }


}

}


int buscarID(int codigo){
int pos=0;
Entrenamiento reg;
FILE *p;

p= fopen("Entrenamientos.dat", "rb");
if (p==NULL){
        cout << "ERROR"<<endl << "NO SE PUDO ABRIR EL ARCHIVO";
    return -1;
}
while (fread(&reg,sizeof(Entrenamiento),1,p)!=0){
    if (codigo == reg.id){
        fclose(p);
        return pos;
    }
    pos++;
}
fclose(p);
return -1;
}
void mostrarEntrenamiento(Entrenamiento reg){
    cout << endl;
    cout << "ID: " << reg.id;
    cout << endl;
    cout << "IDusuario: " << reg.idUsuario;
    cout << endl;
    mostrarFecha(reg.nac);

    cout << "Actividad: " << reg.actividad;
    cout << endl;
    cout << "Calorias: " << reg.calorias;
    cout << endl;
    cout << "Tiempo en minutos: " << reg.tiempo;
    cout << endl;


}

void mostrarEntrenamientoxID(){
    system("cls");
    title("Mostrar entrenamiento x ID");
    gotoxy(1,3);
    cout << "ID: ";
    int codigo;
    cin  >> codigo;

    int pos = buscarID(codigo);
    if (pos==-1){
        msj( "El ID no existe",APP_FORECOLOR,APP_ERRORCOLOR);
        return;
    }
    Entrenamiento reg;
    FILE *p;
    p = fopen("Entrenamientos.dat","rb");
    fseek(p,pos*sizeof(Entrenamiento),SEEK_SET);
    fread(&reg,sizeof(Entrenamiento),1,p);
    mostrarEntrenamiento(reg);
    fclose(p);

}

Entrenamiento leerEntrenamiento(int codigo){
    Entrenamiento reg;
    FILE *p = fopen("Entrenamientos.dat", "rb");
    if (p == NULL){
        reg.id = 0;
        return reg;
    }
    fseek(p, codigo * sizeof(Entrenamiento), SEEK_SET);
    fread(&reg, sizeof(Entrenamiento), 1, p);
    fclose(p);
    return reg;
}

bool guardarEntrenamiento(Entrenamiento reg, int pos){
bool grabo;
    FILE *f;
    f = fopen("Entrenamientos.dat", "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Entrenamiento), SEEK_SET);
    grabo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return grabo;
}

void mostrarEntrenamientoxIDusuario(){
    system("cls");
    title("Mostrar entrenamiento x IDusuario");
    gotoxy(1,3);
int codigo;
cout << "IDusuario: ";
cin >> codigo;

int pos=buscarUsuario(codigo);
if (pos==-1){
    msj("El usuario no existe. ",APP_FORECOLOR,APP_ERRORCOLOR);
    return;
}
Entrenamiento reg;
FILE *p;
p=fopen("Entrenamientos.dat","rb");
while(fread(&reg,sizeof(Entrenamiento),1,p)!=0){
    if(reg.idUsuario==codigo){
        mostrarEntrenamiento(reg);
    }
}
fclose(p);

}
/*
void listarEntrenamientos(){
    Entrenamiento reg;
    FILE *p;
    system("cls");
    title("Listar todos los entrenamientos");
    gotoxy(1,3);
    p=fopen("Entrenamientos.dat","rb");
    while(fread(&reg,sizeof(Entrenamiento),1,p)!=0){

            mostrarEntrenamiento(reg);

    }
    fclose(p);
}*/

void listarEntrenamientos(){
    system("cls");
    title("Listado de entrenamientos");
    gotoxy(1, 5);
    int cant =  cantidadEntrenamientos();
    if (cant > 0){
        cout << left;

        cout << setw(6) << "ID" << setw(11) << "IDusuario" << setw(11) << "Actividad" << setw(10) << "Calorias" << setw(10) << "Tiempo" << setw(15) << "Fecha";
        cout << endl << "------------------------------------------------------------" << endl;
        for(int i = 0; i<cant; i++){
            Entrenamiento reg = leerEntrenamiento(i);
            cout << setw(6) << reg.id;
            cout << setw(11) << reg.idUsuario;
            cout << setw(11) << reg.actividad;
            cout << setw(10) << reg.calorias;
            cout << setw(10) << reg.tiempo;
            mostrarFecha(reg.nac);
        }
    }
}


