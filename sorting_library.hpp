#ifndef SORTING_LIBRARY_HPP
#define SORTING_LIBRARY_HPP

#include <algorithm>
#include <iostream>
#include <type_traits>

/*
Algoritmos de ordenamiento
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort
- Heap Sort
*/

/*
Bubble Sort

Time Complexity
- Best Case O(N)
- Worst Case O(N^2)
Memory Complexity: O(1)
Stable: Yes
*/

template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void bubbleSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The bubbleSort() function only accepts random access iterators or raw "
        "pointers to an array.\n" );

    int  N = end - begin;
    bool sorted;

    for ( int i = 0; i < N; i++, end-- ) {
        sorted = true;
        for ( RAIter j = begin; j < end - 1; j++ ) {
            if ( compare( *( j + 1 ), *( j ) ) ) {
                sorted = false;
                std::iter_swap( j + 1, j );
            }
        }
        // El arreglo ya esta ordenado
        if ( sorted )
            break;
    }
}

/*
Insertion Sort

Time Complexity: O(N^2)
Memory Complexity: O(1)
Estable: Yes
*/

template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void insertionSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The insertionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );

    for ( RAIter i = begin + 1; i < end; i++ ) {
        RAIter j = i - 1;
        // Guardar el valor de *i, en el tipo de dato correcto
        typename std::iterator_traits< RAIter >::value_type key = *( i );

        // Mover los elementos de [*i, ..., *(j-1)], que son mayores que *j, una
        // posición a la derecha.
        while ( j >= begin && compare( key, *( j ) ) ) {
            *( j + 1 ) = *( j );
            j--;
        }
        *( j + 1 ) = key;
    }
}

/*
Selection Sort

Time Complexity: O(N^2)
Memory Complexity: O(1)
Estable: No
*/
template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void selectionSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The selectionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );

    for ( RAIter i = begin; i < end - 1; i++ ) {
        RAIter mini = i;
        // Buscar el elemento mas pequeño en [*i, ..., *(end-1)]
        for ( RAIter j = i + 1; j < end; j++ ) {
            if ( compare( *( j ), *( mini ) ) ) {
                mini = j;
            }
        }
        std::iter_swap( i, mini );
    }
}

/*
Merge Sort

Time Complexity: O(N log N)
Memory Complexity: O(N)
Estable: Yes
*/
template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void mergeSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The mergeSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );
    // El Arreglo es un solo elemento, ya esta ordenado
    if ( end - begin <= 1 )
        return;

    RAIter mid = begin + ( end - begin ) / 2;
    mergeSort( begin, mid );
    mergeSort( mid, end );
    // combina dos cadenas consecutivas ordenadas [begin, mid) y [mid, end)
    std::inplace_merge( begin, mid, end, compare );
}

/*
Quick Sort

Time Complexity:
- Best Case: O(N log N)
- Worst Case: O(N^2)
- Average: O(N log N)
Memory Complexity: O(1)
Estable: No
*/

template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void quickSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The quickSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );

    // Caso base un solo elemento en el arreglo
    if ( end - begin <= 1 )
        return;

    // Seleccionamos un elemento aleatorio en el arreglo
    RAIter piv = begin + ( rand() % ( end - begin ) );

    // Pasar el pivote a la ultima posición
    std::iter_swap( piv, end - 1 );
    piv = end - 1;

    // Los elementos de [begin, ind) son menores a piv y los de la derecha
    // son mayores o iguales. piv esta en la posición ind

    RAIter ind = begin - 1;
    for ( RAIter i = begin; i < piv; i++ ) {
        // El elemento actual es menor al pivote
        if ( compare( *( i ), *( piv ) ) ) {
            ind++;
            std::iter_swap( ind, i );
        }
    }
    std::iter_swap( ind + 1, piv );
    ind++;
    // piv esta en la posición correcta
    // ordenamos de [begin, ind) y [ind+1, end)
    quickSort( begin, ind, compare );
    quickSort( ind + 1, end, compare );
}

/*
Heap Sort

Time Complexity: O(N log N)
Memory Complexity: O(1)
Estable: No
*/

template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void heapify( RAIter root, int node, int N, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The heapifySort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );

    int largest = node;
    int l = node * 2 + 1, r = node * 2 + 2;
    // Tiene hijo izquierdo y es mayor a node
    if ( l < N && compare( root[largest], root[l] ) )
        largest = l;
    // Tiene hijo derecho y es mayor a node
    if ( r < N && compare( root[largest], root[r] ) )
        largest = r;
    // hay que corregir el sub-arbol
    if ( largest != node ) {
        std::swap( root[node], root[largest] );
        heapify( root, largest, N, compare );
    }
}

template< typename RAIter,
          typename Compare = std::less< typename std::iterator_traits< RAIter >::value_type > >
void heapSort( RAIter begin, RAIter end, Compare compare = {} ) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same< std::random_access_iterator_tag,
                      typename std::iterator_traits< RAIter >::iterator_category >::value,
        "The selectionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n" );

    // Vamos a utilizar el arreglo como estructura de max-heap.
    // Inicialmente tenemos un arbol binario completo y las hojas cumplen la
    // propiedad de heap (sus hijos son menores).
    // Si la raiz del arbol es el nodo 0, y el arbol tiene N nodos, entonces los
    // nodos N/2, (N/2) + 1,..., N-1 son hojas (la división es la función suelo)
    // Entonces para construir un max-heap podemos hacer heapify a los nodos
    // (N/2)-1, (N/2)-2,..., 0, en dicho orden.

    // Esto transforma el arreglo en un max-heap
    int N = end - begin;
    for ( int i = ( N / 2 ) - 1; i >= 0; i-- ) {
        heapify( begin, i, N, compare );
    }
    // Al eliminar nodo por nodo se obtiene el arreglo ordenado
    for ( int i = N - 1; i >= 0; i-- ) {
        std::swap( begin[0], begin[i] );
        heapify( begin, 0, i, compare );
    }
}
#endif