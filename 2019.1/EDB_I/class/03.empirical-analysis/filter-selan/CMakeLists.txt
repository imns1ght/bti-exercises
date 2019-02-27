cmake_minimum_required(VERSION 3.5)
project (Filter)

#=== FINDING PACKAGES ===#

# Locate GTest package (library)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
#set( PREPROCESSING_FLAGS  "-D PRINT")
#set( PREPROCESSING_FLAGS  "-D PRINT -D DEBUG -D CASE="WORST" -D ALGO="QUAD"')
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS} ${PREPROCESSING_FLAGS}" )

#Include dir
include_directories( include )

#=== Main App ===
#Can manually add the sources using the set command as follows:
#set(SOURCES src/filter.cpp src/timing_filter.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(timing_filter ${SOURCES})

add_definitions(-DALGO=LIN    # Choose which type of algorithm to run: LIN (linear) or QUAD (quadratic)
                -DCASE=AVERAGE  # Choose which input data configuration to run: WORST, AVERAGE, or BEST case
                -DDEBUG       # Set this if you want to see messages explaning how the selected algorithm works.
                -DPRINT       # Set this if you want the program to print the input/output array.
                )

#define C++11 as the standard.
target_compile_features(timing_filter PUBLIC cxx_std_11)

#=== Test target ===

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES_TEST "test/*.cpp")
#
add_executable(run_tests ${SOURCES_TEST} src/filter.cpp)

# Link with the google test libraries.
target_link_libraries(run_tests ${GTEST_LIBRARIES} )

#define C++11 as the standard.
#set_property(TARGET run_tests PROPERTY CXX_STANDARD 11)
target_compile_features(run_tests PUBLIC cxx_std_11)
