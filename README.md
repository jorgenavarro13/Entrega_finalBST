# Sistema de Gestión de Órdenes con BST

Este proyecto implementa un sistema de gestión de órdenes utilizando un Árbol Binario de Búsqueda (BST) para el manejo eficiente de datos de pedidos de restaurantes.

## Estructura del Proyecto

El proyecto está organizado en los siguientes archivos:

- `main.cpp` - Punto de entrada del programa
- `Back.h/cpp` - Implementación de la lógica de negocio y operaciones BST
- `Orden.h/cpp` - Clase para el manejo de órdenes individuales
- `orders.txt` - Archivo de datos con las órdenes

## Clases Principales

### Clase Orden

Representa una orden individual con los siguientes atributos:
- Fecha (mes, día)
- Hora (hora, minuto, segundo)
- Restaurante
- Platillo
- Precio

Métodos principales:
- Getters para todos los atributos
- Conversión de mes en texto a número
- Cálculo de fecha en segundos para ordenamiento

### Clase Back

Maneja la lógica principal del sistema:

#### Métodos de Ordenamiento
- `particionT<T>`: Implementa la partición para QuickSort
- `ordQuickT<T>`: Implementa el algoritmo QuickSort
  - Complejidad temporal: O(n log n) caso promedio
  - Complejidad espacial: O(log n)

#### Métodos de Búsqueda
- `buscarInicio`: Búsqueda binaria para encontrar el inicio de un rango
- `buscarFin`: Búsqueda binaria para encontrar el fin de un rango

#### Manejo de Archivos
- `retornaNumeroLineas`: Cuenta el número de líneas en el archivo
- `cargarOrdenes`: Lee y procesa el archivo de órdenes

#### Métodos de Interfaz
- `preguntaMes`: Validación de entrada para mes
- `preguntaDia`: Validación de entrada para día
- `preguntaHora`: Validación de entrada para hora
- `preguntaArchivo`: Manejo de guardado de archivos

## Formato del Archivo de Datos

El archivo `orders.txt` debe tener el siguiente formato por línea:
```
[Mes] [Día] [HH]:[MM]:[SS] Restaurante:[Nombre]: [Platillo] ([Precio])
```
Ejemplo:
```
Enero 1 12:30:00 Restaurante:McDonalds: Hamburguesa (150)
```

## Compilación y Ejecución

Para compilar el proyecto:
```bash
g++ -O2 *.cpp -o program
```

Para ejecutar:
```bash
./program
```

## Optimizaciones Implementadas

1. Uso de Templates para flexibilidad en tipos de datos
2. Optimización de lectura de archivos
3. Limpieza de datos en tiempo de procesamiento
4. Manejo eficiente de memoria con arrays estáticos

## Complejidad Algorítmica

- Ordenamiento (QuickSort): O(n log n) promedio
- Búsqueda Binaria: O(log n)
- Carga de Datos: O(n) donde n es el número de líneas en el archivo

## Manejo de Errores

El sistema implementa manejo de excepciones para:
- Validación de entrada de usuario
- Apertura y lectura de archivos
- Parsing de datos

## Mejoras Futuras Posibles

1. Implementación de persistencia de datos
2. Interfaz gráfica de usuario
3. Soporte para múltiples formatos de archivo
4. Búsquedas avanzadas por criterios múltiples
