#include "sorting_library.hpp"

#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

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
    person( string name1, int age1, float height1 ) {
        name   = name1;
        age    = age1;
        height = height1;
    }
    void read() {
        cin >> name >> age >> height;
        // height = 0;
    }
    void print() {
        cout << "[" << name << ", " << age << ", " << height << "]";
    }

    // Default operator
    bool operator<( const person& ot ) const {
        // La prioridad de ordenamiento es: name, age, height
        if ( name < ot.name )
            return true;
        // else if ( name == ot.name && age < ot.age )
        //     return true;
        // else if ( name == ot.name && age == ot.age && height < ot.height )
        //     return true;
        return false;
    }
    bool operator==( const person& ot ) const {
        return name == ot.name && age == ot.age && height == ot.height;
    }
};

bool comp1( const person& p1, const person& p2 ) {
    // La prioridad de ordenamiento es: age, name, height
    if ( p1.age < p2.age )
        return true;
    else if ( p1.age == p2.age && p1.name < p2.name )
        return true;
    else if ( p1.age == p2.age && p1.name == p2.name && p1.height < p2.height )
        return true;
    return false;
}

bool comp2( const person& p1, const person& p2 ) {
    // Ordena de manere y por prioridad:
    // No creciente height
    // No creciente age
    // No decreciente name
    if ( p1.height > p2.height )
        return true;
    else if ( p1.height == p2.height && p1.age > p2.age )
        return true;
    else if ( p1.height == p2.height && p1.age == p2.age && p1.name < p2.name )
        return true;
    return false;
}

template< typename T, typename Compare = std::less< T > >
string check( vector< T > input, vector< T > output, Compare compare = {},
              bool stable = false ) {
    if ( input.size() != output.size() ) {
        return "El vector cambio";
    }
    // Verificar que los elementos esten ordenados
    for ( int i = 1; i < output.size(); i++ ) {
        if ( compare( output[i], output[i - 1] ) ) {
            return "No esta ordenado";
        }
    }
    if ( stable ) {
        stable_sort( input.begin(), input.end(), compare );
        if ( input != output ) {
            return "El algoritmo no es estable";
        }
    }
    return "Correcto";
}

template< typename T, typename Compare = std::less< T > >
void call_bubble( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    bubbleSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "BubbleSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;

    // Print the vector
    // for ( auto u: output ) {
    //     u.print();
    //     cout << endl;
    // }
    // cout << endl << endl;
}

template< typename T, typename Compare = std::less< T > >
void call_insertion( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    insertionSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "InsertionSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;
}

template< typename T, typename Compare = std::less< T > >
void call_selection( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    selectionSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "selectionSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;
}

template< typename T, typename Compare = std::less< T > >
void call_merge( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    mergeSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "mergeSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;
}

template< typename T, typename Compare = std::less< T > >
void call_quick( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    quickSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "quickSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;
}

template< typename T, typename Compare = std::less< T > >
void call_heap( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;

    auto start = high_resolution_clock::now();
    heapSort( output.begin(), output.end(), compare );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );

    cout << "InsertionSort: "
         << "Status: " << check( input, output, compare, true )
         << " Takes: " << duration.count() << endl;
}

int main() {
    srand( time( NULL ) );

    int              N;
    vector< person > A, B;

    cin >> N;
    A.resize( N );

    for ( int i = 0; i < N; i++ ) {
        A[i].read();
    }

    B = A;
    call_bubble< person >( B );
    B = A;
    call_insertion( B );
    B = A;
    call_selection( B );
    B = A;
    call_merge( B );
    B = A;
    call_quick( B );
    B = A;
    call_heap( B );
    return 0;
}