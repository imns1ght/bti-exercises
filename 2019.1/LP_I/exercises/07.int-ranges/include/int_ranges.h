#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iostream>
#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
	using value_type = int;

	/// Negate all integer values in [first;last).
	void negate( value_type * first, value_type * last );

	/// Returns a pointer to the first occurrency of the smallest element the range.
	const value_type * min( const value_type *, const value_type * );

	/// Reverse the order of the elements in range `[first;last)`.
	void reverse(value_type *first, value_type*last);
	
	/// Multiplies an integer passed by parameter by all elements in the range [first, last].
	void scalar_multiplication(value_type * first, value_type * last , value_type scalar);

	/// Returns the scalar product of the sub-arrays
	value_type dot_product(const value_type * a_first , const value_type * a_last , const value_type * b_first);

	/// Discard all the negative numbers and nulls.
	value_type * compact(value_type *first, value_type *last);

	/// Copy the content of the range `[first;last)` to another range beginning at `d_first`.
    	value_type * copy(const value_type *first, const value_type *last, value_type *d_first);

	/// Eliminates repeats of elements in range [first, last)
    	value_type * unique(value_type *first, value_type *last);

	/// Rearrange the elements of the range using only the swap operation (std :: swap)
    	value_type * sort_marbles(value_type *first, value_type *last);

	/// Rearrange the elements of the range using only a value "pivot"
	void partition(value_type *first, value_type *last, value_type *pivot);

    	/// Rotate elements in range.
    	void rotate(value_type *first, value_type *n_first, value_type *last);

	/// Auxiliary function to check if two array are equal
	bool equalArrays(const value_type A[], const value_type A_E[], std::size_t n);
}

#endif
