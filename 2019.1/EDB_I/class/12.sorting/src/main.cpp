#include "../include/compare.h"
#include "../include/print-array.h"
#include "../include/insertion-sort.h"
#include "../include/selection-sort.h"
#include "../include/bubble-sort.h"
#include "../include/quick-sort.h"
#include "../include/merge-sort.h"

constexpr int ARR_SZ = 10; // Default array size.

int main()
{
	// ================================================================================
	// PREPARATION
	// --------------------------------------------------------------------------------
	int source[ARR_SZ]; // Source data array.

	// Fills the range [first, last) with sequentially increasing values
	std::iota(std::begin(source), std::end(source), 1); 

#ifndef RANDOM
	std::random_device rd;
	std::mt19937 g(rd());
#else
	std::mt19937 g(100);
#endif
	std::shuffle(std::begin(source), std::end(source), g); 

	int destination[ARR_SZ]; // Sorted array by the insertion sort.
	std::fill(std::begin(destination), std::end(destination), 0); // Fill array with zeros.

	// ================================================================================
	std::cout << ">>> INSERTION SORT <<<\n\n";
	// --------------------------------------------------------------------------------
	
	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));
	std::cout << ">>> Destination vetor\n";
	print_array( std::begin(destination), std::end(destination));

	auto last = std::begin(destination);// The last is equal to first, empty array.
	for (const auto &e: source) {
		std::cout << "\n>>> Inserting " << e << std::endl;
		last = insertion_sort(std::begin(destination), last, e, compare_ints);
		print_array(std::begin(destination), std::end(destination));
	}

	// ================================================================================
	std::cout << "\n\n>>> SELECTION SORT <<<\n\n";
	// --------------------------------------------------------------------------------	
	std::shuffle(std::begin(source), std::end(source), g); 
	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));

	selection_sort(std::begin(source), std::end(source), compare_ints);

	std::cout << ">>> Destination vetor\n";
	print_array(std::begin(source), std::end(source));
	
	// ================================================================================
	std::cout << "\n\n>>> BUBBLE SORT <<<\n\n";
	// --------------------------------------------------------------------------------
	std::shuffle(std::begin(source), std::end(source), g);
	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));

	bubble_sort(std::begin(source), std::end(source), compare_ints);
	
	std::cout << ">>> Destination vetor\n";
	print_array(std::begin(source), std::end(source));
	
	// ================================================================================
	std::cout << "\n\n>>> QUICK SORT <<<\n\n";
	// --------------------------------------------------------------------------------
	std::shuffle(std::begin(source), std::end(source), g);
	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));

	quick_sort(std::begin(source), std::end(source), compare_ints);
	
	std::cout << ">>> Destination vetor\n";
	print_array(std::begin(source), std::end(source));

	// ================================================================================
	std::cout << "\n\n>>> MERGE SORT <<<\n\n";
	// --------------------------------------------------------------------------------
	std::shuffle(std::begin(source), std::end(source), g);
	std::cout << ">>> Data source\n";
	print_array(std::begin(source), std::end(source));

	mergesort(std::begin(source), std::end(source));
	
	std::cout << ">>> Destination vetor\n";
	print_array(std::begin(source), std::end(source));

	std::cout << std::endl;

	return EXIT_SUCCESS;
}