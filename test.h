#ifndef TEST_H
#define TEST_H

#include "sorting_library.hpp"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

template< typename T > void print_vector( std::vector< T > v, std::ostream& out ) {
    for ( size_t i = 0; i < v.size(); i++ ) {
        out << v[i];

        if ( i + 1 < v.size() )
            out << " ";
        else
            out << std::endl;
    }
};

template< typename T > class Tests {
  private:
    std::random_device                 rd {};
    std::mt19937                       e1 { rd() }, e2 { rd() };
    std::uniform_int_distribution<>    d1;
    std::uniform_int_distribution< T > d2;

    int nextPosition() {
        return d1( e1 );
    }

    T nextValue() {
        return ( rand() % ( V * 2 + 1 ) ) - V;
        // return d2( e2 );
    }

    void perform_swaps1( std::vector< T >& v, int SWAPS ) {
        while ( SWAPS-- ) {
            int x = nextPosition();
            int y = std::min( x + 1, (int) v.size() - 1 );

            std::swap( v[x], v[y] );
        }
    }

    void perform_swaps2( std::vector< T >& v, int SWAPS ) {
        while ( SWAPS-- ) {
            int x = nextPosition();
            int y = nextPosition();

            std::swap( v[x], v[y] );
        }
    }

    int N, V;

  public:
    Tests( int _N, int _V ): N( _N ), V( _V ) {
        std::uniform_int_distribution<>    x { 0, N - 1 };
        std::uniform_int_distribution< T > y { 0, V - 1 };

        d1 = std::move( x );
        d2 = std::move( y );
    }

    std::vector< T > random_order() {
        std::vector< T > v;
        v.resize( N );

        for ( T& x: v )
            x = nextValue();

        return v;
    }

    std::vector< T > sorted_ascending() {
        std::vector< T > v = random_order();
        std::sort( v.begin(), v.end() );

        return v;
    }

    std::vector< T > sorted_decreasing() {
        std::vector< T > v = random_order();
        std::sort( v.begin(), v.end() );
        std::reverse( v.begin(), v.end() );

        return v;
    }

    std::vector< T > mostly_sorted1_asc( int SWAPS ) {
        std::vector< T > v = sorted_ascending();
        perform_swaps1( v, SWAPS );

        return v;
    }

    std::vector< T > mostly_sorted2_asc( int SWAPS ) {
        std::vector< T > v = sorted_ascending();
        perform_swaps2( v, SWAPS );

        return v;
    }

    std::vector< T > mostly_sorted1_desc( int SWAPS ) {
        std::vector< T > v = sorted_decreasing();
        perform_swaps1( v, SWAPS );

        return v;
    }

    std::vector< T > mostly_sorted2_desc( int SWAPS ) {
        std::vector< T > v = sorted_decreasing();
        perform_swaps2( v, SWAPS );

        return v;
    }
};

template< typename T > auto get_time_bubble( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    bubbleSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_selection( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    selectionSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_insertion( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    insertionSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_merge( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    mergeSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_quick( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    quickSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_heap( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    heapSort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T > auto get_time_std_sort( std::vector< T > v ) {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    std::sort( v.begin(), v.end() );
    assert( std::is_sorted( v.begin(), v.end() ) );

    std::chrono::high_resolution_clock ::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

    return item;
}

template< typename T >
void call_sorting_algorithms(
    std::vector< T >& v, std::vector< std::vector< unsigned long long > >& times_bubble,
    std::vector< std::vector< unsigned long long > >& times_insertion,
    std::vector< std::vector< unsigned long long > >& times_selection,
    std::vector< std::vector< unsigned long long > >& times_merge,
    std::vector< std::vector< unsigned long long > >& times_quick,
    std::vector< std::vector< unsigned long long > >& times_heap,
    std::vector< std::vector< unsigned long long > >& times_sort, int p ) {

    if ( v.size() <= 100'000 ) { // Slow algorithms
        times_bubble[p].push_back( get_time_bubble( v ) );
        times_insertion[p].push_back( get_time_insertion( v ) );
        times_selection[p].push_back( get_time_selection( v ) );
    }
    times_merge[p].push_back( get_time_merge( v ) );
    times_quick[p].push_back( get_time_quick( v ) );
    times_heap[p].push_back( get_time_heap( v ) );
    times_sort[p].push_back( get_time_std_sort( v ) );
}

template< typename T >
void test( int N, int V, std::vector< std::vector< unsigned long long > >& times_bubble,
           std::vector< std::vector< unsigned long long > >& times_insertion,
           std::vector< std::vector< unsigned long long > >& times_selection,
           std::vector< std::vector< unsigned long long > >& times_merge,
           std::vector< std::vector< unsigned long long > >& times_quick,
           std::vector< std::vector< unsigned long long > >& times_heap,
           std::vector< std::vector< unsigned long long > >& times_sort ) {

    assert( times_bubble.size() == 7 );
    assert( times_insertion.size() == 7 );
    assert( times_selection.size() == 7 );
    assert( times_merge.size() == 7 );
    assert( times_quick.size() == 7 );
    assert( times_heap.size() == 7 );
    assert( times_sort.size() == 7 );
    Tests< T > tests { N, V };

    auto v = tests.random_order();
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 0 );

    v = tests.sorted_ascending();
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 1 );

    v = tests.sorted_decreasing();
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 2 );

    v = tests.mostly_sorted1_asc( 2 * ( N / 10 ) );
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 3 );

    v = tests.mostly_sorted1_desc( 2 * ( N / 10 ) );
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 4 );

    v = tests.mostly_sorted2_asc( 2 * ( N / 10 ) );
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 5 );

    v = tests.mostly_sorted2_desc( 2 * ( N / 10 ) );
    call_sorting_algorithms( v, times_bubble, times_insertion, times_selection, times_merge,
                             times_quick, times_heap, times_sort, 6 );
}

template< typename T > double average( std::vector< T > v ) {
    auto sum = std::accumulate( v.begin(), v.end(), 0 );
    return static_cast< double >( sum ) / v.size();
}

void gen_data() {
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    std::vector< std::pair< int, int > > pairs( 14 );
    // pairs[0] = { 100, 100 };
    // pairs[1] = { 1'000, 500 };
    // pairs[2] = { 10'000, 2'000 };
    // pairs[3] = { 100'000, 15'000 };
    // pairs[4] = { 1'000'000, 40'000 };
    // pairs[5] = { 5'000'000, 80'000 };
    // pairs[6] = { 10'000'000, 125'000 };
    pairs[0] = pairs[1] = pairs[2] = pairs[3] = pairs[4] = pairs[5] = pairs[6] = { 0, 0 };

    pairs[7]  = { 100, 2'000'000'000 };
    pairs[8]  = { 1'000, 2'000'000'000 };
    pairs[9]  = { 10'000, 2'000'000'000 };
    pairs[10] = { 100'000, 2'000'000'000 };
    pairs[11] = { 1'000'000, 2'000'000'000 };
    pairs[12] = { 5'000'000, 2'000'000'000 };
    pairs[13] = { 10'000'000, 2'000'000'000 };

    std::ofstream out( "results.txt" );
    out << "bubbleSort\n"
        << "insertionSort\n"
        << "selectionSort\n"
        << "mergeSort\n"
        << "quickSort\n"
        << "heapSort\n"
        << "std::sort\n"
        << "\n\n\n";

    out << "test1: Random Order\n"
        << "test2: Sorted Ascending\n"
        << "test3: Sorted Decreasing\n"
        << "test4: Sorted Ascendign with 20% of adjacent swaps\n"
        << "test5: Sorted Decreasing with 20% of adjacent swaps\n"
        << "test6: Sorted Ascendign with 20% of random swaps\n"
        << "test7: Sorted Decreasing with 20% of random swaps\n"
        << "\n\n\n";

    for ( int i = 0; i < 14; i++ ) {
        const std::string str = "data" + std::to_string( i );
        out << str << std::endl;
        std::cerr << str << std::endl;

        int N = pairs[i].first;
        int V = pairs[i].second;

        out << N << " " << V << std::endl;

        std::vector< std::vector< unsigned long long > > times_bubble( 7 ),
            times_insertion( 7 ), times_selection( 7 ), times_merge( 7 ), times_quick( 7 ),
            times_heap( 7 ), times_sort( 7 );

        int ITERATIONS = 3;

        while ( ITERATIONS-- ) {
            test< int >( N, V, times_bubble, times_insertion, times_selection, times_merge,
                         times_quick, times_heap, times_sort );
        }

        for ( int i = 0; i < 7; i++ ) {
            out << std::fixed << std::setprecision( 2 );
            out << average( times_bubble[i] ) << '\t' << average( times_insertion[i] ) << '\t'
                << average( times_selection[i] ) << '\t' << average( times_merge[i] ) << '\t'
                << average( times_quick[i] ) << '\t' << average( times_heap[i] ) << '\t'
                << average( times_sort[i] ) << std::endl;
        }

        out << std::endl;
    }

    out.close();
    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();
    auto item = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();
    std::cout << "Total time: " << item / ( 1000 * 60 ) << '\n';
}

#endif // TEST_H