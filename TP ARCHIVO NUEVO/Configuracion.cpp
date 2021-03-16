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

/// pin de confirmacion: 2409

bool backup(){
FILE *p,*pb;
Usuario reg;
Entrenamiento aux;
system("cls");
title("Copia de seguridad");
gotoxy(1,3);
cout << "Si desea volver atras ingrese 0"<<endl;
cout << "Si desea realizar la copia de seguridad ingrese el pin." << endl;
cout << "Ingrese pin de confirmacion: ";
int pin;
cin >>  pin;
while (!(pin == 2409 || pin == 0)){
    delline(5);
    msj("Pin incorrecto, vuelva a intentarlo",APP_FORECOLOR,APP_ERRORCOLOR);
    gotoxy(1,5);
    cout << "> ";
    cin >>pin;
}

if (pin==0){
    return false;
}
if (pin==2409){
    p=fopen("Usuarios.dat","rb");
    if (p==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    pb=fopen("Usuarios.bkp","wb");
    if (pb==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    while(fread(&reg,sizeof(Usuario),1,p)==1){
        if(fwrite(&reg,sizeof(Usuario),1,pb)==0){
            msj("No se pudo realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
            return false;
        }
    }
    fclose(p);
    fclose(pb);
    p=fopen("Entrenamientos.dat","rb");
    if (p==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    pb=fopen("Entrenamientos.bkp","wb");
    if (pb==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    while(fread(&aux,sizeof(Entrenamiento),1,p)==1){
        if(fwrite(&aux,sizeof(Entrenamiento),1,pb)==0){
            msj("No se pudo realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
            return false;
        }
    }
    fclose(p);
    fclose(pb);
}
return true;
}

bool restauracionBKP(){
FILE *p,*pb;
Usuario reg;
Entrenamiento aux;
system("cls");
title("Restaurar copia de seguridad");
gotoxy(1,3);
cout << "Si desea volver atras ingrese 0"<<endl;
cout << "Si desea restaurar la copia de seguridad ingrese el pin." << endl;
cout << "Ingrese pin de confirmacion: ";
int pin;
cin >>  pin;
while (!(pin == 2409 || pin == 0)){
    delline(5);
    msj("Pin incorrecto, vuelva a intentarlo",APP_FORECOLOR,APP_ERRORCOLOR);

    gotoxy(1,5);
    cout << "> ";
    cin >>pin;
}
if (pin==0){
    return false;
}
if (pin==2409){
    p=fopen("Usuarios.bkp","rb");
    if (p==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    pb=fopen("Usuarios.dat","wb");
    if (pb==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    while(fread(&reg,sizeof(Usuario),1,p)==1){
        if(fwrite(&reg,sizeof(Usuario),1,pb)==0){
            msj("No se pudo realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
            return false;
        }
    }
    fclose(p);
    fclose(pb);
    p=fopen("Entrenamientos.bkp","rb");
    if (p==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    pb=fopen("Entrenamientos.dat","wb");
    if (pb==NULL){
        msj("El archivo no se pudo abrir", APP_FORECOLOR, APP_ERRORCOLOR);
        return false;
    }
    while(fread(&aux,sizeof(Entrenamiento),1,p)==1){
        if(fwrite(&aux,sizeof(Entrenamiento),1,pb)==0){
            msj("No se pudo realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
            return false;
        }
    }
    fclose(p);
    fclose(pb);
}
return true;
}
