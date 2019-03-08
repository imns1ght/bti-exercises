/* Exercise 3
 *
 * Desenvolva uma função denominada int getInteger(string msg_) que apresenta uma mensagem msg_
 * na tela solicitando um inteiro, recebe o inteiro e o retorna para o código cliente. 
 * A função deve ficar em laço solicitando um valor até que o usuário forneça um valor inteiro correto.
 */

#include "../include/integer.h"

int main(void) 
{ 	
	auto val = getInteger(">>> Please, enter a integer: "); 
	
	return 0;
}

int getInteger(string msg_)
{
	int integer; // The number in int
	string strInt; // The number in string

	while (true) { // Keep asking the integer until a valid number is provided .
		cout << msg_ ; // Show message .
		getline(cin, strInt); // Get the number (string).
		istringstream iss(strInt); // Associate the stream iss with the number
		iss >> integer >> std::ws; // Convert from string to int

		// Verify the integer
		if ((iss.fail()) || (!iss.eof())) {
			cerr << "getInteger (): Error, illegal integer format.\n";
			strInt.clear(); // Clear string, try again ...
		} else {
			return integer;	
		}	
	}
}