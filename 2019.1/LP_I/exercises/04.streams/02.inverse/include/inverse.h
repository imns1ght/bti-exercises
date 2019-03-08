#ifndef INVERSE_H
#define INVERSE_H

#include <iostream> // std::cout, std::cin
#include <fstream>  // std::ifstream
#include <string>   // std::string
#include <vector>   // std::vector

using namespace std;

/**!
 * Asks user for the name of an input file , tries to open
 * the file and assigns it to the ifstream passed as reference .
 * If the input file name provided by the user does not exist ,
 * the function keeps asking the user to try again .
 *
 * \param ifs_ Reference to the input file stream we want to open.
 * \param msg_ Message to show to the user, asking for a file name.
 * \return A string with the input file name provided by the user.
 */
string askUserFileName(ifstream &ifs_, string msg_ = "") 
{
	string fileName;
	
	while (true) { // Keep asking the file name until a valid name is provided .
		cout << msg_ ; // Show message .
		getline(cin, fileName); // Get the file name .
		ifs_.open (fileName.c_str()); // Try to open the file .
		
		cout << endl;
		if (!ifs_.fail()) {
			return fileName; // Job done !
		}
		
		fileName.clear(); // Clear file name, try again ...
		cout << ">>> Unable to open the file. Try again .\n" ;

		if (msg_ == "") {
			msg_ = ">>> Enter file name: ";
		}
	}
}

/**!
 * Write in the file "invertido.txt" the numbers read from "numbers.txt"
 * in reverse order.
 * 
 * \param ofs Reference to the output file stream we want to write.
 * \param numbers Vector of the numbers from "numbers.txt"
 */
void writeInverse(ofstream &ofs, vector<int> numbers)
{
	cout << ">>> Data written" << endl;
	for (auto i = numbers.end()-1; i != numbers.begin()-1; i--) {
        	ofs << *i << endl; // Send numbers to file
		cout << *i << " "; // Print the numbers on the console
	}
	cout << endl;
}

#endif