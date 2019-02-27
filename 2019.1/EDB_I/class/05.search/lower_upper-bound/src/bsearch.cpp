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
        // TODO: Insert here your solution for the lower bound problem.

        return first; // stub, not valid.
    }


    /// Returns an iterator pointing to the first element in the range [first, last) that is *greater* than value, or last if no such element is found.
    bs::value_type * ubound( bs::value_type * first, bs::value_type * last, bs::value_type value )
    {
        // TODO: Insert here your solution for the lower bound problem.

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
        // determine current length
        auto count = std::distance( first, last );

        // Keep searching and halving the range until we get to an empty range.
        while ( count > 0 )
        {
            auto step = count/2; // Determine the offset to get the midpoint element in the current range.
            auto m{ first }; // An aux iterator that points to the element located at the midpoint.
            std::advance( m, step ); // Position `m` at the midpoint location.

            // Equality test
            if ( not ( value < *m ) and not ( *m < value ) )
            {
                return m;
            }
            else if ( *m < value ) // go right
            {
                count -= (step+1); // Remove the quantity of elements to get to the midpoint + the midpoint itself.
                first = ++m; // Update the first to its new location, just past the "old" midpoint.
            }
            else // look into the left half.
            {
                count = step;
            }
        }

        return  last;
    }
}

