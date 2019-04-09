#include "../include/insertion-sort.h"

int * insertion_sort(int *first, int *last, const int &e, Compare cmp)
{
	auto it(last);

	// Finds the position to alocate 'e'
	while ((it > first) && cmp(e, *(it-1))) {
		std::swap(*it, *(it-1));
		it--;
	}

	*it = e;

	return ++last;
}