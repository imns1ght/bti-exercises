#include "../include/print-array.h"

void print(int *first, int *last)
{
	std::cout << "[ ";
	while (first != last) {
		std::cout << *first++ << " ";
	}
	std::cout << "]";
}

/// Prints the elemets of the specified range on the standard output stream.
void print_array(const int * first, const int * last)
{
	std::cout << "\tArray: [ ";
	std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
	std::cout << "]\n";
}