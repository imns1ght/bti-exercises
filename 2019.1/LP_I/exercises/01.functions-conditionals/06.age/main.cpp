/* Problem VI
 * 
 * Write an algorithm to read an undeterminated number of data, each containing an 
 * individual's age. The final data, which will not enter in the calculations, 
 * contains the value of a negative age. Calculate and print the average age of 
 * this group of individuals.
 */

#include <iostream>

using namespace std;

int main()
{
	int age = 0, n = 0;
	float result = 0;

	while (age >= 0) {
		cin >> age;
		
		if (age < 0) {
			cout << ">>> Average: " << (result / n) << endl;
			return 0;
		}
		
		result += age;
		n++;
	} 
}