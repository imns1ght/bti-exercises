# Introduction

This exercise focuses on two basic types of **search algorithms** applied to a **sequence container** implemented with _array_.

In particular, you should implement two iterative functions, a **linear search** and a **binary search**. Remember that the binary search requires a sorted range, whereas the linear search does not.

The functions are called on ranges defined over an array of integers. Therefore they receive three parameters: two iterators (pointers) that define a half-closed interval for searching, `[first;last)`, and the `value` we are looking for. In case the search is successful, the function should return an iterator to the location of the target element; otherwise, the function should return `last`.

Finally, assume that the elements in the search range are _unique_, i.e. there is no repeated elements in the range.


# TODO

- [x] Implement the iterative versions of the linear search and binary search.
- [x] Test the functions.
- [ ] Compare the runtime of the search algorithms implemented.

# Further work

To improve your programming skills, runtime measurements experience, and your knowledge on recursion, you may want to:

1. Implement recursive versions for these two algorithms;

2. Measure the search runtime in the worst case on ranges with large size;

3. Implement the ternary search, which follows the binary search approach but rather dividing the range into three (almost) equal parts;

4. Run the versions already implemented in the `<cstdlib.h>`, [`bsearch()`](http://en.cppreference.com/w/cpp/algorithm/bsearch), and in `<algorithm>`, [`binary_search()`](http://en.cppreference.com/w/cpp/algorithm/binary_search), and;

5. Compare the runtime of the algorithms implemented, as their input size increases linearly.

# Authorship

Program developed by Selan (<selan@dimap.ufrn.br>) and students from EDB1, 2018.2

&copy; DIMAp/UFRN 2016-2018.

