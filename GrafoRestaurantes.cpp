#include "GrafoRestaurantes.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

void GrafoRestaurantes::agregarNodo(const std::string& nombre) {
    if (adj.find(nombre) == adj.end()) {
        adj.emplace(nombre, std::vector<std::string>{});
    }
}

void GrafoRestaurantes::agregarArista(const std::string& a, const std::string& b) {
    // crear nodos si no existen
    agregarNodo(a);
    agregarNodo(b);

    // agregar arista no dirigida (evitar duplicados)
    auto &va = adj[a];
    if (std::find(va.begin(), va.end(), b) == va.end()) {
        va.push_back(b);
    }
    auto &vb = adj[b];
    if (std::find(vb.begin(), vb.end(), a) == vb.end()) {
        vb.push_back(a);
    }
}

void GrafoRestaurantes::imprimirGrafo() const {
    std::cout << "Grafo (lista de adyacencia):\n";
    for (const auto &p : adj) {
        std::cout << "  " << p.first << " -> ";
        for (size_t i = 0; i < p.second.size(); ++i) {
            std::cout << p.second[i] << (i + 1 < p.second.size() ? ", " : "");
        }
        std::cout << "\n";
    }
}

bool GrafoRestaurantes::existeNodo(const std::string& nombre) const {
    return adj.find(nombre) != adj.end();
}

void GrafoRestaurantes::imprimirRuta(const std::vector<std::string>& ruta) const {
    if (ruta.empty()) {
        std::cout << "(ruta vacía)\n";
        return;
    }
    std::cout << "Ruta: ";
    for (size_t i = 0; i < ruta.size(); ++i) {
        std::cout << ruta[i];
        if (i + 1 < ruta.size()) std::cout << " -> ";
    }
    std::cout << "\n";
}

void GrafoRestaurantes::recorridoBFS(const std::string& inicio, const std::string& objetivo) const {
    if (!existeNodo(inicio)) {
        std::cout << "Inicio \"" << inicio << "\" no existe en la red.\n";
        return;
    }

    // BFS estándar
    std::queue<std::string> q;
    std::unordered_set<std::string> visitados;
    std::unordered_map<std::string, std::string> padre; // para reconstruir ruta

    q.push(inicio);
    visitados.insert(inicio);
    padre[inicio] = ""; // marca de inicio

    bool objetivoEncontrado = false;

    while (!q.empty()) {
        std::string actual = q.front(); q.pop();

        // Si hay objetivo y lo encontramos, podemos romper (pero dejamos lógica para reconstruir ruta)
        if (!objetivo.empty() && actual == objetivo) {
            objetivoEncontrado = true;
            break;
        }

        // recorrer vecinos
        auto it = adj.find(actual);
        if (it == adj.end()) continue; // sin vecinos
        for (const std::string& vecino : it->second) {
            if (visitados.find(vecino) == visitados.end()) {
                visitados.insert(vecino);
                padre[vecino] = actual;
                q.push(vecino);
            }
        }
    }

    if (!objetivo.empty()) {
        // usuario pidió ruta hasta objetivo
        if (!existeNodo(objetivo)) {
            std::cout << "Objetivo \"" << objetivo << "\" no existe en la red.\n";
            return;
        }
        if (!objetivoEncontrado && visitados.find(objetivo) == visitados.end()) {
            std::cout << "No hay ruta desde \"" << inicio << "\" hasta \"" << objetivo << "\" (están en componentes distintos).\n";
            return;
        }

        // reconstruir ruta desde objetivo hasta inicio
        std::vector<std::string> ruta;
        std::string cur = objetivo;
        // Si objetivo == inicio, esto añadirá solo el inicio
        while (!cur.empty()) {
            ruta.push_back(cur);
            auto pit = padre.find(cur);
            if (pit == padre.end()) break;
            cur = pit->second;
        }
        std::reverse(ruta.begin(), ruta.end());
        std::cout << "BFS (ruta encontrada):\n";
        imprimirRuta(ruta);
    } else {
        // objetivo vacío: listar nodos visitados en orden BFS del componente conectado
        std::cout << "BFS (nodos visitados desde \"" << inicio << "\"):\n";
        // visitados contiene todos los nodos del componente; pero no está en orden exacto BFS,
        // así que volvemos a realizar BFS pero imprimiendo en el orden en que salen de la cola:
        std::queue<std::string> q2;
        std::unordered_set<std::string> seen;
        q2.push(inicio);
        seen.insert(inicio);
        bool primero = true;
        while (!q2.empty()) {
            std::string nodo = q2.front(); q2.pop();
            if (!primero) std::cout << " -> ";
            std::cout << nodo;
            primero = false;
            auto it = adj.find(nodo);
            if (it == adj.end()) continue;
            for (const auto &v : it->second) {
                if (seen.find(v) == seen.end()) {
                    seen.insert(v);
                    q2.push(v);
                }
            }
        }
        std::cout << "\n";
    }
}
