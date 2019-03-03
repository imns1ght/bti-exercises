/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + upper bound
 *  + lower bound
 *  + binary search
 *
 * \author Selan R. dos Santos
 * \date August, 8th.
 */

#ifndef BSEARCH_H
#define BSEARCH_H

#include <iterator>

#include <gtest/gtest.h>

namespace bs { 

    // just an alias
    using value_type = int;

    value_type * lbound( value_type * first, value_type * last, value_type value );
    value_type * ubound( value_type * first, value_type * last, value_type value );
    value_type * bsearch( value_type * first, value_type * last, value_type value );
} 

#endif
