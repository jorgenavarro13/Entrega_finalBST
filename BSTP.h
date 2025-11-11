#pragma once
#include "LinkedPlatillos.h"
#include "TreeNodeP.h"
#include <string>
using namespace std;

class BSTP{
    public:
        TreeNodeP *cabeza;
        
        BSTP();
        ~BSTP();

        TreeNodeP * sortedListToBST(NodeLPlatillo* head);
        void Inorden(TreeNodeP * node);
        void Postorden(TreeNodeP * node);
        void imprimirArbol(TreeNodeP *head,int espacio, int incremeto);
        
};
