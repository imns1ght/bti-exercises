#ifndef MERGE_H
#define MERGE_H

#include <iostream>     // cout, endl
#include <algorithm>    // suffle
#include <iterator>     // distance

void merge(int *firstL, int *lastL, int *firstR, int *lastR, int *firstA);
void mergesort(int *firstA, int *lastA);

#endif