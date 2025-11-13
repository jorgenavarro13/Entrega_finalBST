# Sistema de Gestión y Análisis de Órdenes (BST Final Project)

Autor: Jorge Arturo Montiel Navarro 

Este proyecto en C++ implementa un sistema avanzado para la gestión y análisis de un **conjunto de datos masivo** de órdenes de un servicio de *Food Delivery*. La solución se centra en la eficiencia algorítmica para el procesamiento, ordenamiento, y búsqueda de registros, además de la construcción de una estructura de datos balanceada (Árbol Binario de Búsqueda) a partir de los datos procesados.

## 1. Estructura del Proyecto

El proyecto está organizado en los siguientes archivos principales:

| Archivo | Descripción |
| :--- | :--- |
| `main.cpp` | Punto de entrada del programa. Coordina la carga, el ordenamiento y la construcción del BST. |
| `Back.h/cpp` | Clase que contiene la lógica de negocio, métodos de ordenamiento genéricos (QuickSort), funciones de búsqueda binaria y lógica de interacción con el usuario. |
| `Orden.h/cpp` | Clase que representa una orden individual y contiene la lógica para el *parsing* de datos de tiempo y detalles de la orden. |
| `Platillo.h/cpp` | Clase que encapsula el nombre del platillo y la cantidad de veces que fue ordenado. |
| `LinkedPlatillos.h/cpp`| Implementación de una lista ligada para almacenar objetos `Platillo` de forma temporal. Incluye lógica para eliminar duplicados y agrupar platillos. |
| `TreeNodeP.h/cpp` | Clase que define la estructura de un nodo para el Árbol Binario de Búsqueda (BST), almacenando la cantidad y nombre del platillo. |
| `BSTP.h/cpp` | Clase que implementa la estructura del BST y sus operaciones fundamentales, incluyendo el método de balanceo. |
| `orders.txt` | Archivo de datos masivo (~10,000 registros) que contiene las órdenes de *Food Delivery*. |
| `printBST.py` | Script auxiliar en Python utilizado para la verificación visual y generación de `arbol.txt` con una impresión horizontal del BST. |
| `reporte.tex` | Documento técnico que detalla el planteamiento, la justificación de algoritmos y el análisis de complejidad de la solución. |

## 2. Clases y Tipos de Datos Abstractos (TADs)

### Clase `Orden`

Encapsula los atributos de cada registro del archivo, enfocándose en la **marca temporal** y los **detalles de la orden**.

| Atributo | Tipo | Descripción |
| :--- | :--- | :--- |
| `mes`, `restaurante`, `platillo` | `string` | Cadenas de texto que describen la orden. |
| `dia`, `hora`, `minuto`, `segundo`, `precio` | `int` | Componentes numéricos de la fecha y el costo. |
| `mesInt` | `int` | Valor entero del mes (1=Enero, etc.), calculado por `mes_to_int`. |
| `fechaSegundos` | `int` | Marca temporal unificada calculada en segundos, utilizada como clave para el ordenamiento y búsqueda. |

**Lógica de Creación:**
El constructor especializado (`Orden(char *mes,...)`) realiza el *parsing* y la **conversión de tipos** (cadenas a enteros) en tiempo de instanciación. Incluye lógica de limpieza de caracteres en `restaurante` y `platillo` para asegurar datos consistentes.

### Clases para el BST de Platillos

La jerarquía de clases para el BST permite el manejo y la organización de los platillos más vendidos.

* **`Platillo`:** Objeto simple para almacenar `string platillo` y `int cantidad`. Se usa en un arreglo dinámico temporal.
* **`NodeLPlatillo` (Lista Ligada):** Nodo para una lista ligada utilizada como etapa intermedia después de la agregación. Almacena `string platillo` y `int cantidad`.
* **`LinkedPlatillos`:** Contiene el `head` de la lista ligada de platillos. Su método clave es `EliminaDuplicados()`, que itera sobre la lista y agrupa los nombres de platillos que tienen la misma cantidad de ventas, concatenando sus nombres con una coma.
* **`TreeNodeP` (Nodo BST):** Nodo para el BST. Almacena `string platillo` y `int cantidad`. El campo `cantidad` actúa como la clave de ordenamiento.
* **`BSTP` (BST de Platillos):** La estructura principal del árbol.

## 3. Algoritmos y Complejidad

El proyecto se basa en algoritmos de alto rendimiento para garantizar una solución eficiente.

### 3.1. Ordenamiento: Quick Sort (Genérico con Templates y Lambdas)

Se implementó el algoritmo Quick Sort de forma genérica mediante el uso de *templates* (`ordQuickT`, `particionT`). Para su uso específico, se emplean **funciones lambda** que definen dinámicamente el criterio de ordenamiento, permitiendo ordenar tanto la lista de `Orden` por `fechaSegundos` como el arreglo de `Platillo` por `cantidad`.

| Operación | Complejidad Temporal (T) | Complejidad Espacial (E) | Justificación |
| :--- | :--- | :--- | :--- |
| Carga de datos | O(n) | O(n) | Recorrido lineal del archivo y almacenamiento de cada orden en un arreglo. |
| Ordenar Órdenes | **O(n log n)** (promedio) | O(log n) | Uso del algoritmo QuickSort. La complejidad espacial es reducida, dependiendo de la recursión. |
| Llenado de Platillos | O(n x P) | O(P) | Búsqueda lineal dentro de la lista de `P` platillos distintos por cada una de las `N` órdenes. |

### 3.2. Búsqueda: Búsqueda Binaria

Utilizada para encontrar de manera eficiente los **índices de inicio y fin** para el filtrado de órdenes por rango de fechas. Esto es posible porque el arreglo de `Orden` ha sido pre-ordenado por `fechaSegundos`.

| Función | Complejidad Temporal (T) | Complejidad Espacial (E) | Objetivo |
| :--- | :--- | :--- | :--- |
| `buscarInicio` | **O(log n)** | O(1) | Encuentra la **primera** ocurrencia o el valor más aproximado *por arriba* del límite inferior de la fecha. |
| `buscarFin` | **O(log n)** | O(1) | Encuentra la **última** ocurrencia o el valor más aproximado *por abajo* del límite superior de la fecha. |

### 3.3. Estructura de Datos (BST)

El proyecto construye un **Árbol Binario de Búsqueda Balanceado** (BST) a partir de la lista final de platillos únicos y ordenados por cantidad.

* **Algoritmo de Construcción:** `sortedListToBST`. Este algoritmo toma la lista ligada ordenada de platillos y la convierte en un BST **perfectamente balanceado**. El algoritmo funciona encontrando el nodo central de la lista ligada (que se convierte en la raíz del subárbol), y luego recursivamente construyendo los subárboles izquierdo (de la mitad izquierda) y derecho (de la mitad derecha).
* **Recorridos:** Se implementan los recorridos en **Inorden** (imprime los platillos por cantidad de menor a mayor) y **Postorden** (útil para ciertas operaciones de eliminación o copia).

## 4. Manejo de Archivos y Formato de Datos

### Formato de `orders.txt`
El sistema procesa un archivo de texto plano con la siguiente estructura consistente por línea:
```
[Mes] [Día] [HH]:[MM]:[SS] R:Restaurante:[Nombre_Restaurante] O:Platillo(Precio)
```

**Mecanismo de Carga:**
La función `cargarOrdenes` utiliza `f.getline` y `strtok` para la **tokenización** de la cadena de texto, separando los datos según delimitadores como espacios, dos puntos (`:`) y paréntesis `()`.

### Lógica de Validación de Entrada

Para asegurar la robustez del sistema, se implementa un mecanismo de **manejo de excepciones** para las funciones de solicitud de datos (`preguntaHora()`, `preguntaDia()`, `preguntaMes()`, `preguntaArchivo()`).

Este mecanismo verifica dos escenarios críticos:
1.  **Rango Inválido:** La entrada excede los límites lógicos (e.g., mes 13, día 35).
2.  **Formato Incorrecto:** Se ingresa un valor no numérico (e.g., una letra) cuando se espera un entero.

La complejidad temporal de la validación se considera **O(k)**, siendo *k* el número de intentos fallidos por parte del usuario.

## 5. Compilación y Ejecución

Para compilar y ejecutar el proyecto, asegúrate de tener un compilador C++ (como g++) y el archivo `orders.txt` en el mismo directorio.



### En Linux / macOS
```bash
# Compilación con optimización O2 para mejorar rendimiento
g++ -O2 *.cpp -o program
# Ejecución del programa
./program
```

### 6. Logros y Optimización
Eficiencia Comprobada: Se eligió QuickSort por su desempeño promedio de O(n log n) y su naturaleza cache friendly.

- **Estructuras de Datos Avanzadas:** Uso de BST balanceado para optimizar futuras búsquedas por cantidad de ventas, y el uso de listas ligadas para una manipulación de datos temporal más dinámica.

- **Generalización de Algoritmos:** Implementación de QuickSort mediante templates para reutilizar el código con diferentes estructuras (Orden y Platillo) y criterios de ordenamiento (fecha vs. cantidad).

- **Control de Flujo Robusto:** Implementación de manejo de excepciones para la interfaz con el usuario, asegurando que el programa no se interrumpa ante entradas inválidas.

- **Generación de Estructura Verificable:** El uso del script en Python (printBST.py) permitió generar una representación verificable del árbol (arbol.txt) para asegurar su correcta construcción y balanceo

### 7. Mejoras Futuras Posibles
Persistencia de Datos: Implementar funcionalidades para guardar el BST directamente a un archivo (serialización) para evitar recargar y reordenar orders.txt en cada ejecución.

Interfaz Gráfica de Usuario (GUI): Desarrollar una interfaz para facilitar la consulta y visualización de los datos.

Búsquedas Avanzadas: Permitir búsquedas por criterios múltiples o rangos más complejos (e.g., platillo y fecha).

Manejo Asincrónico de I/O: Optimizar la lectura del archivo para conjuntos de datos aún más grandes utilizando técnicas de I/O no bloqueante.
