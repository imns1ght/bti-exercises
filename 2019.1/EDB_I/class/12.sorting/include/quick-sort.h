#ifndef QUICK_H
#define QUICK_H

#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance
#include <random>       // std::random_device std::mt19937
#include <numeric>      // iota
#include "../include/print-array.h"

using Compare = bool (*)(const int &, const int&); // Useful alias

void quick_sort(int *first, int *last, Compare cmp);
int * partition(int *first, int *last, Compare cmp);

#endif