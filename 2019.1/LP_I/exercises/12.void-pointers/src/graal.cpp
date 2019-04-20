#include "../include/graal.h"

namespace graal {
const void *min(const void *first, const void *last, size_t size, Compare cmp) {
        const void *min_value = first;

        while (first != last) {
                if (cmp(first, min_value)) {
                        min_value = first;
                }

                first = (byte *)first + size;
        }

        return min_value;
}

void reverse(void *first, void *last, size_t size) {
        int distance = std::distance((byte *)first, (byte *)last) / size;

        // Swap first and last until the half of the range
        for (auto i = 0; i < distance / 2; i++) {
                byte *pfirst = (byte *)first;
                byte *plast = (byte *)last - size;
                byte temp[size];  // aux

                std::memcpy(temp, pfirst, size);
                std::memcpy(pfirst, plast, size);
                std::memcpy(plast, temp, size);

                first = (byte *)first + size;
                last = (byte *)last - size;
        }
}

void *copy(const void *first, const void *last, void *d_first, size_t size) {
        while (first != last) {
                std::memcpy(d_first, first, size);
                d_first = (byte *)d_first + size;
                first = (byte *)first + size;
        }

        return d_first;
}

void *clone(const void *first, const void *last, size_t size) {
        byte *destArray = new byte[std::distance((byte *)first, (byte *)last) / size];
        byte *vfirst = destArray;

        while (first != last) {
                std::memcpy(vfirst, first, size);
                vfirst = vfirst + size;
                first = (byte *)first + size;
        }

        return destArray;
}

const void *find_if(const void *first, const void *last, size_t size, Predicate p) {
        while (first != last) {
                if (p(first)) {
                        return first;
                }

                first = (byte *)first + size;
        }

        return last;
}

const void *find(const void *first, const void *last, size_t size, const void *value, Equal eq) {
        while (first != last) {
                if (eq(first, value)) {
                        return first;
                }

                first = (byte *)first + size;
        }

        return last;
}

bool all_of(const void *first, const void *last, size_t size, Predicate p) {
        while (first != last) {
                if (!p(first)) {
                        return false;
                }

                first = (byte *)first + size;
        }

        return true;
}

bool any_of(const void *first, const void *last, size_t size, Predicate p) {
        if (first == last) {
                return true;
        }

        while (first != last) {
                if (p(first)) {
                        return true;
                }

                first = (byte *)first + size;
        }

        return false;
}

bool none_of(const void *first, const void *last, size_t size, Predicate p) {
        while (first != last) {
                if (p(first)) {
                        return false;
                }

                first = (byte *)first + size;
        }

        return true;
}

bool equal(const void *first1, const void *last1,
           const void *first2, size_t size, Equal p) {
        while (first2 != (byte *)first2 + std::distance((byte *)last1, (byte *)first1)) {
                if (!p(first1, first2)) {
                        return false;
                }

                first1 = (byte *)first1 + size;
                first2 = (byte *)first2 + size;
        }

        return true;
}

bool equal(const void *first1, const void *last1,
           const void *first2, const void *last2, size_t size, Equal p) {
        while (first2 != last2) {
                if (!p(first1, first2)) {
                        return false;
                }

                first1 = (byte *)first1 + size;
                first2 = (byte *)first2 + size;
        }

        if (first1 < last1) {
                return false;
        } else {
                return true;
        }
}

void *unique(void *first, void *last, size_t size, Equal eq) {
        for (auto i = first; i != last; i = (byte *)i + size) {
                bool repeated = false;

                // If there are repeated numbers, try the next number
                for (auto j = (byte *)i + size; j != last; j = (byte *)j + size) {
                        if (eq(i, j)) {
                                repeated = true;
                                break;
                        }
                }

                // If there are no repeating numbers, save the number
                if (!repeated) {
                        std::memcpy(first, i, size);
                }
        }

        return first;
}

void *partition(void *first, void *last, size_t size, Predicate p) {
        // Stores the group of elements when predicate p is true
        for (auto i = first; i != last; i = (byte *)i + size) {
                if (p(i)) {
                        byte temp[size];  // aux
                        std::memcpy(temp, first, size);
                        std::memcpy(first, i, size);
                        std::memcpy(i, temp, size);
                        first = (byte *)first + size;
                }
        }

        auto begin = first;  // Begin of elements after "p true"

        // Stores remaining elements
        for (auto j = first; j != last; j = (byte *)j + size) {
                byte temp[size];  // aux
                std::memcpy(temp, first, size);
                std::memcpy(first, j, size);
                std::memcpy(j, temp, size);
                first = (byte *)first + size;
        }

        return begin;
}

// Simple sort algorithm
void qsort(void *first, size_t count, std::size_t size, Compare cmp) {
        for (auto i = first; i < (byte *)first + (size * count); i = (byte *)i + size) {
                for (auto j = (byte *)i + size; j < (byte *)first + (size * count); j = (byte *)j + size) {
                        if (cmp(j, i)) {
                                byte temp[size];  // aux
                                std::memcpy(temp, i, size);
                                std::memcpy(i, j, size);
                                std::memcpy(j, temp, size);
                        }
                }
        }
}

}  // namespace graal