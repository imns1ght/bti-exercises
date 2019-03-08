#include "../include/table.h"

int main(int argc, char *argv[])
{
	vector<string> hItems;			// Vector to store header items
	vector<int> cellNumbers;		// Vector to store the numbers for the table
	ifstream headerItems(argv[1]);	// Header items
	ifstream numbers(argv[2]); 		// Numbers for table

	readHeader(headerItems, hItems);
	readInteger(numbers, cellNumbers);
	printTable(hItems, cellNumbers);

	headerItems.close();
	numbers.close();
	
	return 0;
}
