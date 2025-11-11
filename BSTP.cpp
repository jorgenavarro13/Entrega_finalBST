#include "BSTP.h"
using namespace std;

BSTP::BSTP(){}
BSTP::~BSTP(){}

TreeNodeP * BSTP::sortedListToBST(NodeLPlatillo* head) {
        if(head==nullptr)return nullptr;

        if(head->next==nullptr){return new TreeNodeP(head->cantidad,head->platillo,nullptr,nullptr);}
        
        NodeLPlatillo *slow=head;
        NodeLPlatillo *fast=head;
        NodeLPlatillo *prev=nullptr;

        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        

        TreeNodeP * root=new TreeNodeP(slow->cantidad, slow->platillo);

        if(prev!=nullptr){
            prev->next=nullptr;
        }
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        cabeza=root;
        return root;
    }

void BSTP::Inorden(TreeNodeP * node){
    if (node == nullptr)return;
            Inorden(node->left);
            cout<<"["<<node->cantidad<<","<<node->platillo<<"]";
            Inorden(node->right);

}

void BSTP::Postorden(TreeNodeP * node){
        if (node == nullptr)return;
        Postorden(node->left);
        Postorden(node->right);
        cout<<"["<<node->cantidad<<","<<node->platillo<<"]"; // ✅ la raíz se imprime al final
}

void BSTP::imprimirArbol(TreeNodeP * raiz, int espacio=0, int incremento=6) {
    if (raiz == nullptr) return;

    espacio += incremento;
    imprimirArbol(raiz->right, espacio);

    cout << endl;
    for (int i = incremento; i < espacio; i++) cout << " ";
    cout << "[" << raiz->cantidad << "] " << raiz->platillo << endl;

    imprimirArbol(raiz->left, espacio);
}