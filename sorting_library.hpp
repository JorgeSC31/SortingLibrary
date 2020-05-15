#ifndef SORTING_LIBRARY_HPP
#define SORTING_LIBRARY_HPP

#include <iostream>
#include <type_traits>

/*
Bubble sort

Time Complexity
- Best Case O(N)
- Worst Case O(N^2)

Memory Complexity
O(1)

Estable: Sí
*/

template <typename RAIter> void bubblesort(RAIter begin, RAIter end) {
    // Verificar que se paso el tipo de iterador correcto
    static_assert(
        std::is_same<
            std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        "The bubblesort() function only accepts random access iterators or raw "
        "pointers to an array.\n");

    bool sorted;
    for (int i = 0, N = (end - begin); i < N; i++, end--) {
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

#endif