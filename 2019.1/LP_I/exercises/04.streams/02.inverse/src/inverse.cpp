#include "../include/inverse.h"

int main (void) 
{
	int n; 		     
	vector<int> numbers; // Store the numbers we read from the input file.

	ifstream ifs; 
	askUserFileName(ifs, ">>> Please, enter a file name: "); 
	ofstream ofs ("../data/invertido.txt");
	
	// Keeps reading until EOF.
	while (ifs >> n) { 	
		numbers.push_back(n);
	}

	if (!ifs.eof()) { // If EOF isn't reached
		cerr << ">>> Data error in file!" << endl ;
		return EXIT_FAILURE;
	} else {
		cout << ">>> Data successfully read" << endl;
	}

	// Numbers read from file
	for (auto i = numbers.begin(); i != numbers.end(); i++) {
        	cout << *i << " "; 
	}
	cout << endl << endl;

	writeInverse(ofs, numbers);
	
	ifs.close();
	ofs.close();

	return EXIT_SUCCESS;
}

