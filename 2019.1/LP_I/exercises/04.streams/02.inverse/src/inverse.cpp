#include "../include/inverse.h"

void writeInverse(ofstream &ofs, vector<int> numbers)
{
	cout << ">>> Data written" << endl;
	for (auto i = numbers.end()-1; i != numbers.begin()-1; i--) {
        	ofs << *i << endl; // Send numbers to file
		cout << *i << " "; // Print the numbers on the console
	}
	cout << endl;
}