#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
#include "Back.h"
using namespace std;

int main(){
    Back back;
    Orden ordenes[11000]; //Arreglo estático de ordenes
    back.cargarOrdenes(ordenes);

    back.ordQuickT<Orden>(ordenes,0,9999);
    for(int i=0; i<10; i++){
        cout<<ordenes[i].getMes()<<" "<<ordenes[i].getDia()<<" "<<ordenes[i].getHora()<<":"<<ordenes[i].getMinuto()<<":"<<ordenes[i].getSegundo()<<" R:"<<ordenes[i].getRestaurante()<<" O:"<<ordenes[i].getPlatillo()<<"("<<ordenes[i].getPrecio()<<")"<<endl;
    }

    return 1;
}

