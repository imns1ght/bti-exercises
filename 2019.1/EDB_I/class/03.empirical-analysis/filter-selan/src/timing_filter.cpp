#include <iostream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>
#include <iterator>

#include "../include/filter.h"

#define N 20 // Default number of elements to filter

//Fill a vector with random numbers in the range [lower, upper]
void randomFill( std::vector<int> &V, const int lower, const int upper, const unsigned int seed)
{
    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    // Fill up vector
    for( auto &elem : V)
        elem = distr(eng);
}


int main( int argc, char * argv[] )
{
    auto arr_sz( 0ul );

    std::cout << ">>> Welcome! This program runs and times the filter <<<\n"
              << ">>> algorithm applied to an array of integers.      <<<\n\n";

    // Process input arguments
    if ( argc > 1 ) // More thant 1 argument means we have input size.
    {
        // Let us try to convert user input into an integer.
        std::istringstream iss( argv[1] );
        iss >> arr_sz;
        if ( iss.fail() or not iss.eof() )
        {
            std::cout << ">>> Problems with the argument, assuming array length = " << N << std::endl;
            arr_sz = N;
        }
    }
    else
    {
        arr_sz = N;
    }
    std::cout << ">>> The required array size is: " << arr_sz << std::endl;

    // Store the data.
    std::vector< int > V( arr_sz );

    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    // List the options
#define AVERAGE 1
#define WORST 2
#define BEST 3

    // Default to average case.
#ifndef CASE
#define CASE AVERAGE
#endif

    // Decide which case to compile
#if CASE==AVERAGE
    std::cout << ">>> Running AVERAGE case...\n\n";
    randomFill( V, -100, 100, r() ); // average case.
#elif CASE==WORST
    std::cout << ">>> Running WORST case...\n\n";
    randomFill( V, -100, 0, r() ); // worst case
#elif CASE==BEST
    std::cout << ">>> Running BEST case...\n\n";
    randomFill( V, 1, 100, r() );  // best case
#endif

#ifdef PRINT
    // Printing out the array, just to make sure we've got random integers.
    std::cout << ">>> ORIGINAL Vet = [ ";
    std::copy( V.begin(), V.end(), std::ostream_iterator<int>( std::cout, " " ) );
    std::cout << "], Size = " << arr_sz << "\n";
#endif


    std::cout << ">>> STARTING computation that needs timing <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================
#define QUAD 1
#define LIN 2

#ifndef ALGO
#define ALGO QUAD
#endif

#if ALGO==QUAD
    std::cout << ">>> QUADRATIC...\n\n";
    #ifdef PRINT
    auto new_end = ft::filter_quad( &V[0], &V[V.size()] );//.begin(), V.end() );
    #else
    ft::filter_quad( &V[0], &V[V.size()] );//.begin(), V.end() );
    #endif
#elif ALGO==LIN
    std::cout << ">>> LINEAR...\n\n";
    auto new_end = ft::filter_lin( &V[0], &V[V.size()] );
#else
    std::cout << ">>> Unknow algorithm option provided, runing the QUADRATIC version...\n";
    auto new_end = ft::filter_quad( &V[0], &V[V.size()] );
#endif

    //================================================================================
    auto end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    //Store the time difference between start and end
    auto diff = end - start;

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
        << " ns" << std::endl;

    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

#ifdef PRINT
    // Printing compacted array.
    std::cout << ">>> Vet FILTERED = [ ";
    std::copy( &V[0], new_end, std::ostream_iterator<int>( std::cout, " " ) );
    std::cout << "], Size = " <<  std::distance( &V[0], new_end ) << "\n";
#endif


    return EXIT_SUCCESS;

}
