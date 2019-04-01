/**
 * Testbed for sorting algorithms.
 * How to compile:  g++ -Wall -std=c++11  sorted_insert.cpp -o io
 */

#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota

// Default array size.
constexpr int ARR_SZ = 10;

// Useful alias
using Compare = bool (*)(const int &, const int&);

// The comparison function (strict total order)
bool compare_ints(const int &a, const int &b)
{
	return (a < b);
}

/*!
 *  Inserts a new element in the range, keeping the range sorted,
 *  and return the new last element in the range.
 *
 *  \note We assume there is enough space in range to insert an extra element.
 *
 *  \param first Iterator to the first element in range.
 *  \param last Iterator to past the last element in range.
 *  \param e The element we wish to insert.
 *  \param cmp The function pointer that compares two elements.
 *  \return An iterator to the new `last` of the range [first;last).
 *
 *  The function inserts a new element `e` in the range [first;last)
 *  in such a way to preserve the current sorting order.
 *  The new range becomes [firstl;last+1).
 *  We assume there is a strict total order relation among the elements
 *  in the range. The strict total order is tested with `cmp(a,b)`, which
 *  return `true` if `a < b`, and false otherwise.
 *
 *  If the elements are not sorted the result is undefined.
 */
int * insert_sorted(int *first, int *last, const int &e, Compare cmp)
{
	auto it(last);

	while ((it > first) && cmp(*it, *(it-1)) && cmp(*(it-1), e)) {
		std::swap(*it, *(it-1));
		it--;
	}

	*it = e;

	return ++last; // Just a stub. Replace it as necessary.
}


/// Prints the elemets of the specified range on the standard output stream.
void print_array(const int * first, const int * last)
{
	std::cout << "    Array: [ ";
	std::copy( first, last, std::ostream_iterator< int >( std::cout, " " ) );
	std::cout << "]\n";
}

int main()
{
	// ================================================================================
	// I. PREPARATION
	// --------------------------------------------------------------------------------

	// Source data array.
	int source[ARR_SZ]; // = {{ 8, 2, 1, 10, 3, 5, 7, 6, 4, 9 } };
	std::iota(std::begin(source), std::end(source), 1);
#ifdef RANDOM
	std::random_device rd;
	std::mt19937 g(rd());
#else
	std::mt19937 g(100);
#endif
	std::shuffle(std::begin(source), std::end(source), g);

	// This is the destination (sorted) array that will receive the input data.
	int destination[ARR_SZ];
	std::fill(std::begin(destination), std::end(destination), 0); // Fill array with zeros.

	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));

	// ================================================================================
	// II. INSERTION
	// --------------------------------------------------------------------------------
	std::cout << ">>> Destination vetor\n";
	print_array( std::begin(destination), std::end(destination) );

	auto last = std::begin(destination);// The last is equal to first, empty array.
	for (const auto &e: source) {
		std::cout << "\n>>> Inserting " << e << std::endl;
		last = insert_sorted(std::begin(destination), last, e, compare_ints);
		print_array(std::begin(destination), last);
	}

	std::cout << "\n>>> Normal ending...\n\n";

	return EXIT_SUCCESS;
}
