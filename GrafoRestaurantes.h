#ifndef GRAFO_RESTAURANTES_H
#define GRAFO_RESTAURANTES_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class GrafoRestaurantes {
public:
    GrafoRestaurantes() = default;
    ~GrafoRestaurantes() = default;

    // Agregar un nuevo nodo restaurante.
    void agregarNodo(const std::string& nombre);

    // Agregar una arista no dirigida entre dos restaurantes (si faltan, se crean).
    void agregarArista(const std::string& a, const std::string& b);

    // Imprime la representación interna del grafo (lista de adyacencia).
    void imprimirGrafo() const;

    // Recorrido BFS:
    // - Si 'objetivo' no está vacío: valida existencia del objetivo y
    //   muestra la ruta desde 'inicio' hasta 'objetivo' (si existe).
    // - Si 'objetivo' está vacío: hace BFS del componente conectado a 'inicio'
    //   y muestra los nodos visitados en orden BFS.
    void recorridoBFS(const std::string& inicio, const std::string& objetivo = "") const;

    // Chequeo si un nodo existe
    bool existeNodo(const std::string& nombre) const;

private:
    // Lista de adyacencia: nombre -> vector de vecinos
    std::unordered_map<std::string, std::vector<std::string>> adj;

    // Utiles internas
    void imprimirRuta(const std::vector<std::string>& ruta) const;
};

#endif // GRAFO_RESTAURANTES_H
