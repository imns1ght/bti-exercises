# Introduction

This exercise focuses on two basic types of **search algorithms** applied to a **sequence container** implemented with _array_.

In particular, you should implement two iterative functions, a **linear search** and a **binary search**. Remember that the binary search requires a sorted range, whereas the linear search does not.

The functions are called on ranges defined over an array of integers. Therefore they receive three parameters: two iterators (pointers) that define a half-closed interval for searching, `[first;last)`, and the `value` we are looking for. In case the search is successful, the function should return an iterator to the location of the target element; otherwise, the function should return `last`.

Finally, assume that the elements in the search range are _unique_, i.e. there is no repeated elements in the range.

# Compiling

This project may be compiled with [CMake](https://cmake.org).
CMake is an open-source, cross-platform family of tools designed to build, test and package software.
Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.

Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

In particular, this project creates two **targets** (executables): a simple driver (simulating a
cliente using the functions), called `run_bsearch`, and the tests (the google tests suite), called `run_tests`.
But don't worry, they are already set up in the `CMakeLists.txt` script.

To compile this project with [cmake](https://cmake.org) follow these steps:

1. `cd searching_exercise`: enters into the main project directory.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .` or `make`: triggers the compiling process.

And *voilà*, you have an executable inside the `build` directory.

# Running

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./run_driver
```

or

```
$ ./run_tests
```

# Further work (TODO)

To improve your programming skills, runtime measurements experience, and your knowledge on recursion, you may want to:

1. Implement recursive versions for these two algorithms;

2. Measure the search runtime in the worst case on ranges with large size;

3. Implement the ternary search, which follows the binary search approach but rather dividing the range into three (almost) equal parts;

4. Run the versions already implemented in the `<cstdlib.h>`, [`bsearch()`](http://en.cppreference.com/w/cpp/algorithm/bsearch), and in `<algorithm>`, [`binary_search()`](http://en.cppreference.com/w/cpp/algorithm/binary_search), and;

5. Compare the runtime of the algorithms implemented, as their input size increases linearly.

6. Implement two new algorithms, `lower_bound` and `upper_bound`.

# Authorship

Program developed by Selan (<selan@dimap.ufrn.br>) and students from EDB1, 2019.1

&copy; DIMAp/UFRN 2016-2019.

