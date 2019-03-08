#include "table.h"

int readHeader(ifstream &headerItems, vector<string> &hItems)
{
	string n; // Header item

	// Keeps reading until EOF.
	while (getline(headerItems, n)) { 	
		hItems.push_back(n); // Insert the number in the vector
	}

	// If EOF isn't reached
	if (!headerItems.eof()) { 
		cerr << ">>> Header error!" << endl ;
		return 1;
	}

	return 0;
}

int readInteger(ifstream &numbers, vector<int> &cellNumbers)
{
	int integer; 			// The number in int
	string strInt; 			// The number in string

	// Read numbers from the stream and add to the vector
	while (!numbers.eof()) { 		// If EOF isn't reached
		numbers >> strInt; 		// Get the number (string).
		istringstream iss(strInt); 	// Associate the stream iss with the number
		iss >> integer >> std::ws; 	// Convert from string to int
		cellNumbers.push_back(integer); // Insert the number in the vector

		// Verify the integer
		if ((iss.fail())) {
			cerr << "readInteger (): Error, illegal integer format.\n";
			strInt.clear(); 	// Clear string, try again ...
			return 1;
		} 
	}

	return 0;
}