#include "../include/int_ranges.h"

namespace ir {
    void negate( value_type * first, value_type * last )
    {
        while(first != last) {
            *first++ *= -1;
        }
    }

    const value_type * min(const value_type* first, const value_type* last)
    {
        auto min_value = first;

        while(first != last) {
            if (*min_value > *first) {
                min_value = first;
            }
            first++;
        }

        return min_value;
    }

    value_type * copy( const value_type * first_, const value_type *last_, value_type *d_first_ )
    {
        // TODO: place your code solution here!
        return nullptr;
    }

    void reverse( value_type *first, value_type*last )
    {
        
    }

    value_type * rotate( value_type *first, value_type *n_first, value_type *last )
    {
        // TODO: place your code solution here!
        return nullptr;
    }

    // TODO: Place the rest of the implementation here.


}
