#ifndef INSERTION_H
#define INSERTION_H

#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota

using Compare = bool (*)(const int &, const int&); // Useful alias

/*!
 *  Inserts a new element in the range, keeping the range sorted,
 *  and return the new last element in the range.
 *
 *  \note We assume there is enough space in range to insert an extra element.
 *
 *  \param first Iterator to the first element in range.
 *  \param last Iterator to past the last element in range.
 *  \param e The element we wish to insert.
 *  \param cmp The function pointer that compares two elements.
 *  \return An iterator to the new `last` of the range [first;last).
 *
 *  The function inserts a new element `e` in the range [first;last)
 *  in such a way to preserve the current sorting order.
 *  The new range becomes [firstl;last+1).
 *  We assume there is a strict total order relation among the elements
 *  in the range. The strict total order is tested with `cmp(a,b)`, which
 *  return `true` if `a < b`, and false otherwise.
 *
 *  If the elements are not sorted the result is undefined.
 */
int * insertion_sort(int *first, int *last, const int &e, Compare cmp);

#endif