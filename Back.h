#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
#include "Platillo.h"
using namespace std;

class Back{
    public:
        int preguntaMes();

        int preguntaHora();

        int preguntaDia();

        bool preguntaArchivo();

        int buscarInicio(Orden *ordenes, int n, int fechaInicio);

        int buscarFin(Orden *ordenes, int n, int fechaFin); 

        int retornaNumeroLineas();

        void cargarOrdenes(Orden ordenes[],long int n);

        int llenaArregloPlatillos(Orden ordenes[]  ,Platillo *platillos, long int n);

        // Métodos de ordenamiento genéricos con lambda functions
        
        template <class T, class KeyExtractor>
        int particionT(T *arreglo, int inicio, int fin, KeyExtractor getKey) {
            auto pivote = getKey(arreglo[inicio]);
            int i = inicio;
            
            for (int j = inicio + 1; j <= fin; j++) {
                if (getKey(arreglo[j]) <= pivote) {
                    i++;
                    // Intercambio
                    T temp = arreglo[i];
                    arreglo[i] = arreglo[j];
                    arreglo[j] = temp;
                }
            }
            
            // Colocar el pivote en su posición correcta
            T temp = arreglo[i];
            arreglo[i] = arreglo[inicio];
            arreglo[inicio] = temp;
            
            return i;
        }

        template <class T, class KeyExtractor>
        void ordQuickT(T *arreglo, int inicio, int fin, KeyExtractor getKey) {
            if (inicio < fin) {
                int pivote = particionT(arreglo, inicio, fin, getKey);
                ordQuickT(arreglo, inicio, pivote - 1, getKey);
                ordQuickT(arreglo, pivote + 1, fin, getKey);
            }
        }

        // Funciones de ayuda para ordenar específicamente Orden y Platillo
        void ordenarPorFecha(Orden *arreglo, int inicio, int fin) {
            ordQuickT(arreglo, inicio, fin, 
                [](Orden& o) { return o.getFechaSegundos(); });
        }

        void ordenarPorCantidad(Platillo *arreglo, int inicio, int fin) {
            ordQuickT(arreglo, inicio, fin, 
                [](Platillo& p) { return p.getCantidad(); });
        }





};
