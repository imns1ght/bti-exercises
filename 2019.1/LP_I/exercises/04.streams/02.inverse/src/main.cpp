/* Exercise 2
 *
 * Neste exercı́cio você deve ler uma sequência de inteiros de comprimento desconhecido a partir de
 * um arquivo de entrada fornecido pelo usuário. Você, então, deve armazenar os números lidos em um
 * std::vector e depois abrir um arquivo de saı́da invertido.txt e gravar os mesmo números na
 * ordem inversa que foram lidos, um por linha.
 */

#include "../include/askFile.h"
#include "../include/inverse.h"

int main(void) {
        int n;
        vector<int> numbers;  // Store the numbers we read from the input file.

        ifstream ifs;  // Input
        askUserFileName(ifs, ">>> Please, enter a file name: ");
        ofstream ofs("../data/invertido.txt");  // Output

        // Keeps reading until EOF.
        while (ifs >> n) {
                numbers.push_back(n);
        }

        if (!ifs.eof()) {  // If EOF isn't reached
                cerr << ">>> Data error in file!" << endl;
                return EXIT_FAILURE;
        } else {
                cout << ">>> Data successfully read" << endl;
        }

        // Numbers read from file
        for (auto i = numbers.begin(); i != numbers.end(); i++) {
                cout << *i << " ";
        }
        cout << endl
             << endl;

        writeInverse(ofs, numbers);

        ifs.close();
        ofs.close();

        return EXIT_SUCCESS;
}
