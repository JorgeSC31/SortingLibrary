# Sorting Library
### Proyecto final de Estructuras de Datos y Algoritmos
#### Universidad de Guanajuato

**Sorting Library** es una libreria implementada en C++ que nos ofrece multiples algoritmos de ordenamiento populares. Podremos elegir el algoritmo de ordenamiento que mejor se adecue a nuestra necesidad, ya sea por memoria, tiempo o si requerimos un algoritmo de ordenamiento que sea estable o no.

## Instalación
Para agregar Sorting Library a tu proyecto puedes descargar el archivo `sorting_library.hpp` de este repositorio.
Después, simplemente incluye este archivo en cualquier archivo de C++ en el que necesites la libreria y enlaza el archivo cabezera.

`#include "sorting_library.hpp"`

## Algoritmos de ordenamiento
La libreria actualmente contiene 6 algoritmos de ordenamiento 
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort
- Heap Sort
### Bubble Sort
Bubble Sort, es un algoritmo de ordenamiento simple que recorre repetidamente la lista para ordenar, compara cada par de elementos adyacentes y los intercambia si esta en el orden incorrecto. El paso por la lista se repite hasta que no se necesitan intercambios, lo que indica que la lista está ordenada. Aunque el algoritmo es simple, es demasiado lento y poco practico. El Bubble Sort puede ser útil si la entrada está casi ordenada.

Análisis complejidad en tiempo:

|Peor caso|Caso promedio|Mejor caso|
|---|---|---|
|O(n<sup>2</sup>)|Θ(n<sup>2</sup>)|Ω(n)|

|In-place?|Stable?|
|---|---|
|Yes|Yes|

### Insertion Sort
Insertion Sort, es un algoritmo de ordenamiento simple que crea el arreglo ordenado final, un elemento a la vez. El Insertion Sort, en cada iteración toma un elemento de la lista de entrada, encuentra la ubicación a la que pertenece dentro de la lista dentro de la lista ordenada y lo inserta alli. Se repite hasta que todos los elementos de entrada hayan sido insertados.

Análisis complejidad en tiempo:
|Peor caso|Caso promedio|Mejor caso|
|---|---|---|
|O(n<sup>2</sup>)|Θ(n<sup>2</sup>)|Ω(n)|

|In-place?|Stable?|
|---|---|
|Yes|Yes|

### Selection Sort
Selection Sort, es un algoritmo de ordenamiento, especificamente un ordenamiento por comparacion in-place. No es eficiente para entradas grandes ya que tiene complejidad cuadratica.
El algoritmo divide la lista de entrada en dos partes: la sublista de elementos ya ordenados, que se construye de izquierda a derecha en la parte delantera (izquierda) de la lista, y la sublista de elementos restantes para ordenar que ocupan el resto del lista. Inicialmente, la sublista ordenada está vacía y la sublista no ordenada es la lista de entrada completa. El algoritmo continúa encontrando el elemento más pequeño en la sublista no ordenada, intercambiándolo con el elemento no ordenado más a la izquierda.

Análisis complejidad en tiempo:
|Peor caso|Caso promedio|Mejor caso|
|---|---|---|
|O(n<sup>2</sup>)|Θ(n<sup>2</sup>)|Ω(n<sup>2</sup>)|

|In-place?|Stable?|
|---|---|
|Yes|No|

### Merge Sort
Merge Sort, es un algoritmo de ordenamiento eficiente, basado en comparaciones. Es un algortimo del tipo *divide y veceras*. Conceptualmente el Merge Sort trabaja de la siguiente manera:
1. Divide la lista no ordenada en n sublistas de tamaño 1 (Una lista de tamaño 1 está ordenada)
2. Combina repetidamente las sublistas para producir una nueva sublista ordenada hasta que solo quede una sublista. Esta sera la lista ordenada.

Análisis complejidad en tiempo:
|Peor caso|Caso promedio|Mejor caso|
|---|---|---|
|O(n log(n))|Θ(n log(n))|Ω(n log(n))|

|In-place?|Stable?|
|---|---|
|Yes|No|

### Quick Sort
Quick Sort, es un algoritmo de ordenamiento eficiente. Puede llegar a ser mas rapido que el *Merge Sort* y el *Heap Sort*. Sin embargo en el peor caso tiene complejidad cuadratica.

Análisis complejidad en tiempo:
|Peor caso|Caso promedio|Mejor caso|
|---|---|---|
|O(n<sup>2</sup>)|Θ(n log(n))|Ω(n log(n))|

|In-place?|Stable?|
|---|---|
|Yes|No|

### Heap Sort
Heap Sort, es un algoritmo de ordenamient basado en comparaciones. Este algorimto usa la estructura de datos heap para ordenar la lista. Primero prepara la lista no ordenada en un *max-heap*, Despues extra el elemento maximo uno por uno y lo pone al final de la lista.

Time complexity analysis:

|Worst Case|Average Case|Best Case|
|---|---|---|
|O(n log(n))|Θ(n log(n))|Ω(n) (bottom up)|

|In-place?|Stable?|
|---|---|
|Yes|No|

## Uso
```
```cpp
default (1)

template <class RandomAccessIterator>
  void bubbleSort (RandomAccessIterator begin, RandomAccessIterator end);

custom (2)

template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator begin, RandomAccessIterator end, Compare compare);
```
```

## Creditos
La libreria `sorting_library` fue creada por Jorge Salazar Cruz.



