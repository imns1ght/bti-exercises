#include "../include/table.h"

void printTable(const vector<string> &hItems, const vector<int> &cellNumbers) {
        ostringstream line, header, numbers;    // Streams associated with table structure
        ofstream output("../data/output.txt");  // Stream associated with the result (table)

        // Create header
        for (int i = 0; i < hItems.size(); i++) {
                // Dividing line
                line << "+";
                line << setfill('-') << setw(hItems[i].size() + 2) << "";
                // Columns
                header << "| " << hItems[i] << " ";
        }

        // Print header
        output << line.str() << "+" << endl;
        output << header.str() << "|" << endl;
        output << line.str() << "+" << endl;

        // Create the structure for the numbers
        int cont = 0;
        while (cont < cellNumbers.size()) {
                for (int j = 0; j < hItems.size(); j++) {
                        numbers << "| " << setw(hItems[j].size()) << cellNumbers[cont] << " ";
                        cont++;
                }

                numbers << "|" << endl;
        }

        // Print numbers
        output << numbers.str();
        output << line.str() << "+" << endl;

        output.close();
}