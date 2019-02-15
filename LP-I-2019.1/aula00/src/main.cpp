#include <iostream>

int main()
{
	int exp = 0;
	unsigned long long int result = 1;

	std::cout << ">>> This program lists the powers of 2, starting from 0.\n\n";
	
	do {
		std::cout << ">>> Type the expoent limit in [0, 63]\n";
		std::cout << ">>> Warning: you'll need to retype if you exceed the limit\n";
		std::cout << ">>> Input: ";
		std::cin >> exp;
	} while (exp < 0 || exp > 63);

	for (int i = 0; i <= exp; i++) {
		if (i == 0) {
			std::cout << "\n>>> 2 raised to the power of " << i << " is " << result << std::endl;
		} else {
			result *= 2;
			std::cout << ">>> 2 raised to the power of " << i << " is " << result << std::endl;
		}                
	}

	return 0;
}