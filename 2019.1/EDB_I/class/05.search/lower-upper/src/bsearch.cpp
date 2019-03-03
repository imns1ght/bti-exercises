/*!
 * Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date August, 8th.
 */

#include "../include/bsearch.h"

namespace bs {

/// Returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e. greater or equal to) value, or last if no such element is found.
bs::value_type * lbound( bs::value_type * first, bs::value_type * last, bs::value_type value )
{
	auto distance = std::distance(first, last); // Current length

 	while (distance > 0) {
    		auto offset = distance / 2; // Determine the mid element of the range
		auto m = first + offset; // Pointer for the element located in mid
    		
		if (value > *m) { // If the element is on the right
      			distance -= offset + 1; // Determines the range for one element after mid 
			first = ++m; // Determines the first element for one element after mid
    		} else {
			distance = offset;
  		}	
	}

	return first; // stub, not valid.
}

/// Returns an iterator pointing to the first element in the range [first, last) that is *greater* than value, or last if no such element is found.
bs::value_type * ubound( bs::value_type * first, bs::value_type * last, bs::value_type value )
{
	auto distance = std::distance(first, last); // Current length

 	while (distance > 0) {
    		auto offset = distance / 2; // Determine the mid element of the range
		auto m = first + offset; // Pointer for the element located in mid
    		
		if (value >= *m) { // If the element is not less than value
      			distance -= offset + 1; // Determines the range for one element after mid 
			first = ++m; // Determines the first element for one element after mid
    		} else {
			distance = offset;
  		}	
	}

	return first; // stub, not valid.
}

/// Implements an interative binary search on an array of integers.
/*!
 * \param first Pointer to the first element in the range.
 * \param last Pointer past the last valid element in the range.
 * \param value The target value we are looking for within the range.
 * \return A pointer to the target value within the range; or last, in case the value is not in the range.
 */
bs::value_type * bsearch( bs::value_type * first, bs::value_type * last, bs::value_type value )
{
	auto distance = std::distance(first, last); // Current length

	while (distance > 0) {
		auto offset = distance / 2; // Determine the mid element of the range
		auto m = first + offset; // Pointer for the element located in mid

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

}
