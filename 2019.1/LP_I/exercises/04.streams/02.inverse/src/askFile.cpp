#include "../include/askFile.h"

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