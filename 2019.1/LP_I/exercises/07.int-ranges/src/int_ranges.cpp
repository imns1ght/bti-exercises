#include "../include/int_ranges.h"

namespace ir {
void negate(value_type *first, value_type *last) {
        while (first != last) {
                *first++ *= -1;
        }
}

const value_type *min(const value_type *first, const value_type *last) {
        auto min_value = first;

        while (first != last) {
                if (*min_value > *first) {
                        min_value = first;
                }

                first++;
        }

        return min_value;
}

void reverse(value_type *first, value_type *last) {
        auto range = std::distance(first, last);  // Calculates the range of the array

        // Swap first and last until the half of the range
        for (int i = 0; i < range / 2; i++, first++, last--) {
                std::swap(*first, *(last - 1));
        }
}

void scalar_multiplication(value_type *first, value_type *last, value_type scalar) {
        while (first != last) {
                *first++ = *first * scalar;
        }
}

value_type dot_product(const value_type *a_first, const value_type *a_last, const value_type *b_first) {
        value_type result = 0;

        while (a_first != a_last) {
                result += (*a_first++) * (*b_first++);
        }

        return result;
}

value_type *compact(value_type *first, value_type *last) {
        for (auto i = first; i != last; i++) {
                if (*i > 0) {
                        *first++ = *i;
                }
        }

        return first;
}

value_type *copy(const value_type *first, const value_type *last, value_type *d_first) {
        // Copy while free location exists
        while (first != last) {
                if (*d_first != 0) {
                        return d_first;
                } else {
                        *d_first++ = *first;
                }

                first++;
        }

        return d_first;
}

value_type *unique(value_type *first, value_type *last) {
        for (auto i = first; i != last; i++) {
                bool repeated = false;

                // If there are repeated numbers, try the next number
                for (auto j = (i + 1); j != last; j++) {
                        if (*i == *j) {
                                repeated = true;
                                break;
                        }
                }

                // If there are no repeating numbers, save the number
                if (!repeated) {
                        *first++ = *i;
                }
        }

        return first;
}

value_type *sort_marbles(value_type *first, value_type *last) {
        bool whtExists = true;

        for (auto i = first; i != last; i++) {
                // If there are a white
                if (*i) {
                        // Search for a black to swap
                        for (auto j = (i + 1); j != last; j++) {
                                if (!*j) {
                                        std::swap(*i, *j);
                                        break;
                                }
                        }
                        first++;

                } else {
                        whtExists = false;
                }
        }

        if (whtExists) {  // If there are no white
                return last;

        } else {  // If there are no black
                return first;
        }
}

void partition(value_type *first, value_type *last, value_type *pivot) {
        auto value = *pivot;  // Value of the pivot

        // Stores the group of elements LESS than pivot
        for (auto i = first; i != last; i++) {
                if (*i < value) {
                        std::swap(*first++, *i);
                }
        }

        // Stores the group of elements EQUAL than pivot
        for (auto j = first; j != last; j++) {
                if (*j == value) {
                        std::swap(*first++, *j);
                }
        }

        // Stores the group of elements GREATER than pivot
        for (auto k = first; k != last; k++) {
                if (*k > value) {
                        std::swap(*first++, *k);
                }
        }
}

void rotate(value_type *first, value_type *n_first, value_type *last) {
        auto range = std::distance(first, n_first);  // Calculates the range of the first sub-array

        // Rotates the elements "range" times
        for (int i = 0; i < range; i++) {
                auto temp = *first;
                auto j = first;

                while (j < (last - 1)) {
                        *j = *(j + 1);
                        j++;
                }

                *j = temp;
        }
}

bool equalArrays(const value_type A[], const value_type A_E[], std::size_t n) {
        return std::equal(A, A + n, A_E);
}

}  // namespace ir