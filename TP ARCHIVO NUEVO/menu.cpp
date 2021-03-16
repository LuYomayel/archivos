#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#include "menu.h"
#include <cstdlib>
#include "fecha.h"
#include "Usuario_fun.h"
#include "validaciones.h"
#include "Fun_entrenamiento.h"
#include "ui.h"
#include "rlutil.h"
#include "Configuracion.h"
#include "Reportes.h"

void menuPrincipal(){
    while(true){

            system("cls");
    title("Menu principal");
    gotoxy(1,3);

    cout << "1- Usuarios"<< endl;
    cout << "2- Entrenamientos"<< endl;
    cout << "3- Reportes"<< endl;
    cout << "4- Configuracion"<< endl;
    cout << endl;
    cout << "0- Salir del programa" << endl << endl;
    cout << "Elija una opcion: ";
    int opc;
    cin >> opc;



        switch(opc){
            case 1:
                menuUsuarios();
            break;
            case 2:
                menuEntrenamientos();

            break;
            case 3:
                menuReportes();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                return;
            break;
        }
    }
}

void menuUsuarios(){
while(true){
system ("cls");
            title( "Menu usuarios" );
            gotoxy(1,3);

            cout << "1- Nuevo usuario " << endl;
            cout << "2- Modificar usuario " << endl;
            cout << "3- Listar usuario por ID" << endl;
            cout << "4- Listar todos los usuarios " << endl;
            cout << "5- Eliminar usuario " << endl<<endl;
            cout << "0- Volver al menu principal"<< endl;

            cout << endl << "Elija una opcion: ";
            int opc;
            cin >> opc;


        switch(opc){
            case 1:
                Usuario reg;
                reg = cargarUsuario();
                if (guardarUsuario(reg)){
                    msj( "Usuario registrado.", APP_FORECOLOR, APP_OKCOLOR);
                }
                else{
                    msj( "No se pudo registrar el usuario.", APP_FORECOLOR,APP_ERRORCOLOR);
                }
            break;
            case 2:
                modificarUsuario();
            break;
            case 3:
                mostrarUsuarioxID();
            break;
            case 4:
               listarUsuarios();
               system("pause");
            break;
            case 5:
                eliminarUsuario();
                break;

            case 0:
                return;
            break;
        }


    }
}

void menuEntrenamientos(){
while(true){
system ("cls");
            title("Menu entrenamientos");
            gotoxy(1,3);
            cout << "1- Nuevo entrenamiento " << endl;
            cout << "2- Modificar entrenamiento " << endl;
            cout << "3- Listar entrenamiento por ID" << endl;
            cout << "4- Listar entrenamiento por IDusuario " << endl;
            cout << "5- Listar todos los entrenamientos " << endl<<endl;
            cout << "0- Volver al menu principal"<< endl;

            cout << endl << "Elija una opcion: ";
            int opc;
            cin >> opc;


        switch(opc){
            case 1:
                Entrenamiento reg;
                reg = cargarEntrenamiento();
                if (guardarEntrenamiento(reg)){
                    msj( "Entrenamiento guardado.",APP_FORECOLOR, APP_OKCOLOR);
                }
                else{
                    msj("No se pudo registrar el entrenamiento.",APP_FORECOLOR, APP_ERRORCOLOR);
                }
            break;
            case 2:
                modificarEntrenamiento();
            break;
            case 3:
                mostrarEntrenamientoxID();
                system("pause");
            break;
            case 4:
               mostrarEntrenamientoxIDusuario();

            break;
            case 5:
                listarEntrenamientos();
                system("pause");
                break;

            case 0:

                return;
            break;
        }


    }
}

void menuConfiguracion(){

    while(true){
    system ("cls");
            title("Menu configuracion");
            gotoxy(1,3);
            cout << "1- Realizar copia de seguridad " << endl;
            cout << "2- Restaurar copia de seguridad" << endl << endl;

            cout << "0- Volver al menu principal"<< endl;

            cout << endl << "Elija una opcion: ";
            int opc;
            cin >> opc;


        switch(opc){
            case 1:
                if(backup()){
                    msj("Copia de seguridad realizada correctamente.",APP_FORECOLOR,APP_OKCOLOR);
                }
                else{
                    msj("Error al realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
                }
            break;
            case 2:
                if(restauracionBKP()){
                    msj("Copia de seguridad realizada correctamente.",APP_FORECOLOR,APP_OKCOLOR);
                }
                else{
                    msj("Error al realizar la copia de seguridad.",APP_FORECOLOR,APP_ERRORCOLOR);
                }
            break;
            case 0:
                return;
            break;
        }


    }
}

void menuReportes(){
    while(true){
    system ("cls");
            title("Menu reportes");
            gotoxy(1,3);
            cout << "1- Reporte 1 " << endl;
            cout << "2- Reporte 2" << endl << endl;

            cout << "0- Volver al menu principal"<< endl;

            cout << endl << "Elija una opcion: ";
            int opc;
            cin >> opc;


        switch(opc){
            case 1:
                reporte1();
                system("pause");
            break;
            case 2:
    reporte2();
    system("pause");
            break;
            case 0:
                return;
            break;
        }


    }
}
