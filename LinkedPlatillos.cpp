#include "LinkedPlatillos.h"
using namespace std;

void LinkedPlatillos::llenamosLinkedList(Platillo *platillos, int capacidad) {
    NodeLPlatillo *current = head; 
    for (int i = 1; i < capacidad; i++) {
        NodeLPlatillo *nuevo_nodo = new NodeLPlatillo(platillos[i].getPlatillo(), platillos[i].getCantidad());
            current->next = nuevo_nodo;
            current = nuevo_nodo;        
        
    }
}

void LinkedPlatillos::ImprimePlatillos(){
        NodeLPlatillo *temp=head;
        while(temp!=nullptr){
            cout<<temp->getPlatillo()<<" :"<<temp->getCantidad()<<endl;
            temp=temp->next;
        }
        cout<<"Terminamos de imprimir correctamente"<<endl;
    }

void LinkedPlatillos::EliminaDuplicados(){
        NodeLPlatillo *temp=head;
        while(temp->next!=nullptr){
            if(temp->cantidad==temp->next->cantidad){
                temp->cantidad+=temp->next->cantidad;
                temp->platillo+=temp->next->platillo;
                NodeLPlatillo *aBorrar=temp->next;
                temp->next=temp->next->next;
                delete aBorrar;
            }else{
                temp=temp->next;
            }

    }
}   