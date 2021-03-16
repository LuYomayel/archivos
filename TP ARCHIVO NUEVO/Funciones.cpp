#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "validaciones.h"
#include "fecha.h"
#include "Usuario_fun.h"
#include "rlutil.h"
#include "ui.h"
#include "iomanip"

using namespace std;
Usuario cargarUsuario(){
system("cls");
Usuario reg;
title("Cargar usuario");
gotoxy(1,3);
cout << "ID: ";
int codigo;
cin >> codigo;
if (cantidadUsuarios()!=-1){
while (validacionID(codigo)==false){
delline(3);
        msj("Codigo repetido.", APP_FORECOLOR, APP_ERRORCOLOR);

        gotoxy(1,3);
        cout << "ID: ";
        cin >> codigo;
}
}
reg.id=codigo;

int sw;
cout << "Nombre: ";
cin.ignore();
cin.getline(reg.nombre,50);
sw=validarCadena(reg.nombre);
int c;
c=strlen(reg.nombre);

while (sw==1 || c==0){
    delline(4);

    msj("El nombre no puede contener espacios vacios al principio ni estar vacia",APP_FORECOLOR, APP_ERRORCOLOR);

    gotoxy(1,4);

    cout << "Nombre: ";
    cin.getline(reg.nombre,50);
    sw=validarCadena(reg.nombre);
    c=strlen(reg.nombre);
}


cout << "Apellido: ";
cin.getline(reg.apellido,50);
sw=validarCadena(reg.apellido);
c=strlen(reg.apellido);
while (sw==1 || c==0){
    delline(5);
    msj("El nombre no puede contener espacios vacios al principio ni estar vacia",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,5);
    cout << "Apellido: ";
    cin.getline(reg.apellido,50);
    sw=validarCadena(reg.apellido);
    c=strlen(reg.apellido);
}

int edad;
Fecha aux;
aux=cargarFecha();
edad=calculoEdad(aux);
while(edad<13){
        delline(6);
        delline(7);
        delline(8);
        delline(9);
    msj( "Debe ser mayor de 13 anios: ",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,6);
    aux=cargarFecha();
    edad=calculoEdad(aux);
}
reg.nac=aux;

int altura;
cout << "Altura (cm): ";
cin >> altura;
while(altura<=0){
delline(10);
    msj("La altura no puede ser 0 o negativa",APP_FORECOLOR, APP_ERRORCOLOR);

    gotoxy(1,10);
    cout << "Altura: ";
    cin >> altura;
}
reg.altura=altura;

int peso;
cout << "Peso (kg): ";
cin >> peso;
while(peso<=0){
        delline(11);
    msj("El peso no puede ser 0 o negativo"  ,APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,11);
    cout << "Peso (kg): ";

    cin >> peso;
}
reg.peso=peso;

char perfil;
cout << "Perfil de actividad (A/B/C): ";
cin >> perfil;
bool b=true;

    while (b==true){

            if ( perfil == 'a' || perfil == 'A'){
                b=false;
            }
            if (perfil == 'b' || perfil == 'B'){
                b=false;
            }
            if (perfil == 'c' || perfil == 'C'){
                b=false;
            }
            if (b==true){
    delline(12);
    msj("El perfil de actividad debe ser el caracter 'a' 'b' o 'c'.",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,12);
    cout << "Perfil de actividad: ";
    cin >> perfil;
            }
}
reg.perfilDeActividad =perfil;

int apto;
cout << "Apto medico: ";
cin >> apto;
while(apto <0 || apto >1){
        delline(13);
    msj("El apto medico debe ser igual a 0 o 1",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,13);
    cout<< "Apto medico: " ;

    cin >>apto;
}
reg.aptoMedico=apto;

reg.estado=true;
return reg;

}

bool guardarUsuario(Usuario reg){
bool b;
FILE *p;
p = fopen("Usuarios.dat","ab");
if (p==NULL){
        b=false;
        fclose(p);
    return b;
}
b = fwrite(&reg,sizeof(Usuario),1,p);
fclose(p);
return b;

}

void mostrarUsuario(Usuario reg){
cout << "ID: ";
cout << reg.id << endl;
cout << "Nombre: ";
 cout << reg.nombre << endl;
cout << "Apellido: ";
cout << reg.apellido << endl;
mostrarFecha(reg.nac);
cout << "Altura: ";
cout << reg.altura << endl;
cout << "Perfil de actividad: ";
cout << reg.perfilDeActividad << endl;
cout << "Apto medico: ";
cout  << reg.aptoMedico << endl;
}

/*
void listarUsuarios(Usuario reg){
system ("cls");
title("Listar todos los usuarios");
FILE *p;
p = fopen("Usuarios.dat","rb");
if (p==NULL){
        msj("No se pudo abrir el archivo",APP_FORECOLOR,APP_ERRORCOLOR);
    return ;
}
gotoxy(1,3);
while(fread(&reg,sizeof(Usuario),1,p)!=0){

    if (reg.estado==1){
    mostrarUsuario(reg);
    cout << endl;
        }
}
fclose(p);

}*/

void listarUsuarios(){
    system("cls");
    title("Listado de usuarios");
    gotoxy(1, 5);
    int cant =  cantidadUsuarios();
    if (cant > 0){
        cout << left;

        cout << setw(6) << "ID" << setw(20) << "Apellidos" << setw(20) << "Nombres" << setw(10) << "Altura" << setw(7) << "Peso" << setw(15) << "Perfil de Act."<< setw(15) << "Apto medico" << setw(15) << "Fecha";
        cout << endl << "-------------------------------------------------------------------------------------------------------" << endl;
        for(int i = 0; i<cant; i++){
            Usuario reg = leerUsuario(i);
            cout << setw(6) << reg.id;
            cout << setw(20) << reg.apellido;
            cout << setw(20) << reg.nombre;
            cout << setw(10) << reg.altura;
            cout << setw(7) << reg.peso;
            cout << setw(15) << reg.perfilDeActividad;
            cout << setw(15) << reg.aptoMedico;
            mostrarFecha(reg.nac);
        }
    }
}


int buscarUsuario(int codigo){
int pos=0;
Usuario reg;
FILE *p;

p= fopen("Usuarios.dat", "rb");
if (p==NULL){
        cout << "ERROR"<<endl << "NO SE PUDO ABRIR EL ARCHIVO";
    return -1;
}
while (fread(&reg,sizeof(Usuario),1,p)!=0){
    if (codigo == reg.id){
        fclose(p);
        return pos;
    }
    pos++;
}
fclose(p);
return -1;
}

Usuario leerUsuario(int posicion){
    Usuario reg;
    FILE *p = fopen("Usuarios.dat", "rb");
    if (p == NULL){
        reg.id = 0;
        return reg;
    }
    fseek(p, posicion * sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return reg;
}

void modificarUsuario(){
system ("cls");

title( "Modificar Usuario" );
gotoxy(1,3);
cout << "ID: " ;
int codigo, pos;
cin >> codigo;
pos = buscarUsuario(codigo);
if (pos == -1){
    msj("El usuario no existe",APP_FORECOLOR, APP_ERRORCOLOR);

    return;
}
Usuario reg=leerUsuario(pos);
mostrarUsuario(reg);

if (reg.estado==0){
    msj( "El usuario fue eliminado",APP_FORECOLOR, APP_ERRORCOLOR);

    return;
}

if (pos >= 0){
        system("cls");
        title("Usuario a modificar: ");
int apto;
int sw=0;
char perfil;
int edad;
Fecha aux;
bool b=true;
int c;

    gotoxy(1,3);
    cout << endl << "Que desea cambiar?" << endl;
    cout << "1- Nombre";
    cout << endl;
    cout << "2- Apellido";
    cout << endl;
    cout << "3- Fecha de nacimiento";
    cout << endl;
    cout << "4- Altura";
    cout << endl;
    cout << "5- Peso";
    cout << endl;
    cout << "6- Perfil de Actividad";
    cout << endl;
    cout << "7- Apto Medico";
    cout << endl;
    cout << "0- Volver";
    cout << endl;
    cout << "Ingrese la opcion que desea modificar: ";
    int opc;
    cin >> opc;
    system("cls");
    switch(opc){
case 1:
    title("Modificar usuario");

    gotoxy(1,3);
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(reg.nombre,50);
    sw=validarCadena(reg.nombre);
    c=strlen(reg.nombre);
    while (sw==1 || c==0){
    delline(3);

    msj("El nombre no puede contener espacios vacios al principio.",APP_FORECOLOR, APP_ERRORCOLOR);

    gotoxy(1,3);
    cout << "Nombre: ";
    cin.getline(reg.nombre,50);
    sw=validarCadena(reg.nombre);
    c=strlen(reg.nombre);
}

    break;
case 2:
title("Modificar usuario");
    gotoxy(1,3);
    cout << "Apellido: ";
    cin.ignore();
    cin.getline(reg.apellido,50);
    sw=validarCadena(reg.apellido);
    c=strlen(reg.apellido);
    while (sw==1 || c==0){
        delline(5);
        msj("El apellido no puede contener espacios vacios al principio.",APP_FORECOLOR, APP_ERRORCOLOR);
        gotoxy(1,3);
        cout << "Apellido: ";
        cin.getline(reg.apellido,50);
        sw=validarCadena(reg.apellido);
        c=strlen(reg.apellido);
}

    break;
    case 3:
        title("Modificar usuario");
    gotoxy(1,3);

    aux=cargarFecha();
    edad=calculoEdad(aux);
    while(edad<13){
        delline(3);
        delline(4);
        delline(5);
        delline(6);
    msj( "Debe ser mayor de 13 anios: ",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,3);
    aux=cargarFecha();
    edad=calculoEdad(aux);
}
reg.nac=aux;

    break;
case 4:
    title("Modificar usuario");
    gotoxy(1,3);
    int altura;
    cout << "Altura (cm): ";
    cin >> altura;
    while(altura<=0){
    delline(3);
    msj("La altura no puede ser 0 o negativa",APP_FORECOLOR, APP_ERRORCOLOR);

    gotoxy(1,3);
    cout << "Altura: ";
    cin >> altura;
}
reg.altura=altura;

    break;
    case 5:
        title("Modificar usuario");
        gotoxy(1,3);
        int peso;
    cout << "Peso (kg): ";
    cin >> peso;
while(peso<=0){
        delline(3);
    msj("El peso no puede ser 0 o negativo"  ,APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,3);;
    cout << "Peso (kg): ";

    cin >> peso;
}
reg.peso=peso;

    break;
case 6:
    title("Modificar usuario");
    gotoxy(1,3);

cout << "Perfil de actividad (A/B/C): ";
cin >> perfil;


    while (b==true){

            if ( perfil == 'a' || perfil == 'A'){
                b=false;
            }
            if (perfil == 'b' || perfil == 'B'){
                b=false;
            }
            if (perfil == 'c' || perfil == 'C'){
                b=false;
            }
            if (b==true){
    delline(3);
    msj("El perfil de actividad debe ser el caracter 'a' 'b' o 'c'.",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,3);
    cout << "Perfil de actividad: ";
    cin >> perfil;
            }
}
reg.perfilDeActividad =perfil;

    break;
case 7:
    title("Modificar usuario");
    gotoxy(1,3);

cout << "Apto medico: ";
cin >> apto;
while(apto <0 || apto >1){
        delline(3);
    msj("El apto medico debe ser igual a 0 o 1",APP_FORECOLOR, APP_ERRORCOLOR);
    gotoxy(1,3);
    cout<< "Apto medico: " ;

    cin >>apto;
}
reg.aptoMedico=apto;

    break;

case 0:
    return;
    break;
    }
    if (guardarUsuario(reg,pos)==true){
        msj( "Usuario guardado correctamente",APP_FORECOLOR,APP_OKCOLOR);
    }
    else{
        msj("No se guardo el usuario.",APP_FORECOLOR,APP_OKCOLOR);
    }
}
system("pause");
}

bool guardarUsuario(Usuario reg, int pos){
bool grabo;
    FILE *f;
    f = fopen("Usuarios.dat", "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Usuario), SEEK_SET);
    grabo = fwrite(&reg, sizeof(Usuario), 1, f);
    fclose(f);
    return grabo;
}

void mostrarUsuarioxID(){
system("cls");
title("Mostrar usuario x ID");
gotoxy(1,3);
cout << "ID: ";
int id, pos;
cin >> id;
pos = buscarUsuario(id);
if (pos == -1){
    msj("El usuario no existe",APP_FORECOLOR,APP_ERRORCOLOR);

    return;
}

Usuario reg=leerUsuario(pos);
if (reg.estado==1){
system("cls");
title("Mostrar usuario x ID");
gotoxy(1,3);
mostrarUsuario(reg);
system("pause");
}
else{
    msj("El usuario fue eliminado",APP_FORECOLOR,APP_ERRORCOLOR);

    return;
}


}

void eliminarUsuario(){
system("cls");
title("Eliminar usuario");
gotoxy(1,3);
cout << "ID: ";
int id, pos=-1;
cin >> id;

pos = buscarUsuario(id);




Usuario reg=leerUsuario(pos);
if (reg.estado==0 ){
    system("cls");
    title("Eliminar usuario");
    msj("El usuario fue eliminado",APP_FORECOLOR,APP_ERRORCOLOR);

    return;
}
if (pos == -1){
    system("cls");
    title("Eliminar usuario");
    msj("El usuario no existe",APP_FORECOLOR,APP_ERRORCOLOR);

    return;
}
system("cls");
title("Eliminar usuario");
gotoxy(1,3);

mostrarUsuario(reg);
reg.estado=0;
guardarUsuario(reg,pos);
if (reg.estado==0){

    msj( "Usuario eliminado correctamente", APP_FORECOLOR,APP_OKCOLOR);

}

}

int cantidadUsuarios(){
FILE *p;
p=fopen("Usuarios.dat","rb");
if (p==NULL){
    return -1;
}
int bytes, cant;
fseek(p,0,SEEK_END);
bytes=ftell(p);
fclose (p);
cant= bytes / sizeof(Usuario);
return cant;
}
/*void verificarEstado(Usuario reg){
system ("cls");
FILE *p;
p = fopen("Usuarios.dat","rb");
if (p==NULL){
        cout << "ERROR"<<endl << "NO SE PUDO ABRIR EL ARCHIVO";
    return ;
}
while(fread(&reg,sizeof(Usuario),1,p)!=0){
        if (reg.estado==1)
}
fclose(p);

}*/
