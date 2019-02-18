/* Problem I
 *
 * Read a number X. Put this X at the first position of an array N[100]. 
 * In each subsequent position (1 up to 99) put half of the number inserted at the
 * previous position, according to the example below. Print all the vector N.
 */

#include <iostream>
#include <limits>

int main()
{
	double n [100];

	std::cout << ">>> Type a number: ";
	std::cin >> n[0];

	for (int i = 0; i < 100; i++) {
		if (i == 0) {
			n[i+1] = n[i] / 2;
			i++;
		} else {
			n[i] = n[i-1] / 2;
		}
	}
	
	std::cout.precision(4);
	for (int i = 0; i < 100; i++) {
		std::cout << "N[" << i <<"] = " << std::fixed << n[i] << std::endl;
	}

	return 0;
}