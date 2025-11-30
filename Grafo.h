#pragma once
#include <iostream>
#include <string>
using namespace std;

const int INF = 999999; 

class Grafo {
private:
    static const int MAX_NODOS = 50; 
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
};