#pragma once
#include <iostream>
#include <string>

using namespace std;

// Definimos infinito (999999 es suficiente para este mapa)
const int INF = 999999; 

class Grafo {
private:
    // 200 es un tamaño seguro para la memoria RAM estática.
    // Es muy probable que tus restaurantes únicos sean menos de 100.
    static const int MAX_NODOS = 200; 
    
    int matrizAdyacencia[MAX_NODOS][MAX_NODOS]; 
    string nombresRestaurantes[MAX_NODOS]; 
    int numNodos; 

    int minDistance(int dist[], bool sptSet[]);

public:
    Grafo();
    ~Grafo();

    void agregarNodo(string nombre); 
    void agregarArista(string origen, string destino, int peso);
    void agregarArista(int i, int j, int peso);
    
    void dijkstra(string origen, string destino);

    int encontrarIndice(string nombre);
    void imprimirGrafo();
    
    // Método extra para saber cuántos cargó realmente
    int getNumNodos() { return numNodos; }
};