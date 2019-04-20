#include <iterator> // std::begin(), std::end()

#include "../include/graal.h" // header file for tested functions
#include "gtest/gtest.h"      // gtest lib
#include <algorithm>          // std::min_element
#include <functional>         // std::function

using namespace graal;

// ============================================================================
//                                                     Tests for integer arrays
// ============================================================================

/* Predicate function for int */
bool INT_bigg_than(const void *c) {
        const int *c_c = static_cast<const int *>(c);
        return *c_c > 1;
};

/* Equality function for int */
bool INT_equal_to(const void *a, const void *b) {
        const int *a_ = static_cast<const int *>(a);
        const int *b_ = static_cast<const int *>(b);

        return *a_ == *b_;
};

/* Boolean sort for int */
bool INT_sort_comp(const void *a, const void *b) {
        const int *m_a = static_cast<const int *>(a);
        const int *m_b = static_cast<const int *>(b);

        return *m_a < *m_b;
}

// IntRange -> min() tests {{{
TEST(IntRange, MinBasic) {
        int A[]{1, 2, -3, 4, 0};

        auto result = (const int *)graal::min(std::begin(A), std::end(A), sizeof(int),
                                              [](const void *a, const void *b) {
                                                      return *(static_cast<const int *>(a)) < *(static_cast<const int *>(b));
                                              });

        ASSERT_EQ(result, std::begin(A) + 2);
}

TEST(IntRange, MinFirstOcurrence) {
        int A[]{1, 1, 1, 1, 1};

        auto result = (const int *)graal::min(std::begin(A), std::end(A), sizeof(int),
                                              [](const void *a, const void *b) {
                                                      return *(static_cast<const int *>(a)) < *(static_cast<const int *>(b));
                                              });
        ASSERT_EQ(result, std::begin(A));
}

// IntRange -> reverse() tests {{{
TEST(IntRange, ReverseEntireArrayEven) {
        int A[]{1, 2, 3, 4, 5, 6};
        int result[]{6, 5, 4, 3, 2, 1};

        graal::reverse(std::begin(A), std::end(A), sizeof(A[0]));

        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(result)));
}

TEST(IntRange, ReverseEntireArrayOdd) {
        int A[]{1, 2, 3, 4, 5};
        int A_E[]{5, 4, 3, 2, 1};

        graal::reverse(std::begin(A), std::end(A), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, ReversePartOfArrayEven) {
        int A[]{1, 2, 3, 4, 5, 6, 7};
        int A_E[]{1, 2, 6, 5, 4, 3, 7};

        graal::reverse(std::begin(A) + 2, std::begin(A) + 6, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, ReversePartOfArrayOdd) {
        int A[]{1, 2, 3, 4, 5, 6, 7};
        int A_E[]{1, 6, 5, 4, 3, 2, 7};

        graal::reverse(std::begin(A) + 1, std::begin(A) + 6, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

// IntRange -> copy() tests {{{
TEST(IntRange, CopyEntireArray) {
        int A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        int A_E[]{'a', 'a', 'a', 'a', 'a', 'a', 'a'};

        graal::copy(std::begin(A), std::end(A), std::begin(A_E), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, CopyPartOfArray) {
        int A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        int A_E[]{'a', 'b', 'a', 'a', 'a', 'a', 'a'};

        graal::copy(std::begin(A) + 2, std::end(A), std::begin(A_E) + 2, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, CopyFinalOfArray) {
        int A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        int A_E[]{'a', 'b', 'c', 'd', 'e', 'b', 'a'};

        graal::copy(std::begin(A) + 5, std::end(A), std::begin(A_E) + 5, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, CopyUnaryArray) {
        int A[]{'a'};
        int A_E[]{'x'};

        graal::copy(std::begin(A), std::end(A), std::begin(A_E), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

//}}}
// IntRange -> clone() tests {{{
TEST(IntRange, CloneEntireArray) {
        int A[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int *result = static_cast<int *>(graal::clone(std::begin(A), std::end(A), sizeof(A[0])));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), result));
        delete[] result;
}

TEST(IntRange, ClonePartOfArray) {
        int A[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        int *result = static_cast<int *>(graal::clone(std::begin(A) + 3, std::end(A), sizeof(A[0])));
        ASSERT_TRUE(std::equal(std::begin(A) + 3, std::end(A), result));
        delete[] result;
}

//}}}
// IntRange -> find_if() tests {{{
TEST(IntRange, FindIfLotsAreBiggerThan) {
        int A[]{-10, -3, -4, 5, 7, 4};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), INT_bigg_than);
        ASSERT_EQ(std::begin(A) + 3, result);
}

TEST(IntRange, FindIfOneIsBiggerThan) {
        int A[]{1, 1, 1, 2, 1};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), INT_bigg_than);
        ASSERT_EQ(std::begin(A) + 3, result);
}
TEST(IntRange, FindIfNoneIsBiggerThan) {
        int A[]{1, 1, 1, 1};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), INT_bigg_than);
        ASSERT_EQ(std::end(A), result);
}

//}}}
// IntRange -> find() tests {{{
TEST(IntRange, FindLotsAreEqual) {
        int A[]{'a', 'b', 'k', 'k', 'k'};
        int A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), INT_equal_to);
        ASSERT_EQ(std::begin(A) + 2, result);
}

TEST(IntRange, FindThereIsOneEqual) {
        int A[]{'b', 'a', 'q', 'l', 'k'};
        int A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), INT_equal_to);
        ASSERT_EQ(std::begin(A) + 4, result);
}

TEST(IntRange, FindNoneIsEqual) {
        int A[]{'a', 'b', 'c', 'd', 'e'};
        int A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), INT_equal_to);
        ASSERT_EQ(std::end(A), result);
}

//}}}
// IntRange -> all_of() tests {{{
TEST(IntRange, AllOfAreBiggerThan) {
        int A[]{10, 20, 30, 40, 50, 2, 80};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), INT_bigg_than);
        ASSERT_TRUE(result);
}

TEST(IntRange, AllOfAreNotBiggerThan) {
        int A[]{10, 20, 1, 30, 40, 80, 1};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), INT_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// IntRange -> any_of() tests {{{
TEST(IntRange, AnyOfAreBiggerThan) {
        int A[]{1, -10, -20, -30, 2, 1, 1};
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), INT_bigg_than);
        ASSERT_TRUE(result);
}

TEST(IntRange, AnyOfAreNotBiggerThan) {
        int A[]{1, 1, 1, 1, 1, 1, 1};
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), INT_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// IntRange -> none_of() tests {{{
TEST(IntRange, NoneOfAreBiggerThan) {
        int A[]{1, 1, 1, 1, 1, 1, 1};
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), INT_bigg_than);
        ASSERT_TRUE(result);
}

TEST(IntRange, NoneOfAreNotBiggerThan) {
        int A[]{1, 1, 1, 1, 10, 1, 1, 1, 1};
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), INT_bigg_than);
        ASSERT_FALSE(result);
}

//}}}
// IntRange -> type1 equal() tests {{{
TEST(IntRange, AllAreEqualType1) {
        int A[]{'a', 'b', 'c', 'd'};
        int A_E[]{'a', 'b', 'c', 'd'};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              INT_equal_to);
        ASSERT_TRUE(result);
}

TEST(IntRange, AllAreNotEqualType1) {
        int A[]{'a', 'b', 'c', 'd'};
        int A_E[]{'a', 'f', 'c', 'd'};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              INT_equal_to);
        ASSERT_FALSE(result);
}

TEST(IntRange, PartAreEqualType1) {
        int A[]{'a', 'c', 'b', 'd', 'g'};
        int A_E[]{'l', 'c', 'b', 'd', 'a'};

        bool result;
        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              INT_equal_to);
        ASSERT_TRUE(result);
}

TEST(IntRange, PartAreNotEqualType1) {
        int A[]{'a', 'c', 'b', 'd', 'g'};
        int A_E[]{'l', 'c', 'a', 'd', 'p'};

        bool result;
        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              INT_equal_to);
        ASSERT_FALSE(result);
}
//}}}
// IntRange -> type2 equal() tests {{{
TEST(IntRange, AllAreEqualType2) {
        int A[]{'a', 'c', 'b', 'd', 'g'};
        int A_E[]{'a', 'c', 'b', 'd', 'g'};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              INT_equal_to);
        ASSERT_TRUE(result);
}

TEST(IntRange, AllAreNotEqualType2) {
        int A[]{'a', 'c', 'b', 'd', 'g'};
        int A_E[]{'a', 'h', 'b', 'd', 'g'};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              INT_equal_to);
        ASSERT_FALSE(result);
}

TEST(IntRange, PartAreEqualType2) {
        int A[]{'a', 'c', 'b', 'd', 'e', 'g'};
        int A_E[]{'l', 'c', 'b', 'd', 'e', 'h'};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              INT_equal_to);
        ASSERT_TRUE(result);
}

TEST(IntRange, PartAreNotEqualType2) {
        int A[]{'a', 'c', 'b', 'd', 'e', 'g'};
        int A_E[]{'l', 'c', 'b', 'd', 'f', 'h'};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              INT_equal_to);
        ASSERT_FALSE(result);
}

//}}}
// IntRange -> unique() tests {{{
TEST(IntRange, UniqueAllAre) {
        int A[]{1, 10, 11, 20, 21, 30, 31};
        int A_E[]{1, 10, 11, 20, 21, 30, 31};

        int *result;
        result = static_cast<int *>(graal::unique(std::begin(A), std::end(A), sizeof(A[0]), INT_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, UniqueManyAre) {
        int A[]{1, 2, 5, 4, 5, 3, 3};
        int A_E[]{1, 2, 5, 4, 3};

        int *result;
        result = static_cast<int *>(graal::unique(std::begin(A), std::end(A), sizeof(A[0]), INT_equal_to));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, UniqueOneIs) {
        int A[]{1, 5, 3, 3, 5, 10, 1};
        int A_E[]{1, 5, 3, 10};

        int *result;
        result = static_cast<int *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                INT_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, UniqueNoneIs) {
        int A[]{1, 2, 5, 2, 5, 1, 9, 9, 5, 2};
        int A_E[]{1, 2, 5, 9};

        int *result;
        result = static_cast<int *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                INT_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

//}}}
// IntRange -> partition() tests {{{
TEST(IntRange, PartitionAllAreTrue) {
        int A[]{2, 3, 4, 5, 6, 7};
        int A_E[]{2, 3, 4, 5, 6, 7};

        int *result;
        result = static_cast<int *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), INT_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, PartitionSomeAreTrue) {
        int A[]{1, 2, 3, 5, 1, 4};
        int A_E[]{2, 3, 5, 4};

        int *result;
        result = static_cast<int *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), INT_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, PartitionOneIsTrue) {
        int A[]{1, 1, 1, 1, 1, 1, 5};
        int A_E[]{5};

        int *result;
        result = static_cast<int *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), INT_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(IntRange, PartitionNoneIsTrue) {
        int A[]{1, 1, 0, 1, 0, 1, 1};
        int A_E[]{NULL};

        int *result;
        result = static_cast<int *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), INT_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

//}}}
// IntRange -> sort() tests {{{
TEST(IntRange, BasicSort) {
        int A[]{2, 5, 3, 6, 1, 30, 10};
        int A_O[]{1, 2, 3, 5, 6, 10, 30};

        std::cout << "Before:\t";
        for (auto &i : A)
                std::cout << i << " ";
        std::cout << std::endl;

        graal::qsort(
            std::begin(A),
            std::distance(std::begin(A), std::end(A)),
            sizeof(A[0]),
            INT_sort_comp);

        std::cout << "After:\t";
        for (auto &i : A)
                std::cout << i << " ";
        std::cout << std::endl;

        bool result = std::equal(std::begin(A), std::end(A), std::begin(A_O));
        ASSERT_TRUE(result);
}

TEST(IntRange, DuplicatedMembersSort) {
        int A[]{7, 6, 5, 4, 1, 1, 1};
        int A_O[]{1, 1, 1, 4, 5, 6, 7};

        graal::qsort(
            std::begin(A),
            std::distance(std::begin(A), std::end(A)),
            sizeof(A[0]),
            INT_sort_comp);

        bool result = std::equal(std::begin(A), std::end(A), std::begin(A_O));
        ASSERT_TRUE(result);
}

// ============================================================================
//                                                        Tests for char arrays
// ============================================================================
//{{{
// Predicate function for char
bool CHAR_bigg_than(const void *c) {
        const char *c_c = static_cast<const char *>(c);
        return *c_c > 'a';
};

// Equality function for char
bool CHAR_equal_to(const void *a, const void *b) {
        const char *a_ = static_cast<const char *>(a);
        const char *b_ = static_cast<const char *>(b);

        return *a_ == *b_;
};

// Boolean sort for char
bool CHAR_sort_comp(const void *a, const void *b) {
        const char *m_a = static_cast<const char *>(a);
        const char *m_b = static_cast<const char *>(b);

        return *m_a < *m_b;
}

// CharRange -> min() tests {{{
TEST(CharRange, MinBasic) {
        char A[]{'c', 'a', 's', 'a', 'l'};

        auto result = (const char *)graal::min(std::begin(A), std::end(A), sizeof(char),
                                               [](const void *a, const void *b) {
                                                       return *(static_cast<const char *>(a)) < *(static_cast<const char *>(b));
                                               });
        ASSERT_EQ(result, std::begin(A) + 1);
}

TEST(CharRange, MinFirstOcurrence) {
        char A[]{'c', 'c', 'c', 'c', 'c'};

        auto result = (const char *)graal::min(std::begin(A), std::end(A), sizeof(char),
                                               [](const void *a, const void *b) {
                                                       return *(static_cast<const char *>(a)) < *(static_cast<const char *>(b));
                                               });
        ASSERT_EQ(result, std::begin(A));
}
//}}}
// CharRange -> reverse() tests {{{
TEST(CharRange, ReverseEntireArrayEven) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f'};
        char result[]{'f', 'e', 'd', 'c', 'b', 'a'};

        graal::reverse(std::begin(A), std::end(A), sizeof(A[0]));

        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(result)));
}

TEST(CharRange, ReverseEntireArrayOdd) {
        char A[]{'a', 'b', 'c', 'd', 'e'};
        char A_E[]{'e', 'd', 'c', 'b', 'a'};

        graal::reverse(std::begin(A), std::end(A), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(CharRange, ReversePartOfArrayEven) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        char A_E[]{'a', 'b', 'f', 'e', 'd', 'c', 'g', 'h'};

        graal::reverse(std::begin(A) + 2, std::begin(A) + 6, sizeof(A[0]));

        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(CharRange, ReversePartOfArrayOdd) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        char A_E[]{'a', 'f', 'e', 'd', 'c', 'b', 'g'};

        graal::reverse(std::begin(A) + 1, std::begin(A) + 6, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
//}}}
// CharRange -> copy() tests {{{
TEST(CharRange, CopyEntireArray) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        char A_E[]{'a', 'a', 'a', 'a', 'a', 'a', 'a'};

        graal::copy(std::begin(A), std::end(A), std::begin(A_E), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(CharRange, CopyPartOfArray) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        char A_E[]{'a', 'b', 'a', 'a', 'a', 'a', 'a'};

        graal::copy(std::begin(A) + 2, std::end(A), std::begin(A_E) + 2, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(CharRange, CopyFinalOfArray) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        char A_E[]{'a', 'b', 'c', 'd', 'e', 'b', 'a'};

        graal::copy(std::begin(A) + 5, std::end(A), std::begin(A_E) + 5, sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(CharRange, CopyUnaryArray) {
        char A[]{'a'};
        char A_E[]{'x'};

        graal::copy(std::begin(A), std::end(A), std::begin(A_E), sizeof(A[0]));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}
//}}}
// CharRange -> clone() tests {{{
TEST(CharRange, CloneEntireArray) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

        char *result = static_cast<char *>(graal::clone(std::begin(A), std::end(A), sizeof(A[0])));
        ASSERT_TRUE(std::equal(std::begin(A), std::end(A), result));
        delete[] result;
}

TEST(CharRange, ClonePartOfArray) {
        char A[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

        char *result = static_cast<char *>(graal::clone(std::begin(A) + 3, std::end(A), sizeof(A[0])));
        ASSERT_TRUE(std::equal(std::begin(A) + 3, std::end(A), result));
        delete[] result;
}
//}}}
// CharRange -> find_if() tests {{{
TEST(CharRange, LotsAreBiggerThan) {
        char A[]{'a', 'c', 'd', 'b', 'a'};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE((std::begin(A) + 1) == result);
}

TEST(CharRange, OneIsBiggerThan) {
        char A[]{'a', 'a', 'a', 'b', 'a'};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE((std::begin(A) + 3) == result);
}
TEST(CharRange, NoneIsBiggerThan) {
        char A[]{'a', 'a', 'a', 'a'};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE(std::end(A) == result);
}
//}}}
// CharRange -> find() tests {{{
TEST(CharRange, LotsAreEqual) {
        char A[]{'a', 'b', 'k', 'k', 'k'};
        char A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), CHAR_equal_to);
        ASSERT_TRUE((std::begin(A) + 2) == result);
}

TEST(CharRange, ThereIsOneEqual) {
        char A[]{'b', 'a', 'q', 'l', 'k'};
        char A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), CHAR_equal_to);
        ASSERT_TRUE((std::begin(A) + 4) == result);
}

TEST(CharRange, NoneIsEqual) {
        char A[]{'a', 'b', 'c', 'd', 'e'};
        char A_E[]{'k'};
        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), CHAR_equal_to);
        ASSERT_TRUE(std::end(A) == result);
}
//}}}
// CharRange -> all_of() tests {{{
TEST(CharRange, AllOfAreBiggerThan) {
        char A[]{'b', 'c', 'd', 'e', 'f', 'g'};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(CharRange, AllOfAreNotBiggerThan) {
        char A[]{'b', 'a', 'd', 'e', 'f', 'g'};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), CHAR_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// CharRange -> any_of() tests {{{
TEST(CharRange, AnyOfAreBiggerThan) {
        char A[]{
            'a',
            'a',
            'a',
            'a',
            'a',
            'b',
            'a',
        };
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(CharRange, AnyOfAreNotBiggerThan) {
        char A[]{
            'a',
            'a',
            'a',
            'a',
            'a',
            'a',
            'a',
        };
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), CHAR_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// CharRange -> none_of() tests {{{
TEST(CharRange, NoneOfAreBiggerThan) {
        char A[]{
            'a',
            'a',
            'a',
            'a',
            'a',
            'a',
            'a',
        };
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), CHAR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(CharRange, NoneOfAreNotBiggerThan) {
        char A[]{
            'a',
            'a',
            'a',
            'z',
            'a',
            'a',
            'a',
        };
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), CHAR_bigg_than);
        ASSERT_FALSE(result);
}

//}}}
// CharRange -> type1 equal() tests {{{
TEST(CharRange, AllAreEqualType1) {
        char A[]{'a', 'b', 'c', 'd'};
        char A_E[]{'a', 'b', 'c', 'd'};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_TRUE(result);
}

TEST(CharRange, AllAreNotEqualType1) {
        char A[]{'a', 'b', 'c', 'd'};
        char A_E[]{'a', 'f', 'c', 'd'};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_FALSE(result);
}

TEST(CharRange, PartAreEqualType1) {
        char A[]{'a', 'c', 'b', 'd', 'g'};
        char A_E[]{'l', 'c', 'b', 'd', 'a'};
        bool result;

        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_TRUE(result);
}

TEST(CharRange, PartAreNotEqualType1) {
        char A[]{'a', 'c', 'b', 'd', 'g'};
        char A_E[]{'l', 'c', 'a', 'd', 'p'};

        bool result;
        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_FALSE(result);
}
//}}}
// CharRange -> type2 equal() tests {{{
TEST(CharRange, AllAreEqualType2) {
        char A[]{'a', 'c', 'b', 'd', 'g'};
        char A_E[]{'a', 'c', 'b', 'd', 'g'};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_TRUE(result);
}

TEST(CharRange, AllAreNotEqualType2) {
        char A[]{'a', 'c', 'b', 'd', 'g'};
        char A_E[]{'a', 'h', 'b', 'd', 'g'};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_FALSE(result);
}

TEST(CharRange, PartAreEqualType2) {
        char A[]{'a', 'c', 'b', 'd', 'e', 'g'};
        char A_E[]{'l', 'c', 'b', 'd', 'e', 'h'};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_TRUE(result);
}

TEST(CharRange, PartAreNotEqualType2) {
        char A[]{'a', 'c', 'b', 'd', 'e', 'g'};
        char A_E[]{'l', 'c', 'b', 'd', 'f', 'h'};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              CHAR_equal_to);
        ASSERT_FALSE(result);
}

//}}}
// CharRange -> unique() tests {{{
TEST(CharRange, UniqueAllAre) {
        char A[]{'a', 'c', 'd', 'b', 'e'};
        char A_E[]{'a', 'c', 'd', 'b', 'e'};

        char *result;
        result = static_cast<char *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                CHAR_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, UniqueManyAre) {
        char A[]{'a', 'b', 'e', 'd', 'e', 'c', 'c'};
        char A_E[]{'a', 'b', 'e', 'd', 'c'};

        char *result;
        result = static_cast<char *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                CHAR_equal_to));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, UniqueOneIs) {
        char A[]{'a', 'f', 'c', 'c', 'f', 'k', 'a'};
        char A_E[]{'a', 'f', 'c', 'k'};

        char *result;
        result = static_cast<char *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                CHAR_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, UniqueNoneIs) {
        char A[]{'a', 'b', 'h', 'b', 'h', 'a', 'j', 'j'};
        char A_E[]{'a', 'b', 'h', 'j'};

        char *result;
        result = static_cast<char *>(
            graal::unique(
                std::begin(A),
                std::end(A),
                sizeof(A[0]),
                CHAR_equal_to));

        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

//}}}
// CharRange -> partition() tests {{{
TEST(CharRange, PartitionAllAreTrue) {
        char A[]{'b', 'c', 'd', 'e', 'f'};
        char A_E[]{'b', 'c', 'd', 'e', 'f'};

        char *result;
        result = static_cast<char *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), CHAR_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, PartitionSomeAreTrue) {
        char A[]{'a', 'c', 'd', 'a', 'f'};
        char A_E[]{'c', 'd', 'f'};

        char *result;
        result = static_cast<char *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), CHAR_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, PartitionOneIsTrue) {
        char A[]{'a', 'a', 'a', 'a', 'a', 'a', 'f'};
        char A_E[]{'f'};

        char *result;
        result = static_cast<char *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), CHAR_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

TEST(CharRange, PartitionNoneIsTrue) {
        char A[]{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
        char A_E[]{NULL};

        char *result;
        result = static_cast<char *>(
            graal::partition(std::begin(A), std::end(A),
                             sizeof(A[0]), CHAR_bigg_than));
        ASSERT_TRUE(std::equal(std::begin(A), result, std::begin(A_E)));
}

//}}}
// CharRange -> sort() tests {{{
TEST(CharRange, BasicSort) {
        char A[]{'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        char A_O[]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};

        graal::qsort(
            std::begin(A),
            std::distance(std::begin(A), std::end(A)),
            sizeof(A[0]),
            CHAR_sort_comp);

        bool result = std::equal(std::begin(A), std::end(A), std::begin(A_O));
        ASSERT_TRUE(result);
}

TEST(CharRange, DuplicatedMembersSort) {
        char A[]{'g', 'f', 'e', 'd', 'a', 'a', 'a'};
        char A_O[]{'a', 'a', 'a', 'd', 'e', 'f', 'g'};

        graal::qsort(
            std::begin(A),
            std::distance(std::begin(A), std::end(A)),
            sizeof(A[0]),
            CHAR_sort_comp);

        bool result = std::equal(std::begin(A), std::end(A), std::begin(A_O));
        ASSERT_TRUE(result);
}

// ============================================================================
//                                                      Tests for string arrays
// ============================================================================
//{{{

// Predicate function for string
bool STR_bigg_than(const void *c) {
        const std::string *c_c = static_cast<const std::string *>(c);
        return *c_c > "aa";
};

// Equality function for string
bool STR_equal_to(const void *a, const void *b) {
        const std::string *a_ = static_cast<const std::string *>(a);
        const std::string *b_ = static_cast<const std::string *>(b);

        return *a_ == *b_;
};

// Boolean sort for std::string
bool STR_sort_comp(const void *a, const void *b) {
        const std::string *m_a = static_cast<const std::string *>(a);
        const std::string *m_b = static_cast<const std::string *>(b);

        return *m_a < *m_b;
}

// StringRange -> min() tests {{{
TEST(StringRange, MinBasic) {
        std::string A[]{"zebra", "azul", "tosse", "abacate", "nad"};

        auto result = (const std::string *)graal::min(std::begin(A), std::end(A), sizeof(std::string),
                                                      [](const void *a, const void *b) {
                                                              return *(static_cast<const std::string *>(a)) < *(static_cast<const std::string *>(b));
                                                      });
        ASSERT_EQ(result, std::begin(A) + 3);
}
TEST(StringRange, MinFirstOcurrence) {
        std::string A[]{"ano", "sal", "atroz", "anp", "anq", "re"};

        auto result = (const std::string *)graal::min(std::begin(A), std::end(A), sizeof(std::string),
                                                      [](const void *a, const void *b) {
                                                              return *(static_cast<const std::string *>(a)) < *(static_cast<const std::string *>(b));
                                                      });
        ASSERT_EQ(result, std::begin(A));
}
//}}}
// StringRange -> find_if() tests {{{
TEST(StringRange, FindIfLotsAreBiggerThan) {
        std::string A[]{"a", "cc", "lll", "bb", "aa"};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), STR_bigg_than);
        ASSERT_EQ(std::begin(A) + 1, result);
}

TEST(StringRange, FindIfOneIsBiggerThan) {
        std::string A[]{"a", "aa", "a", "bb", "aa"};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), STR_bigg_than);
        ASSERT_EQ(std::begin(A) + 3, result);
}

TEST(StringRange, FindIfNoneIsBiggerThan) {
        std::string A[]{"a", "aa", "a", "aa"};
        auto result = graal::find_if(std::begin(A), std::end(A),
                                     sizeof(A[0]), STR_bigg_than);
        ASSERT_EQ(std::end(A), result);
}
//}}}
// StringRange -> find() tests {{{
TEST(StringRange, FindLotsAreEqual) {
        std::string A[]{"aa", "bb", "kk", "kk", "kk"};
        std::string A_E[]{"kk"};

        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), STR_equal_to);
        ASSERT_EQ(std::begin(A) + 2, result);
}

TEST(StringRange, FindThereIsOneEqual) {
        std::string A[]{"bb", "aa", "qq", "ll", "kkkk"};
        std::string A_E[]{"kkkk"};

        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), STR_equal_to);
        ASSERT_EQ(std::begin(A) + 4, result);
}

TEST(StringRange, NoneIsEqual) {
        std::string A[]{"aa", "bb", "cc", "dd", "ee"};
        std::string A_E[]{"kk"};

        auto result = graal::find(std::begin(A), std::end(A), sizeof(A[0]),
                                  std::begin(A_E), STR_equal_to);
        ASSERT_EQ(std::end(A), result);
}
//}}}
// StringRange -> all_of() tests {{{
TEST(StringRange, AllOfAreBiggerThan) {
        std::string A[]{"ab", "ac", "ad", "aab", "ae"};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), STR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(StringRange, AllOfAreNotBiggerThan) {
        std::string A[]{"zz", "yy", "cc", "xx", "aa", "ww", "kkk"};
        bool result;

        result = graal::all_of(std::begin(A), std::end(A),
                               sizeof(A[0]), STR_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// StringRange -> any_of() tests {{{
TEST(StringRange, AnyOfAreBiggerThan) {
        std::string A[]{"aa", "aa", "aa", "aa", "bar", "aa", "aa"};
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), STR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(StringRange, AnyOfAreNotBiggerThan) {
        std::string A[]{"aa", "aa", "aa", "aa", "aa", "aa", "aa"};
        bool result;

        result = graal::any_of(std::begin(A), std::end(A), sizeof(A[0]), STR_bigg_than);
        ASSERT_FALSE(result);
}
//}}}
// StringRange -> none_of() tests {{{
TEST(StringRange, NoneOfAreBiggerThan) {
        std::string A[]{"aa", "aa", "aa", "aa", "aa"};
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), STR_bigg_than);
        ASSERT_TRUE(result);
}

TEST(StringRange, NoneOfAreNotBiggerThan) {
        std::string A[]{"aa", "zz", "aa", "aa", "aa"};
        bool result;

        result = graal::none_of(std::begin(A), std::end(A), sizeof(A[0]), STR_bigg_than);
        ASSERT_FALSE(result);
}

//}}}
// StringRange -> type1 equal() tests {{{
TEST(StringRange, AllAreEqualType1) {
        std::string A[]{"aa", "bb", "cc", "dd"};
        std::string A_E[]{"aa", "bb", "cc", "dd"};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              STR_equal_to);
        ASSERT_TRUE(result);
}

TEST(StringRange, AllAreNotEqualType1) {
        std::string A[]{"aa", "bb", "cc", "dd"};
        std::string A_E[]{"aa", "ff", "cc", "dd"};

        bool result;
        result = graal::equal(std::begin(A), std::end(A),
                              std::begin(A_E), sizeof(A[0]),
                              STR_equal_to);
        ASSERT_FALSE(result);
}

TEST(StringRange, PartAreEqualType1) {
        std::string A[]{"aa", "cc", "bb", "dd", "gg"};
        std::string A_E[]{"ll", "cc", "bb", "dd", "aa"};

        bool result;
        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              STR_equal_to);
        ASSERT_TRUE(result);
}

TEST(StringRange, PartAreNotEqualType1) {
        std::string A[]{"aa", "cc", "bb", "dd", "gg"};
        std::string A_E[]{"ll", "cc", "aa", "dd", "pp"};

        bool result;
        result = graal::equal(std::begin(A) + 1, std::begin(A) + 4,
                              std::begin(A_E) + 1, sizeof(A[0]),
                              STR_equal_to);
        ASSERT_FALSE(result);
}
//}}}
// StringRange -> type2 equal() tests {{{
TEST(StringRange, AllAreEqualType2) {
        std::string A[]{"aa", "cc", "bb", "dd", "gg"};
        std::string A_E[]{"aa", "cc", "bb", "dd", "gg"};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              STR_equal_to);
        ASSERT_TRUE(result);
}

TEST(StringRange, AllAreNotEqualType2) {
        std::string A[]{"aa", "cc", "bb", "dd", "gg"};
        std::string A_E[]{"aa", "hh", "bb", "dd", "gg"};

        bool result;
        result = graal::equal(std::begin(A),
                              std::end(A),
                              std::begin(A_E),
                              std::end(A_E),
                              sizeof(A[0]),
                              STR_equal_to);
        ASSERT_FALSE(result);
}

TEST(StringRange, PartAreEqualType2) {
        std::string A[]{"aa", "cc", "bb", "dd", "ee", "gg"};
        std::string A_E[]{"ll", "cc", "bb", "dd", "ee", "hh"};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              STR_equal_to);
        ASSERT_TRUE(result);
}

TEST(StringRange, PartAreNotEqualType2) {
        std::string A[]{"aa", "cc", "bb", "dd", "ee", "gg"};
        std::string A_E[]{"ll", "cc", "bb", "dd", "ff", "hh"};

        bool result;
        result = graal::equal(std::begin(A) + 1,
                              std::begin(A) + 5,
                              std::begin(A_E) + 1,
                              std::begin(A_E) + 5,
                              sizeof(A[0]),
                              STR_equal_to);
        ASSERT_FALSE(result);
}

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
