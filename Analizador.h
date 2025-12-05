#pragma once
#include <iostream>
#include <string>
#include "Orden.h"

using namespace std;

class Analizador {
public:
    Analizador();
    ~Analizador();

    // Esta función recibe todas las ordenes, cuántas son, y qué platillo buscas.
    // Devuelve el nombre del restaurante ganador.
    string encontrarMejorRestaurante(Orden ordenes[], long int n, string platilloBuscado);
};