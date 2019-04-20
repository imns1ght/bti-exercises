#ifndef GRAAL_LIB_H
#define GRAAL_LIB_H

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include "../include/client.h"  // Functions provide by client

namespace graal {

/// Returns a pointer to the first occurrency of the smallest element the range.
const void *min(const void *first, const void *last, size_t size, Compare cmp);

/// Reverse the order of the elements in range `[first;last)`.
void reverse(void *first, void *last, size_t size);

/// Copy the content of the range `[first;last)` to another range beginning at `d_first`.
void *copy(const void *first, const void *last, void *d_first, size_t size);

/// Receives a range defined over an array and returns a pointer to
/// a new array containing a copy of the original range
void *clone(const void *first, const void *last, size_t size);

///  Returns a pointer to the first element in the range for which
/// a given predicate p returns true
const void *find_if(const void *first, const void *last, size_t size, Predicate p);

///  Returns a pointer to the first element in the range that is equal to the value passed to the function
const void *find(const void *first, const void *last, size_t size, const void *value, Equal eq);

/// Returns true if the predicate returns true for all elements in the range
bool all_of(const void *first, const void *last, size_t size, Predicate p);

/// Returns true if the predicate returns true for at least one element in the range
bool any_of(const void *first, const void *last, size_t size, Predicate p);

/// Returns true if the predicate returns true for none of elements in the range.
bool none_of(const void *first, const void *last, size_t size, Predicate p);

/// Receives range[first1;last1), and a pointer to the beginning of another range first2;
/// and return true if the first range is equal to the range [first2; first2 + (last1 - first1)),
/// and false otherwise.
bool equal(const void *first1, const void *last1, const void *first2, size_t size, Equal p);

/// Receives two ranges, [first1;last1) and [first2;last2); and return true
/// if the elements in the ranges are equal, and false otherwise.
bool equal(const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal p);

/// Receives a range [first;last) over an array, reorders the elements
/// in the range [first,last) in such a way that all unique elements
/// should appear at the beginning of the range
void *unique(void *first, void *last, size_t size, Equal eq);

/// Receives a range [first;last) over an array, reorders the elements
/// in the range [first,last) in such a way that all elements
/// for which a given predicate p returns true precede the elements
/// for which predicate p returns false.
void *partition(void *first, void *last, size_t size, Predicate p);

/// Receives and sorts the elements in ascending order.
void qsort(void *first, size_t count, std::size_t size, Compare cmp);

}  // namespace graal
#endif
