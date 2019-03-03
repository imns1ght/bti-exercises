#include <gtest/gtest.h>
#include "../include/bsearch.h"
#include <iterator>
#include <algorithm>

using namespace bs;

TEST(lower_bound, empty_range)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 3 };
    auto lb_it = bs::lbound( std::begin(A), std::begin(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::begin(A), value );
    ASSERT_NE( lb_it, nullptr );
    ASSERT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, range_single_value)
{
    bs::value_type A[]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    auto value{ 1 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}


TEST(lower_bound, regular_call_odd)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 3 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, lb_to_the_left_odd)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 2 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}


TEST(lower_bound, lb_to_the_right_odd)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 4 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, lb_at_the_beginning)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 1 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, lb_at_the_end)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 5 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( *lb_it, value );
    ASSERT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, range_single_value_lb_not_present)
{
    bs::value_type A[]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    auto value{ 2 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::find( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    ASSERT_EQ( lb_it, expected_lb_it );
}
TEST(lower_bound, regular_target_outside_to_left_lb_not_present)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ -2 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::begin(A));
    EXPECT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, regular_target_outside_to_right_lb_not_present)
{
    bs::value_type A[]{ 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 };

    auto value{ 8 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::end(A));
    EXPECT_EQ( lb_it, expected_lb_it );
}

TEST(lower_bound, regular_target_outside_in_middle_not_present)
{
    bs::value_type A[]{ 1, 1, 1, 3, 3, 5, 5, 5, 7, 7, 7, 9, 9 };

    auto value{ 2 };
    auto lb_it = bs::lbound( std::begin(A), std::end(A), value );
    auto expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::begin(A)+3 );
    EXPECT_EQ( lb_it, expected_lb_it );

    value = 4 ;
    lb_it = bs::lbound( std::begin(A), std::end(A), value );
    expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::begin(A)+5 );
    EXPECT_EQ( lb_it, expected_lb_it );

    value = 6 ;
    lb_it = bs::lbound( std::begin(A), std::end(A), value );
    expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::begin(A)+8 );
    EXPECT_EQ( lb_it, expected_lb_it );

    value = 8 ;
    lb_it = bs::lbound( std::begin(A), std::end(A), value );
    expected_lb_it = std::lower_bound( std::begin(A), std::end(A), value );
    ASSERT_NE( lb_it, nullptr );
    EXPECT_EQ( lb_it, std::begin(A)+11 );
    EXPECT_EQ( lb_it, expected_lb_it );
}
