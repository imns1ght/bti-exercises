#include <iostream> // cout, endl
#include <string>   // std::string
#include <iomanip>  // setw, setfill
#include <vector>   // vector
#include <sstream> // ostringstream

using namespace std;

/**!
* Print the table’s header to the terminal (std::cout).
* @param fields_ Reference to the list of header fields to be printed.
*/
void printHeader(const std::vector< std::string > & fields)
{
/* Print a vector
 * Version 1:
	for (auto i{0}; i < fields.size(); i++) {
		cout << fields[i] << ", ";
	}
	cout << endl;

 * Version 2:
	for (auto it = fields.begin(); it != fields.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

 * Version 3:
	for (const auto &e : fields) {
		cout << e << ", ";
	}
	cout << endl;
*/
	// Create the table
	ostringstream line, header; // Stream associated with a string

	for (auto i{0}; i < fields.size(); i++) {
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

int main()
{
	std::vector<std::string> fieldNames = {"ITEM", "QUANTIDADE", "VALOR UNITARIO"}; // Header items

	printHeader(fieldNames); // Imprimir cabecalho da tabela.
	return EXIT_SUCCESS;
}