
# Sistema de Gestión, Análisis de Órdenes y Conectividad (BST & Map-Based Graphs)

**Autor:** Jorge Arturo Montiel Navarro & Emilio Ogaz Galvan

Este proyecto en C++ implementa un sistema robusto para el procesamiento de un **dataset masivo** de órdenes de *Food Delivery*. La solución combina algoritmos de ordenamiento eficientes, estructuras de árbol para análisis de frecuencias y una implementación flexible de **Grafos basada en Hash Maps** para descubrir relaciones y rutas entre restaurantes.

## 1\. Flujo del Sistema y Arquitectura

El proyecto se ejecuta en tres etapas lógicas claramente definidas en `main.cpp`:

### Etapa 1: Procesamiento Temporal (Arrays & QuickSort)

  * **Carga:** Se leen miles de registros desde `orders.txt` a un arreglo estático de objetos `Orden`.
  * **Ordenamiento:** Se utiliza un algoritmo **QuickSort Genérico** (implementado en `Back.h`) para ordenar todas las órdenes cronológicamente.

### Etapa 2: Red de Restaurantes (Grafos con Hash Maps)

Esta versión modela la conectividad entre restaurantes basándose en los **platillos que comparten**. Si dos restaurantes sirven el mismo platillo, existe una conexión entre ellos.

  * **Estructura de Datos:** No se usa una clase grafo tradicional rígida. Se emplean contenedores de la STL para una gestión dinámica y eficiente:
      * **`restToPlat`** (`unordered_map<string, unordered_map<string, int>>`): Mapea cada restaurante a sus platillos y la frecuencia de venta (peso).
      * **`platToRest`** (`unordered_map<string, vector<string>>`): Mapa inverso que permite saber qué restaurantes sirven un platillo específico.
  * **Algoritmo BFS (Búsqueda en Anchura):**
      * Implementado en `Back::bfsRestaurante`.
      * Utiliza los mapas anteriores para navegar la red.
      * **Objetivo:** Encontrar si existe una ruta (y cuál es) entre un `Restaurante A` y un `Restaurante B` saltando a través de platillos compartidos.

### Etapa 3: Ranking de Platillos (BST Balanceado)

  * **Agregación:** Se procesan las órdenes para contar la frecuencia de cada platillo único usando una Lista Ligada (`LinkedPlatillos`) para eliminar duplicados.
  * **Estructura BST:** Se construye un **Árbol Binario de Búsqueda Balanceado** a partir de los datos ordenados.
  * **Reportes:** Se generan recorridos **Inorden** (ranking ascendente) y **Postorden**, además de una visualización gráfica del árbol.

## 2\. Descripción de Archivos

| Archivo | Función Principal |
| :--- | :--- |
| `main.cpp` | Orquestador del programa. Construye los mapas del grafo (`restToPlat`), gestiona la interacción de búsqueda de rutas y coordina la creación del BST. |
| `Back.h/cpp` | Lógica de negocio central. Contiene el algoritmo **BFS** para grafos y el **QuickSort** genérico (Templates). |
| `Orden.h/cpp` | TAD que representa una orden con *parsing* inteligente de fechas y horas. |
| `Platillo.h/cpp` | TAD que encapsula el nombre y la cantidad de ventas de un producto. |
| `BSTP.h/cpp` | Implementación del Árbol Binario de Búsqueda Balanceado para el ranking. |
| `LinkedPlatillos.h/cpp` | Lista ligada auxiliar para la limpieza y agrupación inicial de platillos. |
| `orders.txt` | Base de datos de entrada con el registro histórico de órdenes. |

## 3\. Análisis de Complejidad

### Construcción del Grafo (Maps)

  * **Complejidad:** O(N), donde N es el número de órdenes.
  * **Justificación:** Se recorre el arreglo de órdenes una sola vez, y la inserción en los `unordered_map` tiene un costo promedio de O(1).

### Búsqueda de Ruta (BFS)

  * **Complejidad:** O(V + E), donde V son restaurantes y E son las conexiones (platillos compartidos).
  * **Eficiencia:** Al usar mapas hash para las listas de adyacencia, la búsqueda de vecinos es extremadamente rápida.

### Construcción del BST

  * **Complejidad:** O(N) para construirlo desde una lista ordenada (`sortedListToBST`).
  * **Balanceo:** El algoritmo garantiza un árbol de altura logarítmica, optimizando futuras búsquedas a O(log P), donde P es el número de platillos únicos.

## 4\. Compilación y Ejecución

El proyecto está configurado para compilar todos los archivos fuente en un único ejecutable. Asegúrate de tener el archivo `orders.txt` en el mismo directorio.

### Comandos (Terminal)

```bash
# Compilar
g++ *.cpp -o sistema_delivery

# Ejecutar
./sistema_delivery  # (o sistema_delivery.exe en Windows)
```

## 5\. Instrucciones de Uso

Al iniciar el programa:

1.  **Carga Automática:** El sistema cargará y ordenará las órdenes.
2.  **Visualización del Grafo:** Se imprimirá en consola la lista de adyacencia (Restaurante -\> Platillos).
3.  **Búsqueda de Rutas:**
      * El sistema solicitará un **Restaurante de Inicio**.
      * Luego solicitará un **Restaurante de Destino**.
      * **Resultado:** El programa indicará si existe conexión y mostrará la ruta encontrada (e.g., *Restaurante A -\> Platillo X -\> Restaurante B*).
4.  **Reporte de Platillos:** Finalmente, se desplegará el análisis del BST con los platillos más vendidos ordenados.
