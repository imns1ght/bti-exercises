/*!
 * \file filter.h
 * \author Selan
 * \date August, 9th
 */
#include <iostream>  //cout, endl
#include <iterator>  // distance
#include <algorithm> // copy, prev
#include <string>    // string
#include <sstream>   // std::ostringstream

#ifndef FILTER_H
#define FILTER_H

namespace ft {
    //=== Alias
    using value_type = int;

    //=== Function prototypes.

    /// Linear filter algorithm
    /*!
     * Remove negative and null elements from the range `[first;last)`
     * of integers, returning a pointer to the end of the resulting
     * (possibly new) interval.
     *
     * The filter process preserves the original relative order of the
     * remaining (positive) integers.
     *
     * The algorithm does not delete memory. It just moves the filtered
     * elements to the begining of the range, preserving their original
     * relative order. Therefore, only the logical length of the range
     * might be altered as a result of the filter operation.
     *
     * This version implements the **linear** slow/fast approach, copying
     * the elements around, within the range memory space. This means that
     * no extra memory is allocated.
     *
     * \note Undefined behavior if the range provided is invalid.
     *
     * \param first The begining of the range we want to filter.
     * \param last The end (just past the last) of the range we want to filter.
     * \return A pointer to the new last, after the elements have been filtered.
     */
    value_type * filter_lin( value_type *first, value_type *last );

    /// Quadratic filter algorithm
    /*!
     * Remove negative and null elements from the range `[first;last)`
     * of integers, returning a pointer to the end of the resulting
     * (possibly new) interval.
     *
     * The filter process preserves the original relative order of the
     * remaining (positive) integers.
     *
     * The algorithm does not delete memory. It just moves the filtered
     * elements to the begining of the range, preserving their original
     * relative order. Therefore, only the logical length of the range
     * might be altered as a result of the filter operation.
     *
     * This version implements the **quadratic** approach, which shifts
     * the entire array whenever a negative/null element is found, thus
     * overriding that target (filtered) element.
     * Because of this (inefficient) movement of memory, the algorithm
     * is quadratic.
     *
     * \note Undefined behavior if the range provided is invalid.
     *
     * \param first The begining of the range we want to filter.
     * \param last The end (just past the last) of the range we want to filter.
     * \return A pointer to the new last, after the elements have been filtered.
     */
    value_type * filter_quad( value_type * first, value_type * last );

#ifdef DEBUG
    /// Prints the range content on a string buffer.
    std::string print ( value_type * first, value_type * last );
#endif
}
#endif
