#pragma once
#include "LinkedPlatillos.h"

using namespace std;

class TreeNodeP{
    public:
        string platillo;
        int cantidad;

        TreeNodeP *left;
        TreeNodeP *right;
        TreeNodeP();
        TreeNodeP(int x, string p);
        TreeNodeP(int x, string p, TreeNodeP *left, TreeNodeP *right);
};

