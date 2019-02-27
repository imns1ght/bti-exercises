/* Problem III
 * 
 * Your job in this problem is to read a number that is a column of an array where
 * an operation will be performed, an uppercase character, indicating the operation
 * to be performed and all elements of a bidimentional array M[12][12]. Then, you 
 * have to calculate and print the sum or average of all elements within the green 
 * area according to the case. The following figure illustrates the case when is 
 * entered the number 5 to the array column, showing all elements that must be 
 * considered in the operation.
 */
#include <iostream>

#define SIZE 12

using namespace std;

int main()
{
	int C;
	char T;
	float result = 0;
	float M[SIZE][SIZE];
	
	do {
		cout << ">>> Column: ";
		cin >> C;
	} while (C < 0 || C > 11);

	do {
		cout << ">>> Operation ([S]um or [A]verage): ";
		cin >> T;
	} while (T != 'S' && T != 'A');

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << "M[" << i << "][" << j << "]: ";
			cin >> M[i][j];
		}
	}
	
	cout.precision(1);
	if (T == 'S') {
		for (int i = 0; i < SIZE; i++) {
			result += M[i][C];
		}

		cout << ">>> Result: " << fixed << result << endl;

	} else if (T == 'A') {
		for (int i = 0; i < SIZE; i++) {
			result += M[i][C];
		}

		result /= SIZE;
		cout << ">>> Result: " << fixed << result << endl;
	}

	return 0;
}