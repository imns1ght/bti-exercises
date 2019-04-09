#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota

using Compare = bool (*)(const int &, const int&); // Useful alias

void bubble_sort(int *first, int *last, Compare cmp);

#endif