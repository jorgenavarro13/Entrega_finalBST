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
#include "LinkedPlatillos.h"
#include "TreeNodeP.h"
#include "BSTP.h"
//Jorge Arturo Montiel Navarro A01278612
using namespace std;

int main(){
    //PRIMERA ENTREGA FINAL BST
    Back back;
    Orden ordenes[11000]; //Arreglo estático de ordenes
    long int n=back.retornaNumeroLineas();

    back.cargarOrdenes(ordenes, n);
    back.ordenarPorFecha(ordenes,0,n-1); //Ordenamos con quick sort, declarando el TAD a utilizar para su compilación

    //Las funcionalidades de la primera entrega se omitieron, si se desea acceder a estas se puede consultar
    //el código de la primera entrega en https://www.onlinegdb.com/mBqPakq5T


    //Tercera entrega final BST
    cout<<"\n-------------------TERCERA ENTREGA FINAL BST----------------------------\n";
    
    
    //SEGUNDA ENTREGA FINAL BST
  
    //Creamos un arreglo dinámico temporal de Nuestros platillos, para eficientar el uso de memoria
    Platillo * platillos=new Platillo[n/10];
    int capacidad=back.llenaArregloPlatillos(ordenes, platillos, n);
    back.ordenarPorCantidad(platillos,0,capacidad-1); //Ordenamos con quick sort, declarando el TAD a utilizar para su compilación

    //Rellenamos la linked list con los platillos ordenados
    LinkedPlatillos lplatillos(platillos[0]);
    lplatillos.llenamosLinkedList(platillos,capacidad);
    cout<<"\n-------------------ANTES DE ELIMINAR DUPLICADOS----------------------------\n";
    lplatillos.ImprimePlatillos();
    lplatillos.EliminaDuplicados();//Eliminamos duplicados y agrupamos los nombres de los platillos
    cout<<"\n-------------------DESPUES DE ELIMINAR DUPLICADOS Y AGRUPAR----------------------------\n";
    lplatillos.ImprimePlatillos();
    int arrSize=lplatillos.longitudLinkL();

    NodeLPlatillo * node=lplatillos.returnHead();

    //Construimos el árbol balanceado
    BSTP ArbolBinario;
    ArbolBinario.sortedListToBST(node);//Después de esta línea, el árbol está construido, y además la linkedList se degenera


    //Imprimimos los recorridos Inorden y Postorden
    int * arregloInorden = new int[arrSize];
    int index=0;
    ArbolBinario.llenaArreglo(ArbolBinario.cabeza, arregloInorden, index);
    
    int * arregloPostorden = new int[arrSize];
    index = 0;
    ArbolBinario.llenaArregloPostorden(ArbolBinario.cabeza, arregloPostorden, index);


    cout<<arrSize<<endl; //¿Capacidad final del arreglo de platillos?
    cout<<"Tamano declarado: "<<arrSize<<endl;




    cout<<"\n-------------------INORDEN----------------------------\n[";
    ArbolBinario.Inorden(ArbolBinario.cabeza);
    cout<<"]";
    //Generamos un arreglo para almacenar los platillos ordenados por cantidad en postorden

    Platillo *postordenPlatillos = new Platillo[capacidad];

    cout<<"\n-------------------POSTORDEN----------------------------\n[";
    ArbolBinario.Postorden(ArbolBinario.cabeza);
    cout<<"]";

    cout<<"\n-------------------IMPRIMIR ARBOL----------------------------\n";
    ArbolBinario.imprimirArbol(ArbolBinario.cabeza);

    //Liberamos memoria
    delete [] arregloInorden;
    delete [] arregloPostorden;
    delete[] platillos;


    //------------FUNCIONALIDADES OCULTAS-----------------


    //Funcionalidad oculta
    //ArbolBinario.imprimirArbol(ArbolBinario.cabeza,0,6);
    //Impresion de platillos ordenados y sin duplicados
    /*for(int i=0; i<capacidad; i++){
        cout<<platillos[i].getPlatillo()<<" :"<<platillos[i].getCantidad()<<endl;
    }
    */
    
    /*

    Impresion de todas las ordenes cargadas
    for(int i=0; i<n; i++){
        cout<<ordenes[i].getMes()<<" "<<ordenes[i].getDia()<<" "<<ordenes[i].getHora()<<":"<<ordenes[i].getMinuto()<<":"<<ordenes[i].getSegundo()<<" R:"<<ordenes[i].getRestaurante()<<" O:"<<ordenes[i].getPlatillo()<<"("<<ordenes[i].getPrecio()<<")"<<endl;
    }*/
    return 1;
}

