#include "TreeNodeP.h"
#include <iostream>

using namespace std;

TreeNodeP::TreeNodeP(){
    this->cantidad=0;
    this->platillo="";
    this->left=nullptr;
    this->right=nullptr;
}

TreeNodeP::TreeNodeP(int x, string p){
   this->cantidad=x;
   this->platillo=p;
   this->left=nullptr;
   this->right=nullptr;
}

TreeNodeP::TreeNodeP(int x, string p, TreeNodeP *left, TreeNodeP *right){
    this->cantidad=x;
    this->platillo=p;
    this->left=left;
    this->right=right;
}