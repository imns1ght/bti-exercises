/*!
 * \file filter.cpp
 * \author Selan
 * \date August, 9th
 */

#include "../include/filter.h"

namespace ft {

#ifdef DEBUG
    std::string print ( value_type * first_, value_type * last_ )
    {
        std::ostringstream oss;
        oss << "[ ";
        std::copy( first_, last_, std::ostream_iterator<int>( oss, " " ) );
        oss << "]";

        return oss.str();
    }
#endif

    value_type *  filter_lin( value_type * first_, value_type * last_ )
    {
        auto slow(first_);
        auto fast(first_);
        while( fast != last_ )
        {
#ifdef DEBUG
            std::cout << ">>> Examining element \'" << *fast << "\' in this iteration.\n";
            std::cout << ">>> Internal ranges (before): " << print( first_, slow )
                << print( slow, last_ ) << "\n";
#endif
            if( *fast > 0 )
            {
#ifdef DEBUG
                std::cout <<  "    Element \'" << *fast << "\' accepted, copying to the filtered range.\n";
#endif
                *slow++ = *fast;
            }
#ifdef DEBUG
            else
            {
                std::cout <<  "    Element \'" << *fast << "\' ignored.\n";
            }
#endif
            fast++;
#ifdef DEBUG
            std::cout << ">>> Internal ranges (after): " << print( first_, slow )
                << print( slow, last_ ) << "\n\n";
#endif
        }
        return slow;
    }

    value_type* filter_quad( value_type * first_, value_type * last_ )
    {
        while( first_ != last_ )
        {
            // Whenever we got a negative number we shift the remaining elements
            // one position to the left, overwriting the excluded number.
#ifdef DEBUG
            std::cout << ">>> Looking at " << *first_ << '\n';
#endif
            if ( *first_ <= 0 )
            {
#ifdef DEBUG
                std::cout << ">>> Elimination process started.\n";
#endif
                auto work( first_ );
                while ( work != std::prev(last_) )
                {
#ifdef DEBUG
                    std::cout << "\t>> Copying " << *(work+1) << " over " << *work << ".\n";
#endif
                    *work = *(work+1);
                    work++;
                }
                last_--;
#ifdef DEBUG
                std::cout << ">>> New array: [ ";
                std::copy( first_, last_, std::ostream_iterator<int>( std::cout, " " ) );
                std::cout << "]\n";
#endif
            }
            else
            {
#ifdef DEBUG
                std::cout << ">>> Accept element.\n";
#endif
                first_++; // Advance processing towards the array's end.
            }
        }
        return first_;
    }
}
