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

template <typename RAIter> void bubbleSort(RAIter begin, RAIter end) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same<
            std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        "The bubbleSort() function only accepts random access iterators or raw "
        "pointers to an array.\n");

    int N = end - begin;
    bool sorted;

    for (int i = 0; i < N; i++, end--) {
        sorted = true;
        for (RAIter j = begin; j < end - 1; j++) {
            if (*(j + 1) < *j) {
                sorted = false;
                std::iter_swap(j + 1, j);
            }
        }
        // Ya estan ordenados
        if (sorted)
            break;
    }
}

/*
Insertion Sort

Time Complexity: O(N^2)
Memory Complexity: O(1)
Estable: Yes
*/
template <typename RAIter> void insertionSort(RAIter begin, RAIter end) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same<
            std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        "The insertionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n");

    for (RAIter i = begin + 1; i < end; i++) {
        RAIter j = i - 1;
        // Guardar el valor de *i, en el tipo de dato correcto
        typename std::iterator_traits<RAIter>::value_type key = *i;

        // Mover los elementos de [*i, ..., *(j-1)], que son mayores que *j, una
        // posición a la derecha.
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

/*
Selection Sort

Time Complexity: O(N^2)
Memory Complexity: O(1)
Estable: No
*/
template <typename RAIter> void selectionSort(RAIter begin, RAIter end) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same<
            std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        "The selectionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n");

    for (RAIter i = begin; i < end - 1; i++) {
        RAIter mini = i;
        // Buscar el elemento mas pequeño en [*i, ..., *(end-1)]
        for (RAIter j = i + 1; j < end; j++) {
            if (*j < *mini) {
                mini = j;
            }
        }
        std::iter_swap(i, mini);
    }
}

/*
Merge Sort

Time Complexity: O(N log N)
Memory Complexity: O(N)
Estable: Yes
*/
template <typename RAIter> void mergeSort(RAIter begin, RAIter end) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same<
            std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        "The selectionSort() function only accepts random access iterators or "
        "raw "
        "pointers to an array.\n");
    if (end - begin <= 1)
        return;
    RAIter mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    // combina dos cadenas consecutivas ordenadas [begin, mid) y [mid, end)
    std::inplace_merge(begin, mid, end);
}

#endif