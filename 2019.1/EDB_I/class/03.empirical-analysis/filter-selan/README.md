# 1. Introduction

This program might be use to compare the execution time of two algorithms from different complexity classes to solve the filter problem.

Based on some preprocessing directives setup while compiling this program, it is possible to print out the execution time of the chosen algorithm for a given input of size defined by command line argument.

# 2. The Problem

The filter problem is:
> Given the range `[first;last)` defined over an array of integers, remove all the null and negative elements, and return a pointer to the new `last`, which should define a range containing the filtered elements.
> The processes must preserve the relative order of the elements that will be kept in the new range.

## Example

Given the range `[first;last)` with the following values
> -3, 4, 8, 0, -2, 7, 0, 12, -1

the program should return the pointer `last` so that if we print `[first;last)` again we get
> 4, 8, 7, 12

If all elements in the input range are null or negative, the output range `[first, last)` should be empty.

If all elements in the input range are positive, the output range `[first,last)` should be the same as the input.

# 3. Compiling

To compile you may enter this at the terminal prompt:

```
g++ -Wall -std=c++11 filter_runtime.cpp -o filter
```

Alternatively, a cmake file is available. Follow the steps below:

1. Create a build directory: `mkdir build`.
2. Change into the build directory: `cd build`.
3. Generate the project file (Makefile): `cmake -G "Unix Makefiles" ..`
4. Compile each target (`timing_filter` and `run_tests`) or both targets at the same time: `cmake --build . --configure Release --target timing_filter` or
 `cmake --build . --configure Release --target run_tests`

## Setting the execution options
The program has several *preprocessing directives* that might be added to the compile line and  enables you to choose between the following running options:

* We may choose between a *linear*  and a *quadractic*  algorithm to solve the problem.
    + Add `-D ALGO="QUAD"` to choose the quadratic algorithm.
    + Add `-D ALGO="LIN"` to choose the linear algorithm (default option).

* We may choose between the three types input range configuration:
    + Add `-D CASE="AVERAGE"` to generate input values randomly chosen from `[-100;100]` (default option).
    + Add `-D CASE="WORST"` to generate only null or negative input values.
    + Add `-D CASE="BEST"` to generate only positive input values.

While compiling you may also turn on/off the following preprocessing directives:

* `-D DEBUG`: to print out messages that explain intermediate steps of the running algorithm.
* `-D PRINT`: to print the input and the output range.

By default, i.e. if no preprocessing directive is provided while compiling, the program runs with the following parameters set:

* Range with 20 elements in the average case.
* The linear algorithm.
* Not printing the input/output range.
* Not displaying any debug message.

# 4. Running

To run you may inform the size of the input range, which should be filled with random values: `$ .\filter [input_size]`

For instance, the example below

```
$ .\filter
```

runs filter with 20 random values, whereas the example below

```
$ .\filter 100
```

runs filter with 100 random values.

In case you provide an invalid input value, the program defaults to 20.

