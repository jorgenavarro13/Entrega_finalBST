#include "Analizador.h"

Analizador::Analizador() {}
Analizador::~Analizador() {}

string Analizador::encontrarMejorRestaurante(Orden ordenes[], long int n, string platilloBuscado) {
    // Arreglos temporales para guardar los contadores
    // Asumimos un máximo de 200 restaurantes distintos (igual que en tu grafo estático)
    string nombresRest[200];
    int conteoVentas[200];
    int totalRestaurantesEncontrados = 0;

    // Inicializar contadores en 0
    for(int i = 0; i < 200; i++) {
        conteoVentas[i] = 0;
        nombresRest[i] = "";
    }

    // 1. Recorremos TODAS las órdenes (Barrido lineal)
    for(int i = 0; i < n; i++) {
        // Solo nos interesa si la orden es del platillo que buscamos
        if(ordenes[i].getPlatillo() == platilloBuscado) {
            
            string restauranteActual = ordenes[i].getRestaurante();
            
            // Buscamos si ya tenemos este restaurante en nuestra lista temporal
            int indice = -1;
            for(int k = 0; k < totalRestaurantesEncontrados; k++) {
                if(nombresRest[k] == restauranteActual) {
                    indice = k;
                    break;
                }
            }

            if(indice != -1) {
                // Si ya existía, le sumamos una venta
                conteoVentas[indice]++;
            } else {
                // Si es nuevo, lo agregamos a la lista
                if(totalRestaurantesEncontrados < 200) {
                    nombresRest[totalRestaurantesEncontrados] = restauranteActual;
                    conteoVentas[totalRestaurantesEncontrados] = 1; // Primera venta
                    totalRestaurantesEncontrados++;
                }
            }
        }
    }

    // 2. Buscar quién vendió más (El máximo)
    int maxVentas = -1;
    string restauranteGanador = "No encontrado";

    for(int i = 0; i < totalRestaurantesEncontrados; i++) {
        if(conteoVentas[i] > maxVentas) {
            maxVentas = conteoVentas[i];
            restauranteGanador = nombresRest[i];
        }
    }

    if(maxVentas == -1) {
        return "Nadie vende este platillo";
    }

    // Opcional: Imprimir cuánto vendió
    cout << "   -> (Record de ventas: " << maxVentas << " ordenes)" << endl;

    return restauranteGanador;
}