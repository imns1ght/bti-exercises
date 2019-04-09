#include "../include/quick-sort.h"

void quick_sort(int *first, int *last, Compare cmp)
{
	if (first < last) {
		auto it = partition(first, last, cmp);
		quick_sort(first, it, cmp); // Left
		quick_sort(it+1, last, cmp); // Right
	}
}

int * partition(int *first, int *last, Compare cmp)
{
	auto slow = first; 
	auto fast = first;
	auto pivot = last-1;

	while (fast < last) {
		if (cmp(*fast, *pivot)) {
			std::swap(*slow, *fast);
			slow++;
		} 
		fast++;
	}
	std::swap(*pivot, *slow);

	return slow;
}