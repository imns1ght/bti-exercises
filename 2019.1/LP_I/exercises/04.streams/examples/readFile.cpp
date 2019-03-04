#include <iostream> // std :: cout , std :: cin
#include <fstream> // std :: ifstream
#include <string> // std :: string

using namespace std;

/**!
 * Asks user for the name of an input file , tries to open
 * the file and assigns it to the ifstream passed as reference .
 * If the input file name provided by the user does not exist ,
 * the function keeps asking the user to try again .
 *
 * @param ifs_ Reference to the input file stream we want to open.
 * @param msg_ Message to show to the user, asking for a file name.
 * @return A string with the input file name provided by the user.
 */
string askUserFileName(ifstream & ifs_, string msg_ = "") {
	string fileName;
	
	while (true) { // Keep asking the file name until a valid name is provided .
		cout << msg_ ; // Show message .
		getline(cin, fileName); // Get the file name .
		ifs_.open (fileName.c_str()); // Try to open the file .
		
		if (!ifs_.fail()) {
			return fileName; // Job done !
		}
		
		fileName.clear(); // Clear file name, try again ...
		cout << "Unable to open the file. Try again .\n" ;
	
		if (msg_ == "") {
			msg_ = "Enter file name: ";
		}
	}
}

int main () {
	ifstream ifs;
	askUserFileName(ifs, "Please, enter a file name: ");
	// Read char by char //
	char ch; // Stores the char we read from the input file.
	
	while(ifs.get(ch)) { // Keeps reading until EOF.
		cout.put(ch); // Just print the character on the screen.
	}

	// Read lines //
	// 
	// string line;
	
	// while(getline(ifs, line)) { // Keeps reading until EOF.
	//	cout << line << endl;
	// }

	
	ifs.close();

	return EXIT_SUCCESS;
}
