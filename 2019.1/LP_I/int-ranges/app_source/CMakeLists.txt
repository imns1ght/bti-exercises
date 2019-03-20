cmake_minimum_required(VERSION 3.5)
project (DriverIntRante)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#Include dir
include_directories( include )

#=== Driver App ===
# Define where the linker should look for libraries at
link_directories( ${CMAKE_SOURCE_DIR}/lib ) # The library is locally installed.

# Define the sources
add_executable(driver_int_ranges "src/driver.cpp")

# Define the lib to link to.
target_link_libraries(driver_int_ranges PRIVATE IntRange )

