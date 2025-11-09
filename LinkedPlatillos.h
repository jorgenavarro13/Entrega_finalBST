#pragma once
#include <iostream>
#include "Platillo.h"
#include <string>
using namespace std;

class NodeLPlatillo{
    public:
        string platillo;
        int cantidad;
        NodeLPlatillo *next;

        NodeLPlatillo():cantidad(0),next(nullptr){};
        ~NodeLPlatillo(){};
        NodeLPlatillo(Platillo platillo){
            this->cantidad=platillo.getCantidad();
            this->platillo=platillo.getPlatillo();
            this->next=nullptr;
        };

        NodeLPlatillo(string p,int n):platillo(p),cantidad(n), next(nullptr){}; 

        int getCantidad(){return this->cantidad;}
        string getPlatillo(){return this->platillo;}
};

class LinkedPlatillos{
    public:
        NodeLPlatillo *head;

        LinkedPlatillos(){};
        ~LinkedPlatillos(){};

        LinkedPlatillos(Platillo platillo){
            head=new NodeLPlatillo(platillo);
        }
        
        LinkedPlatillos(string platillo, int cantidad){
            head=new NodeLPlatillo(platillo, cantidad);
        }

        void ImprimePlatillos();

        void EliminaDuplicados();

        void llenamosLinkedList(Platillo *platillos, int capacidad);

        /*
        void Back::llenaLinkedPlatillos(Platillo*platillos,int capacidad, LinkedPlatillos linkedplatillos){
    NodeLPlatillo* temp=linkedplatillos.head;
    for(int i=1;i<capacidad;i++){
        NodeLPlatillo *t=new NodeLPlatillo(platillos[i]);
        temp->next=t;
        temp=temp->next;
    }
}   */



};