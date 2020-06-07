#include "sorting_library.hpp"

#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

vector< int > input, output;

int N;

int main() {
    cin >> N;
    input.resize( N );
    for ( int i = 0; i < N; i++ ) {
        cin >> input[i];
    }

    // std::sort
    output     = input;
    auto start = high_resolution_clock::now();
    sort( output.begin(), output.end() );
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast< milliseconds >( stop - start );
    cout << "std::sort Takes:\t" << duration.count() << " milliseconds to sort " << N
         << " integers\n";

    // std::stable_sort
    output = input;
    start  = high_resolution_clock::now();
    stable_sort( output.begin(), output.end() );
    stop     = high_resolution_clock::now();
    duration = duration_cast< milliseconds >( stop - start );
    cout << "std::stable_sort Takes:\t" << duration.count() << " milliseconds to sort " << N
         << " integers\n";

    // // bubble
    // output = input;
    // start  = high_resolution_clock::now();
    // bubbleSort( output.begin(), output.end() );
    // stop     = high_resolution_clock::now();
    // duration = duration_cast< milliseconds >( stop - start );
    // cout << "Bubble Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
    //      << " integers\n";

    // // insertion
    // output     = input;
    // start = high_resolution_clock::now();
    // insertionSort( output.begin(), output.end() );
    // stop     = high_resolution_clock::now();
    // duration = duration_cast< milliseconds >( stop - start );
    // cout << "Insertion Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
    //      << " integers\n";

    // // selection
    // output = input;
    // start  = high_resolution_clock::now();
    // selectionSort( output.begin(), output.end() );
    // stop     = high_resolution_clock::now();
    // duration = duration_cast< milliseconds >( stop - start );
    // cout << "Selection Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
    //      << " integers\n";

    // merge
    output = input;
    start  = high_resolution_clock::now();
    mergeSort( output.begin(), output.end() );
    stop     = high_resolution_clock::now();
    duration = duration_cast< milliseconds >( stop - start );
    cout << "Merge Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
         << " integers\n";

    // quick
    output = input;
    start  = high_resolution_clock::now();
    quickSort( output.begin(), output.end() );
    stop     = high_resolution_clock::now();
    duration = duration_cast< milliseconds >( stop - start );
    cout << "Quick Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
         << " integers\n";

    // heap
    output = input;
    start  = high_resolution_clock::now();
    heapSort( output.begin(), output.end() );
    stop     = high_resolution_clock::now();
    duration = duration_cast< milliseconds >( stop - start );
    cout << "Heap Sort Takes:\t" << duration.count() << " milliseconds to sort " << N
         << " integers\n";
}
