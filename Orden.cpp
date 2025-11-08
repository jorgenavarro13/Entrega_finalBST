
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
using namespace std;

Orden::Orden(){};
Orden::~Orden(){};

Orden::Orden(char *mes,char* dia, char* hora,char *minuto, char*segundo, char* restaurante, char* platillo,char* precio){
    this->mes=string(mes);
    this->dia=atoi(dia);
    this->hora=atoi(hora);
    this->minuto=atoi(minuto);
    this->segundo=atoi(segundo);
    string temp(restaurante);
    while (!temp.empty() && (temp.back() == 'O' || temp.back() == ' ')) {
        temp.pop_back();
    }
    this->restaurante = temp;

    string tempPlatillo(platillo);
    // Eliminar 'O' y espacio del inicio si existen
    if (!tempPlatillo.empty() && tempPlatillo[0] == 'O' && tempPlatillo[1] == ' ') {
        tempPlatillo = tempPlatillo.substr(2);
    }
    this->platillo = tempPlatillo;
    
    this->precio=atoi(precio);

    this->mesInt=mes_to_int(this->mes);
    //Calculo de fecha en segundos
    this->fechaSegundos= this->segundo + (this->minuto * 60) + (this->hora * 3600) + (this->dia * 86400) + (this->mesInt * 2592000);    
}

string Orden::getMes(){return this->mes;}
int Orden::getDia(){return this->dia;}
int Orden::getHora(){return this->hora;}
int Orden::getMinuto(){return this->minuto;}
int Orden::getSegundo(){return this->segundo;}
string Orden::getRestaurante(){return this->restaurante;}
string Orden::getPlatillo(){return this->platillo;}
int Orden::getPrecio(){return this->precio;}


//Getters especializados
int Orden::getMesInt(){return this->mesInt;}
int Orden::getFechaSegundos(){return this->fechaSegundos; }

int Orden::mes_to_int(string mesV){ 
            int mes_to_int=0;
            if((mesV[0]=='E' || mesV[0]=='e')) mes_to_int=1;
            if((mesV[0]=='F' || mesV[0]=='f')) mes_to_int=2;
            if((mesV[0]=='M' || mesV[0]=='m') && (mesV[2]=='r')) mes_to_int=3;
            if((mesV[0]=='A' || mesV[0]=='a') && mesV[1]=='b') mes_to_int=4;
            if((mesV[0]=='M' || mesV[0]=='m') && mesV[2]=='y') mes_to_int=5;
            if((mesV[0]=='J' || mesV[0]=='j') && mesV[2]=='n') mes_to_int=6;
            if((mesV[0]=='J' || mesV[0]=='j') && mesV[2]=='l') mes_to_int=7;
            if((mesV[0]=='A' || mesV[0]=='a') && mesV[1]=='g') mes_to_int=8;
            if(mesV[0]=='S' || mesV[0]=='s') mes_to_int=9;
            if(mesV[0]=='O' || mesV[0]=='o') mes_to_int=10;
            if(mesV[0]=='N' || mesV[0]=='n') mes_to_int=11;
            if(mesV[0]=='D' || mesV[0]=='d') mes_to_int=12;
            return mes_to_int;
        }