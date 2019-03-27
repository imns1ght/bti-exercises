# Intro

In this programming project, **IntRanges** you should implement all the items in the assignment.
For each item, create a set of google tests to prove that they are correct.
But don't worry, they are already set up in the `CMakeLists.txt` script.

After finishing the first part of the assigment, you will be able to generate your first **library**, which should
contain the implementation of all functions described in the assignment.
Then, your library, `IntRangelib.a`, might be linked to any application that needs to uses the functions
defines in the library, such as `negate()`, `rotate()`, etc.

To simulate that, you should proceed to the second part of the assignment in which you shall
implement a `driver` app (executable), just to demonstrate some of the funtions from `IntRange` library.


# Compiling

This project may be compiled with [CMake](https://cmake.org).
CMake is an open-source, cross-platform family of tools designed to build, test and package software.
Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.

Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

# Parte 1: Compiling the Library

To compile the libray only we shoudl follow these steps:

1. `cd lib_source`: enters into the main project directory.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .`: triggers the compiling process.
5. `make install`: copies the library to the `lib` directory.

And *voilà*, you have an executable inside the `build` directory that tests the library functions.
Also, you will have a library `libIntRanges.a` in which the functions are compiled.

## Running the tests

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/run_tests
```

# Parte 2: Compiling the Driver Application


Remember that to compile the driver application we must first complete the library implementation.
After that, follow these steps:

1. `cd app_source`: enters into the main project directory.
2. `cp ../lib_source/include/int_ranges.h include`: copy the library header into this new project.
3. `cp ../lib_source/lib/IntRangelib.a lib`: copy the external library into the `lib` directory of this project.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .`: triggers the compiling process.

And *voilà*, you have an executable inside the `build` directory.

## Running the Driver Application

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/driver_int_ranges
```

# TODO

Notice that the code provided is **incomplete**!
You must implement all the functions described in the assignment PDF, design and implement tests (inside `tests/main.cpp`) to
make sure all the function are working correctly.
