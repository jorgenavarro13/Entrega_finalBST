#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <limits>
#include <string>
#include "Orden.h"
using namespace std;

class Platillo{
    public:
        string platillo;
        int cantidad;

        Platillo();
        ~Platillo();
        Platillo(string platillo, int cantidad);
        string getPlatillo();
        int getCantidad();
    
};