#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
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

        void cargarOrdenes(Orden ordenes[]);


        //Metodos de ordenamiento->

        template <class T>
        int particionT(T *arreglo,int inicio,int fin){
            int pivote = arreglo[inicio].getFechaSegundos(); //se trabaja con enteros
            int i = inicio;
            for (int j = inicio + 1; j <= fin; j++){
                if (arreglo[j].getFechaSegundos() <= pivote){
                    i++;
                    //Intercambio
                    T temp = arreglo[i];
                    arreglo[i] = arreglo[j];
                    arreglo[j] = temp;
                }
            }
            //Colocar el pivote en su posicion correcta
            T temp = arreglo[i];
            arreglo[i] = arreglo[inicio];
            arreglo[inicio] = temp;
            
            return i; //Indice del pivote
        }

        //Quick Sort
        //Complejidad: Mejor caso O(nlog).      Caso medio:O(nlogn)     Peor caso:O(n^2)
        //Complejidad espacial O(logn)
        //Recibe como parametros el apuntador al arreglo,el indice de inicio y fin
        // Recibe como parámetros: apuntador al arreglo, índice de inicio y fin.
        //Cache friendly 
        template <class T> 
        void ordQuickT(T *arreglo,int inicio, int fin){
            if (inicio < fin){
                int pivote = particionT(arreglo,inicio,fin);
                
                //Ordenar el subarreglo a la izquierda y el de la derecha
                ordQuickT(arreglo,inicio,pivote-1);
                ordQuickT(arreglo,pivote+1,fin);
            }
        }





};
