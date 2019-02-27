/*!
 * \file searching.cpp
 * \brief Implementing linear and binary search (iterative version).
 * \author Selan, imns1ght
 * \date February, 24th
 */

#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end(), distance()

//=== Alias
using value_type = int ; //!< Simple alias to help code maintenance.

/// Implements an iterative linear seach on an range [first; last) of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
const value_type * lsearch(const value_type *first, const value_type *last, value_type value)
{
	while (first != last) {
		if (*first == value) {
			return first;
		}
		first++;
	}

	return last;
}

/// Implements an interative binary search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer to the last element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
const value_type * bsearch(const value_type *first, const value_type *last, value_type value)
{
	auto distance = std::distance(first, last); /* Current length */

	while (distance > 0) {
		auto offset = distance / 2; // Determine the mid element of the range
		auto m = first + offset; // Mid element pointer

		if (value == *m) {
			return m;
		} else if (value > *m) { // If the element is on the right
			distance -= offset + 1; // Determines the range for one element after mid 
			first = ++m; // Determines the first element for one element after mid
		} else if (value < *m) { // If the element is on the left
			distance = offset; 
		}
	}

	return last; // If the value is not found 
}

// Driver function.
int main()
{
	value_type A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Data container.
	value_type targets[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , -4, 20}; // Target values for testing.

	// Prints out the original data container.
	std::cout << "Array: [ ";
	for (const auto &x : A)
		std::cout << x << " ";
	//std::copy( std::begin(A), std::end(A), std::ostream_iterator<value_type>( std::cout , " " ) );
	std::cout << "]\n";

	// Executes several searchs in the data container.
	for (const auto &e : targets) {
		// Look for target in the entire range.
		auto result = const_cast <value_type *>(bsearch(std::begin(A), std::end(A), e));

		// Process the result
		if (result != std::end(A)) {
			std::cout << ">>> Found \"" << e << "\" at position "
				  << std::distance(std::begin(A),result) << ".\n";
		} else {
			std::cout << ">>> Value \"" << e << "\" was not found in the array!\n";
		}
	}

	return 0;
}
