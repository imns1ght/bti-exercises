#include <iostream>

using namespace std;

int * filter(int *first, int *last);

int main(void)
{
	int *first, *last;
	int foo [10] = {-3, 4, 8, 0, -2, 7, 0, 12, -1, 10}; 

	first = &foo[0];
	last = &foo[10];

	cout << ">>> ";
	for (int i = 0; i < 10; i++) {
		cout << foo[i] << " ";
	}
	cout << endl;

	int *tmp = filter(first, last);
	cout << tmp << endl;

	return 0;
}

int * filter(int *first, int *last) 
{
	for (int i = 0; i < 10; i++) {
		if ((first + i) == NULL) {
			cout << *first;
		}
		cout << first[i] << endl;
	}

	return last;
}