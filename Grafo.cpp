#include "Grafo.h"

Grafo::Grafo() {
    numNodos = 0;
    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            matrizAdyacencia[i][j] = 0; 
        }
        nombresRestaurantes[i] = "";
    }
}

Grafo::~Grafo() {}

void Grafo::agregarNodo(string nombre) {
    if (numNodos < MAX_NODOS) {
        if(encontrarIndice(nombre) == -1){
            nombresRestaurantes[numNodos] = nombre;
            numNodos++;
        }
    } else {
        cout << "Error: Capacidad maxima de nodos alcanzada." << endl;
    }
}

int Grafo::encontrarIndice(string nombre) {
    for (int i = 0; i < numNodos; i++) {
        if (nombresRestaurantes[i] == nombre) {
            return i;
        }
    }
    return -1; 
}

void Grafo::agregarArista(string origen, string destino, int peso) {
    int i = encontrarIndice(origen);
    int j = encontrarIndice(destino);

    if (i != -1 && j != -1) {
        matrizAdyacencia[i][j] = peso;
        matrizAdyacencia[j][i] = peso; 
    } else {
        cout << "Error: Uno o ambos restaurantes no existen." << endl;
    }
}

void Grafo::agregarArista(int i, int j, int peso) {
    if (i >= 0 && i < numNodos && j >= 0 && j < numNodos) {
        matrizAdyacencia[i][j] = peso;
        matrizAdyacencia[j][i] = peso;
    }
}

int Grafo::minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index = -1; 

    for (int v = 0; v < numNodos; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Grafo::dijkstra(string origenStr, string destinoStr) {
    int src = encontrarIndice(origenStr);
    int dest = encontrarIndice(destinoStr);

    if (src == -1 || dest == -1) {
        cout << "Restaurante de origen o destino no valido." << endl;
        return;
    }

    int dist[MAX_NODOS]; 
    bool sptSet[MAX_NODOS]; 
    int parent[MAX_NODOS];  

    for (int i = 0; i < numNodos; i++) {
        dist[i] = INF; 
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < numNodos - 1; count++) {
        int u = minDistance(dist, sptSet);
        
        if (u == -1 || dist[u] == INF) break;

        sptSet[u] = true;
        
        if(u == dest) break; 

        for (int v = 0; v < numNodos; v++)
            if (!sptSet[v] && matrizAdyacencia[u][v] && dist[u] != INF
                && dist[u] + matrizAdyacencia[u][v] < dist[v]) {
                dist[v] = dist[u] + matrizAdyacencia[u][v];
                parent[v] = u;
            }
    }

    if(dist[dest] == INF){
        cout << "\nNo existe ruta entre " << origenStr << " y " << destinoStr << endl;
    } else {
        cout << "\nLa distancia mas corta de " << origenStr << " a " << destinoStr << " es: " << dist[dest] << " km/min" << endl;
        
        string camino[MAX_NODOS]; 
        int pasos = 0;            
        int curr = dest;
        
        while(curr != -1){
            camino[pasos] = nombresRestaurantes[curr];
            pasos++;
            curr = parent[curr];
        }
        
        cout << "Ruta: ";
        for(int i = pasos - 1; i >= 0; i--){
            cout << camino[i];
            if(i > 0) cout << " -> ";
        }
        cout << endl;
    }
}

void Grafo::imprimirGrafo() {
    cout << "\n--- Lista de Restaurantes en el Grafo ---" << endl;
    for (int i = 0; i < numNodos; i++) {
        cout << i << ": " << nombresRestaurantes[i] << endl;
    }
}