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

        void llenaArreglo(TreeNodeP* root, int arr[], int &index);
        void llenaArregloPostorden(TreeNodeP* root, int arr[], int &index);
        

        void imprimirArbol(TreeNodeP* node, const std::string& prefix = "", bool isLeft = true) {
            if (node == nullptr) {
                return;
            }
            imprimirArbol(node->right, prefix + (isLeft ? "|   " : "    "), false);
            cout << prefix << (isLeft ? "+-- " : "+-- ") << node->cantidad <<endl;
            imprimirArbol(node->left, prefix + (isLeft ? "    " : "|   "), true);
}

};
