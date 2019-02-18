/* Problem IV
 * 
 * Read an uppercase character that indicates an operation that will be performed 
 * in an array M[12][12]. Then, calculate and print the sum or average considering 
 * only that numbers that are below of the Secundary diagonal of the array, 
 * like shown in the following figure (green area).
 */
#include <iostream>

#define SIZE 12

using namespace std;

int main()
{
	char O;
	float result = 0;
	float M[SIZE][SIZE];

	do {
		cout << ">>> Operation ([S]um or [A]verage): ";
		cin >> O;
	} while (O != 'S' && O != 'A');

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "M[" << i << "][" << j << "]: ";
			cin >> M[i][j];
		}
	}
	
	cout.precision(1);
	if (O == 'S') {
		for (int i = SIZE - 1, column = 0; column < SIZE; i--, column++) {
			result += M[i][column];
		}

		cout << ">>> Result: " << fixed << result << endl;

	} else if (O == 'A') {
		for (int i = SIZE - 1, column = 0; column < SIZE; i--, column++) {
			result += M[i][column];
		}

		result /= SIZE;
		cout << ">>> Result: " << fixed << result << endl;
	}

	return 0;
}