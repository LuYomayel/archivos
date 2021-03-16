#include <iostream>
#include <cstdlib>
#include "Usuario_fun.h"
#include <cstring>
using namespace std;
#include <cstdio>
#include <ctype.h>
#include <conio.h>

#include "fecha.h"

bool validacionID(int id){
    Usuario reg;

    bool validacion=false;
FILE *p;
p = fopen("Usuarios.dat","rb");
if(p==NULL){
        cout << "No se pudo abrir el archivo" << endl;
}
if (id<0) return false;
while(fread(&reg, sizeof(Usuario),1,p)!=0){
    if (id==reg.id){
        return false;
    }
    else{
        validacion= true;
    }
}
fclose(p);
return validacion;
}

bool bisiesto(int anio){
int i;
for (i=1904;i<3000;i=i+4){
    if (anio==i){
        return true;
    }
}
}

bool verificoApto(int pos){
    Usuario reg;
FILE *p= fopen("Usuarios.dat", "rb");
if(p==NULL){
    return false;
}
fseek(p,sizeof(Usuario)*pos,SEEK_SET);
fread(&reg,sizeof(Usuario),1,p);

fclose(p);


}

int validarCadena(char cadena[]){
int i=0, j, sw=0;
j = strlen(cadena);
if (cadena[0]== ' '){
    sw=1;
}
return sw;
}
