#include <iostream>
#include <cmath>

// ======================================================================================
// LIBRARY CODE STARTS HERE.
// ======================================================================================

/*
 * The library developer programmer is responsible for the code below.
 * This should be in a select.h header.
 * The implementation should be in a select.cpp source file.
 */
// prototipo do select().
// TODO: your job is to implement this function.
int * select( int * first, int * last, // define o intervalo de entrada
              int * first_d,           // define o local destino para os selecionados
              bool (*pred)(int) );     // ponteiro para função predicado



// ======================================================================================
// CLIENT CODE STARTS HERE.
// ======================================================================================

/*
 * The three predicate functions below are responsability of the client code.
 */

/// Predicate that selects number that can be divided by 3.
bool divided_by_3( int x )
{
    return x % 3 == 0;
}

/// Predicate the selects a number greater than 7.
bool greater_7( int x )
{
	return x > 7;
}

/// Select prime number
bool is_prime( int x )
{
	if ( x == 1 ) return false; // special case.
	auto sqrt_x = sqrt(x);
	for (int i{2} ; i <= sqrt_x ; i++ )
		if ( x % i == 0 ) return false;
	
	return true;
}
		
/// Print out to the standard output the elements in a range.
void print_array( const int *first, const int *last )
{
	std::cout << ">>> Array [ ";
	if ( first == last ) std::cout << "empty ";
	while ( first != last ) std::cout << *first++ << " ";
    std::cout << "]\n";
}

int main( void )
{
	// Input array
    int A[]{ 2, 3, 10, 5, -2, 27, 7 };
    //auto szA = sizeof( A ) / sizeof( A[0] );
	int B[ 7 ]; // output array


    // Print out original A.
	std::cout << ">>> Input array is ";
	print_array( std::begin(A), std::end(A) );
	std::cout << std::endl;

	// ======================================================================================

    // Select the elements accordingly
    auto new_last_B = select( std::begin(A), std::end(A), std::begin(B), divided_by_3 );
	// Print the selection result. Expected { 3, 27 }
	std::cout << ">>> The selected elements are ";
	print_array( std::begin(B), new_last_B );
	std::cout << std::endl;

	// ======================================================================================

	// Apply another selection criterion (predicate).
	auto new_last_B = select( std::begin(A), std::end(A), std::begin(B), is_prime );
	// Print the selection result. Expected { 2, 3, 5, 7 }
	std::cout << ">>> The selected elements are ";
	print_array( std::begin(B), new_last_B );
	std::cout << std::endl;

	
	// ======================================================================================

	// Apply another selection criterion (predicate).
	auto new_last_B = select( std::begin(A), std::end(A), std::begin(B), greater_7 );
	// Print the selection result. Expected { 10, 27 }
	std::cout << ">>> The selected elements are ";
	print_array( std::begin(B), new_last_B );
	std::cout << std::endl;

    return 0;
}