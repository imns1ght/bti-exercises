cmake_minimum_required(VERSION 3.5)
project (SortedInsert VERSION 1.0.0 LANGUAGES CXX )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 14)
#--------------------------------

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -g" )

#=== Test Writing with TinyXML2 target ===
add_executable(si "sorted_insert.cpp")

#define C++17 as the standard.
set_property( TARGET si
              PROPERTY CXX_STANDARD 14)
