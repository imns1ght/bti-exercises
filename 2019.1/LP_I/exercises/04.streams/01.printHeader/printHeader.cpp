#include <iomanip>   // setw, setfill
#include <iostream>  // cout, endl
#include <sstream>   // ostringstream
#include <string>    // std::string
#include <vector>    // vector

using namespace std;

/**!
* Print the table’s header to the terminal (std::cout).
* @param fields_ Reference to the list of header fields to be printed.
*/
void printHeader(const std::vector<std::string> &fields) {
        // Create the table
        ostringstream line, header;  // Stream associated with a string

        for (int i = 0; i < fields.size(); i++) {
                // Dividing line
                line << "+";
                line << setfill('-') << setw(fields[i].size() + 2) << "";
                // Columns
                header << "| " << fields[i] << " ";
        }

        // Prints the table
        cout << line.str() << "+" << endl;
        cout << header.str() << "|" << endl;
        cout << line.str() << "+" << endl;
}

int main() {
	// Header items
        std::vector<std::string> fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"};  
        printHeader(fieldNames);

        return EXIT_SUCCESS;
}