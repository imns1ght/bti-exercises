#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each

#include "int_ranges.h"

std::string print( const int* first, const int* last )
{
    std::ostringstream oss;

    oss << "[ ";
    std::for_each(first, last, [&](const int & a){ oss << a << " ";} );
    oss << "]";
    return oss.str();
}

int main (void)
{
    int A[]{1, 2, -3, -4, 5, -6};

    std::cout << ">>> Original A: " << print( std::begin(A), std::end(A) ) << std::endl;

// Nega todo o vetor.
    ir::negate( std::begin(A), std::end(A) );
    std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
// Nega do 3ro at ́e o  ́ultimo elemento do vetor.
    ir::negate( std::begin(A)+2, std::end(A) );
    std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
// Nega apenas o 4to elemento do vetor.
    ir::negate( std::begin(A)+3, std::begin(A)+4 );
    std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

    // TODO: Add other code that uses the functions here.....


    return EXIT_SUCCESS;
}
