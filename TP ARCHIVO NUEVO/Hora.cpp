#include <iostream>
#include <cstdlib>
#include "validaciones.h"
#include <cstring>
#include <ctime>
#include <cstdio>
using namespace std;

int calculoEdad(Fecha reg){
    int edad=14;
  time_t tiempo;
  char cad[80];
struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  //printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  //strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
  //printf("\n\n%s", cad);
  int ver1, ver2,ver3;

  ver1=(tmPtr->tm_mon+1)-reg.mes;

  if (ver1  < 0 ){
    edad=((1900+tmPtr->tm_year)-reg.anio)-1;

  }

  ver2=(tmPtr->tm_mday-reg.dia);


if(ver1 >= 0 && ver2>=0){
    edad=((1900+tmPtr->tm_year)-reg.anio);

  }
  if (ver1 >=0 && ver2 <0){
    edad=((1900+tmPtr->tm_year)-reg.anio)-1;
  }
    /*cout << tmPtr->tm_mday-reg.dia;
    cout << endl;
    cout << (tmPtr->tm_mon+1)-reg.mes;
    cout << endl;
    cout << (1900+tmPtr->tm_year)-reg.anio;
    cout << endl;*/

  return edad;
}

bool restaFechas(Fecha reg){

    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);


  int ver1, ver2,ver3;


  ver1=(tmPtr->tm_mday-reg.dia);
  ver2=(tmPtr->tm_mon+1)-reg.mes;
  ver3=(1900+tmPtr->tm_year)-reg.anio;

    if (ver3 <0){
        return false;
    }

  if (ver3==0 && ver2 <=0 && ver1<0){
    return false;
  }
  return true;


}

