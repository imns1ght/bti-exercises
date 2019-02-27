#include <gtest/gtest.h>
#include "../include/bsearch.h"
#include <iterator>

using namespace bs;

TEST(bsearch, basic)
{
    value_type A[] {1, 2, 3, 4, 5, 6, 7};

    for (const auto &e : A) {
        auto result = bsearch(std::begin(A), std::end(A), e);
        EXPECT_EQ(*result, e);
        ASSERT_EQ(e-1, std::distance(std::begin(A), result));
    }
}

TEST(bsearch, no_present_to_left)
{
    value_type A[]{1, 2, 3, 4, 5, 6, 7};

    auto target{-4};
    auto result = bsearch(std::begin(A), std::end(A), target);
    EXPECT_EQ(result, std::end(A));
}

TEST(bsearch, not_present_to_right)
{
    value_type A[]{1, 2, 3, 4, 5, 6, 7};

    auto target{10};
    auto result = bsearch(std::begin(A), std::end(A), target);
    EXPECT_EQ(result, std::end(A));
}

TEST(bsearch, no_present_in_between)
{
    value_type A[]{1, 3, 5, 7, 9, 11};

    for (auto i{2} ; i < 11 ; i+=2)
    {
        auto result = bsearch(std::begin(A), std::end(A), i);
        EXPECT_EQ(result, std::end(A));
    }
}

TEST(bsearch, empty_range)
{
    value_type A[]{1, 3, 5, 7, 9, 11};

    // Let us simulate an empty range here.
    auto first = std::begin(A);
    auto last = std::begin(A);
    auto result = bsearch(first, last, 10);
    EXPECT_EQ(result, last);
}

