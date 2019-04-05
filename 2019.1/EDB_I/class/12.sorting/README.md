# Table of Contents
1. [Compiling with `cmake`](#compiling-with-cmake)
	1. [Invoking `cmake`](#invoking-cmake)
	2. [Compiling the project](#compiling-the-project)
2. [ Compiling without `cmake`](#compiling-without-cmake-manual-compilation)
3. [Running the project](#running)

# 1. Compiling with `cmake`

To compile the project you need to follow 2 steps:

## 1.1 Invoking cmake

just run the following commands in the same (root) folder as the source file.

```
$ cmake -S . -B build -G "Unix Makefiles"
```

where,
* `-S` indicates where to look for the _source tree_, which in this case is the same folder we are running the command from.
* `-B` indicates which folder the executable and `cmake` cache files will be generated and written to.
* `-G` indicates which type of makefiles/project we want the `cmake` to generate for.

## 1.2 Compiling the project

If everything ran smoothly in the previous step, enter the `build` folder and compile the project with the following commands:

```
$ cd build
$ make
```

# 2. Compiling without `cmake` (manual compilation)

If you don't  want to use `cmake`, just type in the following command:

```
$ g++ -Wall -std=c++14 sorted_insert.cpp -o si
```

# 3. Running

Finally, just type in:

```
$ ./si
```

inside the `build` folder if you are using `cmake` or at the root folder, otherwise.

