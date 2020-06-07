#include "sorting_library.hpp"

#include <bits/stdc++.h>
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
    }
    void print() {
        cout << "[" << name << ", " << age << ", " << height << "]";
    }

    // Default operator
    bool operator<( const person& ot ) const {
        // La prioridad de ordenamiento es: name, age, height
        if ( name < ot.name )
            return true;
        else if ( name == ot.name && age < ot.age )
            return true;
        else if ( name == ot.name && age == ot.age && height < ot.height )
            return true;
        return false;
    }
    // bool operator==( const person& ot ) const {
    //     return false;
    // }
};

bool comp1( person& p1, person& p2 ) {
    // La prioridad de ordenamiento es: age, name, height
    if ( p1.age < p2.age )
        return true;
    else if ( p1.age == p2.age && p1.name < p2.name )
        return true;
    else if ( p1.age == p2.age && p1.name == p2.name && p1.height < p2.height )
        return true;
    return false;
}

bool comp2( person& p1, person& p2 ) {
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
bool check( vector< T > input, vector< T > output, Compare compare = {},
            bool stable = false ) {
    if ( input.size() != output.size() ) {
        cout << "nel1\n";
        return false;
    }
    // Verificar que los elementos esten ordenados
    for ( int i = 1; i < output.size(); i++ ) {
        if ( compare( output[i], output[i - 1] ) ) {
            cout << "nel2\n";
            return false;
        }
    }
    // if ( stable ) {
    //     stable_sort( input.begin(), input.end(), compare );
    //     cout << "stable begin:\n";
    //     for ( auto u: output ) {
    //         u.print();
    //         cout << endl;
    //     }
    //     cout << "Estable end:\n";
    //     if ( input != output ) {
    //         cout << "nel3\n";
    //         return false;
    //     }
    // }
    return true;
}

template< typename T, typename Compare = std::less< T > >
void call_bubble( vector< T > input, Compare compare = {} ) {
    vector< T > output;
    output = input;
    bubbleSort( output.begin(), output.end(), compare );
    cout << "BubbleSort: " << check( input, output, compare, true ) << endl;

    // for ( auto u: output ) {
    //     u.print();
    //     cout << endl;
    // }
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
    // B = A;
    // call_insertion( B );
    // B = A;
    // call_selection( B );
    // B = A;
    // call_merge( B );
    // B = A;
    // call_quick( B );
    // B = A;
    // call_heap( B );
    return 0;
}