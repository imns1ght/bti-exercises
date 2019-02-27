#include "gtest/gtest.h"
#include "../include/filter.h"
#include <iterator>


TEST(FilterLinTest, EmptyRangeInput)
{
    ft::value_type A[]{ 1, 2, 3, 4, 5 };

    auto new_last = ft::filter_lin( std::begin(A), std::begin(A) );
    EXPECT_EQ( new_last, std::begin(A) );
}

TEST(FilterLinTest, AllNegativeInput)
{
    ft::value_type A[]{ -1, -2, -3, -4, -5 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A) );
}

TEST(FilterLinTest, AllZeroInput)
{
    ft::value_type A[]{ 0, 0, 0, 0, 0 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A) );
}

TEST(FilterLinTest, AllNegativeAndZeroInput)
{
    ft::value_type A[]{ 0, 0, -2, -3, -10 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A) );
}

TEST(FilterLinTest, FilterResultOneAtEnd )
{
    ft::value_type A[]{ 0, 0, -2, -3, 10 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A)+1 );
    ASSERT_NE( std::begin(A), nullptr );
    EXPECT_EQ( *std::begin(A), 10 );
}

TEST(FilterLinTest, FilterResultOneAtBegining )
{
    ft::value_type A[]{ 10, 0, -2, -3, -10 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A)+1 );
    ASSERT_NE( std::begin(A), nullptr );
    EXPECT_EQ( *std::begin(A), 10 );
}

TEST(FilterLinTest, FilterResultOneAtMiddle )
{
    ft::value_type A[]{ -1, 0, 10, -3, -10 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A)+1 );
    ASSERT_NE( std::begin(A), nullptr );
    EXPECT_EQ( *std::begin(A), 10 );
}

TEST(FilterLinTest, AllPositiveInput )
{
    ft::value_type A[]{ 1, 10, 2, 3, 20 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::end(A) );
}
TEST(FilterLinTest, IntercalatePositiveAndRejected )
{
    ft::value_type A[]{ 1, -2, 2, -3, 20, 0 };
    ft::value_type R[]{ 1, 2, 20 };

    auto new_last = ft::filter_lin( std::begin(A), std::end(A) );
    EXPECT_EQ( new_last, std::begin(A)+3 );
    auto first( std::begin(A) );
    auto first_result( std::begin(R) );
    while ( first != new_last )
    {
        ASSERT_NE( first, nullptr );
        ASSERT_NE( first_result, nullptr );
        EXPECT_EQ( *first,*first_result );
        first++;
        first_result++;
    }
}
