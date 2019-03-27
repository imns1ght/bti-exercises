#include <iterator> // begin(), end()

#include "gtest/gtest.h"
#include "../include/int_ranges.h"

using namespace ir;
TEST(IntRange, NegateBasic)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5 };
	ir::value_type A_E[]{ -1, -2, -3, -4, -5 };

	auto len_before{ std::distance( std::begin(A), std::end(A) ) };
	ir::negate( std::begin(A), std::end(A) );
	auto len_after{ std::distance( std::begin(A), std::end(A) ) };
	ASSERT_EQ( len_before, len_after );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateZeros)
{
	ir::value_type A[]{ 0, 0, 0, 0, 0 };
	ir::value_type A_E[]{ 0, 0, 0, 0, 0 };

	auto len_before{ std::distance( std::begin(A), std::end(A) ) };
	ir::negate( std::begin(A), std::end(A) );
	auto len_after{ std::distance( std::begin(A), std::end(A) ) };
	ASSERT_EQ( len_before, len_after );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateMixed)
{
	ir::value_type A[]{ 0, -2, 1, -3, 0 };
	ir::value_type A_E[]{ 0, 2, -1, 3, 0 };

	auto len_before{ std::distance( std::begin(A), std::end(A) ) };
	ir::negate( std::begin(A), std::end(A) );
	auto len_after{ std::distance( std::begin(A), std::end(A) ) };
	ASSERT_EQ( len_before, len_after );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, MinBasic)
{
	ir::value_type A[]{ 1, 2, -3, 4, 0 };

	auto result = ir::min( std::begin(A), std::end(A) );
	ASSERT_EQ( result , std::begin(A)+2 );
}

TEST(IntRange, MinFirstOcurrence)
{
	ir::value_type A[]{ 1, 1, 1, 1, 1 };

	auto result = ir::min( std::begin(A), std::end(A) );
	ASSERT_EQ( result , std::begin(A) );
}

TEST(IntRange, ReverseEntireArratyEven)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 6, 5, 4, 3, 2, 1 };

	ir::reverse( std::begin(A), std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, ReverseEntireArratyOdd)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5 };
	ir::value_type A_E[]{ 5, 4, 3, 2, 1 };

	ir::reverse( std::begin(A), std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayEven)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
	ir::value_type A_E[]{ 1, 2, 6, 5, 4, 3, 7 };

	ir::reverse( std::begin(A)+2, std::begin(A)+6 );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, ReversePartOfArrayOdd)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6, 7 };
	ir::value_type A_E[]{ 1, 6, 5, 4, 3, 2, 7 };

	ir::reverse( std::begin(A)+1, std::begin(A)+6 );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, ScalarMultBasic)
{
	ir::value_type A[] {10, -20, 30, -40};
	ir::value_type A_E[]{370, -740, 1110, -1480};
	value_type scalar = 37;
	
	ir::scalar_multiplication(std::begin(A), std::end(A), scalar);
	auto equal = ir::equalArrays(A, A_E, (sizeof(A)/sizeof(A[0])));
	ASSERT_TRUE(equal);
}

TEST(IntRange, ScalarMultNeg)
{
	ir::value_type A[] {-1, -1, -1, -1};
	ir::value_type A_E[]{-37, -37, -37, -37};
	value_type scalar = 37;
	
	ir::scalar_multiplication(std::begin(A), std::end(A), scalar);
	auto equal = ir::equalArrays(A, A_E, (sizeof(A)/sizeof(A[0])));
	ASSERT_TRUE(equal);
}

TEST(IntRange, ScalarMultZero)
{
	ir::value_type A[] {0, 0, 0, 0};
	ir::value_type A_E[]{0, 0, 0, 0};
	value_type scalar = 37;
	
	auto len_before{ std::distance( std::begin(A), std::end(A) ) };
	ir::scalar_multiplication(std::begin(A), std::end(A), scalar);
	auto len_after{ std::distance( std::begin(A), std::end(A) ) };
	ASSERT_EQ( len_before, len_after );
	auto equal = ir::equalArrays(A, A_E, (sizeof(A)/sizeof(A[0])));
	ASSERT_TRUE(equal);
}

TEST(IntRange, dot_productBasic)
{
	ir::value_type A[] {10, -20, 30, -40, -29, 23};
	value_type value = 870;
	
	auto result = ir::dot_product(std::begin(A), (std::begin(A)+3), (std::begin(A)+3));
	ASSERT_TRUE(value == result);
}

TEST(IntRange, dot_productZero)
{
	ir::value_type A[] {0, 0, 0, 0, 0, 0};
	value_type value = 0;
	
	auto result = ir::dot_product(std::begin(A), (std::begin(A)+3), (std::begin(A)+3));
	ASSERT_TRUE(value == result);
}

TEST(IntRange, compactBasic)
{
	ir::value_type A[]{-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};
	
	auto result = ir::compact(std::begin(A), std::end(A));
	ASSERT_EQ((std::begin(A)+5), result);
}

TEST(IntRange, compactZero)
{
	ir::value_type A[]{0, 0, 0, 0, 0};
	
	auto result = ir::compact(std::begin(A), std::end(A));
	ASSERT_EQ((std::begin(A)), result);
}

TEST(IntRange, copyBasic)
{
	ir::value_type A[]{4, 3, 1, 4, 5, 7, 8, 9, 10, 53, 102};
	ir::value_type A_E[]{0, 0, 0, 0, 0};

	auto result = ir::copy( std::begin(A), std::end(A), std::begin(A_E));
	ASSERT_TRUE(std::equal(std::begin(A), (std::begin(A)+5), std::begin(A_E)));
	ASSERT_EQ(std::end(A_E), result);
}

TEST(IntRange, uniqueBasic)
{
	ir::value_type A[] {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};
	ir::value_type A_E[]{1, 2, 3, 4, 5};
	
	auto result = ir::unique(std::begin(A), std::end(A));
	ASSERT_TRUE(std::equal(std::begin(A), (std::begin(A)+5), std::begin(A_E)));
	ASSERT_EQ((std::begin(A)+5), result);
}

TEST(IntRange, uniqueBasic_2)
{
	ir::value_type A[] {1, -2, -1, 2, 3, -3, 1, 2, -4, 5, 3, -4, 5};
	ir::value_type A_E[]{-2, -1, -3, 1, 2, 3, -4, 5};
	
	auto result = ir::unique(std::begin(A), std::end(A));
	ASSERT_TRUE(std::equal(std::begin(A), (std::begin(A)+8), std::begin(A_E)));
	ASSERT_EQ((std::begin(A)+8), result);
}

TEST(IntRange, sortBasic)
{
	ir::value_type A[] {1, 0, 0, 1, 1, 0, 1};
	ir::value_type A_E[]{0, 0, 0, 1, 1, 1, 1};
	
	auto result = ir::sort_marbles(std::begin(A), std::end(A));
	ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
	ASSERT_EQ((std::begin(A)+7), result);
}

TEST(IntRange, sortBasic_2)
{
	ir::value_type A[] {1, 1, 0, 1, 1, 0, 1, 0, 0, 0};
	ir::value_type A_E[]{0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	
	auto result = ir::sort_marbles(std::begin(A), std::end(A));
	ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
	ASSERT_EQ((std::begin(A)+10), result);
}

TEST(IntRange, partitionBasic)
{
	ir::value_type A[] {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
	ir::value_type A_E[]{-5, 1, -2, 3, 7, 7, 7, 9, 10, 8};
	
	ir::partition(std::begin(A), std::end(A), (std::begin(A)+3));
	ASSERT_TRUE(std::equal(std::begin(A), std::end(A), std::begin(A_E)));
}

TEST(IntRange, RotateBasic_0_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 1, 2, 3, 4, 5, 6 };

	rotate( std::begin(A), std::begin(A), std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, RotateBasic_1_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 2, 3, 4, 5, 6, 1 };

	rotate( std::begin(A), std::begin(A)+1, std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_2_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 3, 4, 5, 6, 1, 2 };

	rotate( std::begin(A), std::begin(A)+2, std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_3_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 4, 5, 6, 1, 2, 3 };

	rotate( std::begin(A), std::begin(A)+3, std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, RotateBasic_4_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 5, 6, 1, 2, 3, 4 };

	rotate( std::begin(A), std::begin(A)+4, std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, RotateBasic_5_moves)
{
	ir::value_type A[]{ 1, 2, 3, 4, 5, 6 };
	ir::value_type A_E[]{ 6, 1, 2, 3, 4, 5 };

	rotate( std::begin(A), std::begin(A)+5, std::end(A) );
	ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
