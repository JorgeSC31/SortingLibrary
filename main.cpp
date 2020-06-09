#include "sorting_library.hpp"
#include "test.h"

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

struct person {
    string name;
    int    age;
    float  height;

    person() {
        name   = "";
        age    = 0;
        height = 0.0;
    }
    person( string _name, int _age, float _height ) {
        name   = _name;
        age    = _age;
        height = _height;
    }

    // Default operator <
    // sot by name, age, height
    bool operator<( const person& ot ) const {
        if ( name < ot.name )
            return true;
        if ( name == ot.name && age < ot.age )
            return true;
        if ( name == ot.name && age == ot.age && height < ot.height )
            return true;
        return false;
    }
    friend ostream& operator<<( ostream& os, const person& p1 );
};

ostream& operator<<( ostream& os, const person& p1 ) {
    os << "[" << p1.name << ", " << p1.age << ", " << p1.height << "]";
    return os;
}

// Custom operator <
// sort name, height
// different output with non stable sorting algorithm
bool comp1( const person& p1, const person& p2 ) {
    if ( p1.name < p2.name )
        return true;
    if ( p1.name == p2.name && p1.height < p2.height )
        return true;
    return false;
}

// Custom operator <
// Sort in decreasing order in name
// Sort in ascending order in age
bool comp2( const person& p1, const person& p2 ) {
    if ( p1.name > p2.name )
        return true;
    if ( p1.name == p2.name && p1.age < p2.age )
        return true;
    return false;
}

template< typename T > void print( const vector< T >& v, string text = "" ) {
    if ( text != "" )
        cout << text << '\n';
    for ( auto u: v ) {
        cout << u << ' ';
    }
    cout << '\n';
}

int main() {
    // gen_data();

    vector< person > vp;
    vp.push_back( { "Jorge", 18, 1.79 } );
    vp.push_back( { "Zonia", 22, 1.41 } );
    vp.push_back( { "Alicia", 60, 1.55 } );
    vp.push_back( { "Jorge", 40, 1.68 } );
    vp.push_back( { "Claudia", 42, 1.64 } );
    vp.push_back( { "Alicia", 80, 1.55 } );

    const auto bvp = vp;

    auto vp1 = bvp;
    auto vp2 = bvp;
    auto vp3 = bvp;

    mergeSort( vp1.begin(), vp1.end() );
    quickSort( vp2.begin(), vp2.end(), comp1 );
    heapSort( vp3.begin(), vp3.end(), comp2 );
    print( bvp, "Original: " );
    cout << '\n';
    print( vp1, "Default operator <, merge sort" );
    cout << '\n';
    print( vp2, "comp1, quick sort" );
    cout << '\n';
    print( vp3, "comp2, heap sort" );
    cout << "\n\n\n";

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