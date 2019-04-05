#include "../include/bubble-sort.h"

void bubble_sort(int *first, int *last, Compare cmp)
{	
	for (int *i = first; i < last-1; i++) {
		for (int *j = first; j < (first + std::distance(i, last))-1; j++) {
			// Swap the adjacent element if it is smaller
			if (cmp(*(j+1), *j)) {
				std::swap(*(j+1), *j);
			}
		}
	}	
}
