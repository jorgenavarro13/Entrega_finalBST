#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
#include "Back.h"
#include "Platillo.h"
using namespace std;

int main(){
    Back back;
    Orden ordenes[11000]; //Arreglo estático de ordenes
    long int n=back.retornaNumeroLineas();

    back.cargarOrdenes(ordenes, n);
    back.ordQuickT<Orden>(ordenes,0,n-1); //Ordenamos con quick sort, declarando el TAD a utilizar para su compilación


    //Creamos un arreglo dinámico temporal de Nuestros platillos, para eficientar el uso de memoria
    Platillo * platillos=new Platillo[n/10];
    int capacidad=back.llenaArregloPlatillos(ordenes, platillos, n);

    

    for(int i=0; i<capacidad+3; i++){
        cout<<platillos[i].getPlatillo()<<" :"<<platillos[i].getCantidad()<<endl;
    }

    delete[] platillos;

    

    
    /*

    Falta implementar las impresiones, pero no son indispensables
    for(int i=0; i<n; i++){
        cout<<ordenes[i].getMes()<<" "<<ordenes[i].getDia()<<" "<<ordenes[i].getHora()<<":"<<ordenes[i].getMinuto()<<":"<<ordenes[i].getSegundo()<<" R:"<<ordenes[i].getRestaurante()<<" O:"<<ordenes[i].getPlatillo()<<"("<<ordenes[i].getPrecio()<<")"<<endl;
    }*/
    

    

    return 1;
}

