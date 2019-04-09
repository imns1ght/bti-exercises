#include "../include/selection-sort.h"

void selection_sort(int *first, int *last, Compare cmp)
{
	int *min;
	
	while (first != last-1) {
		min = first;
		
		// Finds the min value of the range [first+1, last)
		for (auto i = first+1; i < last; i++) {
			if (cmp(*i, *min)) {
				min = i;
			}
		}
		std::swap(*min, *first); 
		first++;
	}
}