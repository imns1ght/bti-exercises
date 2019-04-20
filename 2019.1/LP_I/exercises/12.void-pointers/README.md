# Compiling 

This project may be compiled with [CMake](https://cmake.org).
CMake is an open-source, cross-platform family of tools designed to build, test and package software.
Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.

Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

To compile the library only we should follow these steps:

1. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
2. `cd build`: just moves into the directory created in the step above.
3. `cmake -G "Unix Makefiles" .. .`: asks cmake to create the Makefile based on the script found in  `CMakeLists.txt`, one level up.
4. `cmake --build .`: triggers the compiling process.
5. `make install`: copies the library to the `lib` directory.

And *voilà*, you have an executable inside the `build` directory that tests the library functions.
Also, you will have a library `libIntRanges.a` in which the functions are compiled.

# Running the tests

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/run_tests
```

# Author
* [Jefferson Bruno (imns1ght)](https://imns1ght.github.io)
