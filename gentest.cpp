#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
using namespace std;

#define pb       push_back
#define mp       make_pair
#define all( x ) ( x ).begin(), ( x ).end()
#define fi       first
#define se       second
#define SZ( x )  ( (int) ( x ).size() )

typedef long long        INT;
typedef double           db;
typedef pair< int, int > pii;

const int mod = 101;

const string numbers = "0123456789";
// const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Modificar
const int sz_int  = 1;
const int sz_long = 1;
const int sz_name = 1;

string get_int() {
    string ret = "";
    int    rnd;
    for ( int i = 0; i < sz_int; i++ ) {
        rnd = rand() % numbers.size();
        ret += numbers[rnd];
    }
    return ret;
}
string get_long() {
    string ret = "";
    int    rnd;
    for ( int i = 0; i < sz_long; i++ ) {
        rnd = rand() % numbers.size();
        ret += numbers[rnd];
    }
    return ret;
}
string get_float() {
    string ret = "";

    ret = get_int() + "." + get_int();
    return ret;
}
string get_name() {
    string ret = "";
    int    rnd;
    for ( int i = 0; i < sz_name; i++ ) {
        rnd = rand() % letters.size();
        ret += letters[rnd];
    }
    return ret;
}

string get_random( int tp ) {
    string a = get_int();
    string b = get_long();
    string c = get_float();
    string d = get_name();

    string ret = "";
    switch ( tp ) {
        case 1: ret = a + '\n'; break;
        case 2: ret = b + '\n'; break;
        case 3: ret += c + '\n'; break;
        case 4: ret += d + '\n' + a + '\n' + c + '\n'; break;
        default: break;
    }
    return ret;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    srand( time( NULL ) );

    int N, op1, op2;

    cout << "Ingrese el tamaño de elementos: ";
    cin >> N;

    do {
        cout << "Ingrese el tipo de dato:\n";
        cout << "1. int\n";
        cout << "2. long long\n";
        cout << "3. float\n";
        cout << "4. persona\n";
        cout << "opcion: ";
        cin >> op1;
    } while ( op1 < 1 || op1 > 4 );

    ofstream myfile;
    myfile.open( "A.in" );
    myfile << N << endl << endl;

    string element;
    for ( int i = 0; i < N; i++ ) {
        element = get_random( op1 );
        myfile << element << '\n';
    }

    myfile.close();

    return 0;
}