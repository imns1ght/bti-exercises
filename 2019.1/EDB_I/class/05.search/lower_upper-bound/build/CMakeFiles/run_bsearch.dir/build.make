# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build

# Include any dependencies generated for this target.
include CMakeFiles/run_bsearch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run_bsearch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_bsearch.dir/flags.make

CMakeFiles/run_bsearch.dir/src/app.cpp.o: CMakeFiles/run_bsearch.dir/flags.make
CMakeFiles/run_bsearch.dir/src/app.cpp.o: ../src/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_bsearch.dir/src/app.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_bsearch.dir/src/app.cpp.o -c /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/app.cpp

CMakeFiles/run_bsearch.dir/src/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_bsearch.dir/src/app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/app.cpp > CMakeFiles/run_bsearch.dir/src/app.cpp.i

CMakeFiles/run_bsearch.dir/src/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_bsearch.dir/src/app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/app.cpp -o CMakeFiles/run_bsearch.dir/src/app.cpp.s

CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o: CMakeFiles/run_bsearch.dir/flags.make
CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o: ../src/bsearch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o -c /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/bsearch.cpp

CMakeFiles/run_bsearch.dir/src/bsearch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_bsearch.dir/src/bsearch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/bsearch.cpp > CMakeFiles/run_bsearch.dir/src/bsearch.cpp.i

CMakeFiles/run_bsearch.dir/src/bsearch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_bsearch.dir/src/bsearch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/src/bsearch.cpp -o CMakeFiles/run_bsearch.dir/src/bsearch.cpp.s

# Object files for target run_bsearch
run_bsearch_OBJECTS = \
"CMakeFiles/run_bsearch.dir/src/app.cpp.o" \
"CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o"

# External object files for target run_bsearch
run_bsearch_EXTERNAL_OBJECTS =

run_bsearch: CMakeFiles/run_bsearch.dir/src/app.cpp.o
run_bsearch: CMakeFiles/run_bsearch.dir/src/bsearch.cpp.o
run_bsearch: CMakeFiles/run_bsearch.dir/build.make
run_bsearch: CMakeFiles/run_bsearch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_bsearch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_bsearch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_bsearch.dir/build: run_bsearch

.PHONY : CMakeFiles/run_bsearch.dir/build

CMakeFiles/run_bsearch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_bsearch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_bsearch.dir/clean

CMakeFiles/run_bsearch.dir/depend:
	cd /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build /home/imns1ght/workspace/bti-exercises/2019.1/EDB_I/class/05.search/lower_upper-bound/build/CMakeFiles/run_bsearch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_bsearch.dir/depend

