#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
using namespace std;


class Orden{
    public:
        string mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
        string restaurante;
        string platillo;
        int precio;
        
        int mesInt;
        int fechaSegundos;


        Orden();
        ~Orden();

        //Constructor especializado
        Orden(char *mes,char* dia, char* hora,char *minuto, char*segundo, char* restaurante, char* platillo,char* precio);


        //Getters
        string getMes();
        int getDia();
        int getHora();
        int getMinuto();
        int getSegundo();
        string getRestaurante();
        string getPlatillo();
        int getPrecio();

        //Getters especializados
        int getMesInt();
        int getFechaSegundos();

        //Especializados
        int mes_to_int(string mesV);
};