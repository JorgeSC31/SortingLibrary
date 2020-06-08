#include "sorting_library.hpp"
#include "test.h"

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main() {
    // gen_data();

    int N1 = 10'000;    // Slow Algorithms
    int N2 = 1'000'000; // Fast Algorithms

    vector< int > v1( N1 ), v2( N2 );

    for ( int i = 0; i < N1; i++ ) {
        v1[i] = rand() % 100'000;
    }
    for ( int i = 0; i < N2; i++ ) {
        v2[i] = rand() % 100'000;
    }

    const auto b1 = v1;
    const auto b2 = v2;

    // BubbleSort
    std::chrono::high_resolution_clock::time_point begin1 =
        std::chrono::high_resolution_clock::now();
    bubbleSort( v1.begin(), v1.end() );
    std::chrono::high_resolution_clock::time_point end1 =
        std::chrono::high_resolution_clock::now();
    std::cout
        << "BubbleSort Takes\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N1 << " integers" << std::endl;
    assert( is_sorted( v1.begin(), v1.end() ) );

    // InsertionSort
    v1     = b1;
    begin1 = std::chrono::high_resolution_clock::now();
    insertionSort( v1.begin(), v1.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "InsertionSort Takes\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N1 << " integers" << std::endl;
    assert( is_sorted( v1.begin(), v1.end() ) );

    // SelectionSort
    v1     = b1;
    begin1 = std::chrono::high_resolution_clock::now();
    selectionSort( v1.begin(), v1.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "SelectionSort Takes\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N1 << " integers" << std::endl;
    assert( is_sorted( v1.begin(), v1.end() ) );

    // MergeSort
    begin1 = std::chrono::high_resolution_clock::now();
    mergeSort( v2.begin(), v2.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "MergeSort Takes\t\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N2 << " integers" << std::endl;
    assert( is_sorted( v2.begin(), v2.end() ) );

    // QuickSort
    v2     = b2;
    begin1 = std::chrono::high_resolution_clock::now();
    quickSort( v2.begin(), v2.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "QuickSort Takes\t\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N2 << " integers" << std::endl;
    assert( is_sorted( v2.begin(), v2.end() ) );

    // HeapSort
    v2     = b2;
    begin1 = std::chrono::high_resolution_clock::now();
    heapSort( v2.begin(), v2.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "HeapSort Takes\t\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N2 << " integers" << std::endl;
    assert( is_sorted( v2.begin(), v2.end() ) );

    // std::sort
    v2     = b2;
    begin1 = std::chrono::high_resolution_clock::now();
    sort( v2.begin(), v2.end() );
    end1 = std::chrono::high_resolution_clock::now();
    std::cout
        << "std::sort Takes\t\t"
        << std::chrono::duration_cast< std::chrono::milliseconds >( end1 - begin1 ).count()
        << " milliseconds to sort " << N2 << " integers" << std::endl;
    assert( is_sorted( v2.begin(), v2.end() ) );

    return 0;
}