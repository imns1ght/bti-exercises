/*!
 * Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date August, 8th.
 */
#include <iostream>
#include <algorithm>
#include <iterator>

#include "../include/bsearch.h"

using namespace bs;

std::string print( bs::value_type *first, bs::value_type *last )
{
    std::ostringstream oss;
    std::copy( first, last, std::ostream_iterator< bs::value_type > ( oss, " " ) );
    return oss.str();
}

int main(void)
{
    bs::value_type A1[]{ 1, 2, 3, 3, 3, 4, 5 };
    bs::value_type A2[]{ 1, 3, 3, 4, 4, 4, 5 };
    bs::value_type A3[]{ 1, 1, 2, 2, 3, 3, 4 };
    bs::value_type A4[]{ 1, 2, 3, 4, 5, 6, 7 };

    auto value{ 3 };
    auto lb1 = lbound( std::begin(A1), std::end(A1), value );
    auto ub1 = ubound( std::begin(A1), std::end(A1), value );
    std::cout << ">>> A1[ " << print( std::begin(A1), std::end(A1) ) << "]\n";
    std::cout << "    First instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A1), lb1 ) << std::endl;
    std::cout << "    Just past the last instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A1), ub1 ) << std::endl;

    auto lb2 = lbound( std::begin(A2), std::end(A2), value );
    auto ub2 = ubound( std::begin(A2), std::end(A2), value );
    std::cout << ">>> A2[ " << print( std::begin(A2), std::end(A2) ) << "]\n";
    std::cout << "    First instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A2), lb2 ) << std::endl;
    std::cout << "    Just past the last instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A2), ub2 ) << std::endl;

    auto lb3 = lbound( std::begin(A3), std::end(A3), value );
    auto ub3 = ubound( std::begin(A3), std::end(A3), value );
    std::cout << ">>> A3[ " << print( std::begin(A3), std::end(A3) ) << "]\n";
    std::cout << "    First instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A3), lb3 ) << std::endl;
    std::cout << "    Just past the last instance of \'"<< value << "\' found at position " << std::distance ( std::begin(A3), ub3 ) << std::endl;

    std::cout << ">>> A4[ " << print( std::begin(A4), std::end(A4) ) << "]\n";
    for ( auto i(0u) ; i <= (sizeof(A4)/sizeof(A4[0]))+1 ; ++i )
    {
        std::cout << ">>> Looking for value \'" << i << "\' in A4: ";
        auto result = bsearch( std::begin(A4), std::end(A4), i );
        ( result == std::end(A4) ) ?
            std::cout << "Search failed!\n" :
            std::cout << "Located target element at position " << std::distance( std::begin(A4), result ) << std::endl;
    }

    return 0;
}
