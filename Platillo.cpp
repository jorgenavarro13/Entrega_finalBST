#include "Platillo.h"
#include <string>
using namespace std;

Platillo::Platillo(){};
Platillo::~Platillo(){};
Platillo::Platillo(string p, int n):platillo(p),cantidad(n){};

int Platillo::getCantidad(){return this->cantidad;}
string Platillo::getPlatillo(){return this->platillo;}
