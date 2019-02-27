/* Problem V
 * Read a value N. Calculate and write its corresponding factorial. Factorial 
 * of N = N * (N-1) * (N-2) * (N-3) * ... * 1
 *
 * Implement both iterative/recursive versions.
 */
#include <iostream>

int iterativeFactorial(int n);
int recursiveFactorial(int n);

using namespace std;

int main()
{
	int n;
	char option;

	cout << ">>> Input: ";
	cin >> n;
	
	do {
		cout << ">>> [I]terative or [R]ecursive? ";
		cin >> option;
	} while (option != 'I' && option != 'R');

	if (option == 'I') {
		cout << ">>> Result: " << iterativeFactorial(n) << endl;
	} else {
		cout << ">>> Result: " << recursiveFactorial(n) << endl;
	}

	return 0;
}

int iterativeFactorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

int recursiveFactorial(int n)
{
    	if (n > 1) {
        	return n * recursiveFactorial(n - 1);
    	} else {
        	return 1;
    	}
}