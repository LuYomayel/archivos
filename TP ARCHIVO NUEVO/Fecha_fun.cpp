#include <iostream>
#include <cstdlib>
#include "fecha.h"
#include <cstring>
#include "validaciones.h"
using namespace std;

Fecha cargarFecha(){
    Fecha reg;
    cout << "Fecha de nacimiento (dd/mm/aaaa): " << endl;
    cout << "Dia: ";
    int dia;
    cin >> dia;
    while (dia >31 || dia <=0){
        cout << "El dia debe ser mayor a 0 y menor a 31"<< endl;
        cout << "> ";
        cin >> dia;
    }
    reg.dia=dia;
    int mes;

if (dia==31){
    cout << "Mes: ";
    cin >> mes;
    while(mes== 2 || mes==3 || mes==5 || mes ==9 || mes==11 || mes <0 || mes >12){
        cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
        cin >> mes;
    }


}
if (dia == 30){
    cout << "Mes: ";
    cin >> mes;
    while(mes==2 || mes <0 || mes >12){
        cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
        cin >> mes;
    }

}
if (dia>0 && dia<30){
    cout << "Mes: ";
    cin >> mes;
    while (mes <=0 || mes >12){
       cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
    cin >> mes;
    }
}
reg.mes=mes;

int anio;
if (dia==29 && mes==2){
    cout << "Anio: ";
    cin >> anio;
    while (bisiesto(anio)==false){
        cout << "Debe ingresar un anio bisiesto. " << endl << "Anio: ";
        cin >> anio;
    }

}
else{
    cout << "Anio : ";
    cin >> anio;
    while (anio<1910){
        cout << "Debe ingresar un anio mayor a 1910. " << endl << "Anio: ";
        cin >> anio;
    }
}

    reg.anio=anio;
    return reg;
}

void mostrarFecha(Fecha reg){
    cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

Fecha fechaEntrenamiento(){
    Fecha reg;
    cout << "Fecha de entrenamiento (dd/mm/aaaa): " << endl;
    cout << "Dia: ";
    int dia;
    cin >> dia;
    while (dia >31 || dia <=0){
        cout << "El dia debe ser mayor a 0 y menor a 31"<< endl;
        cout << "> ";
        cin >> dia;
    }
    reg.dia=dia;
    int mes;

if (dia==31){
    cout << "Mes: ";
    cin >> mes;
    while(mes== 2 || mes==3 || mes==5 || mes ==9 || mes==11 || mes <0 || mes >12){
        cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
        cin >> mes;
    }


}
if (dia == 30){
    cout << "Mes: ";
    cin >> mes;
    while(mes==2 || mes <0 || mes >12){
        cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
        cin >> mes;
    }

}
if (dia>0 && dia<30){
    cout << "Mes: ";
    cin >> mes;
    while (mes <=0 || mes >12){
       cout << "Vuelve a ingresar el mes, fecha inexistente."<< endl << "Mes: ";
    cin >> mes;
    }
}
reg.mes=mes;

int anio;
if (dia==29 && mes==2){
    cout << "Anio: ";
    cin >> anio;
    while (bisiesto(anio)==false){
        cout << "Debe ingresar un anio bisiesto. " << endl << "Anio: ";
        cin >> anio;
    }

}
else{
    cout << "Anio : ";
    cin >> anio;
    while (anio<1910){
        cout << "Debe ingresar un anio mayor a 1910. " << endl << "Anio: ";
        cin >> anio;
    }
}

    reg.anio=anio;
    return reg;
}
