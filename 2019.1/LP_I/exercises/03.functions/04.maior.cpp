/* Exercı́cio 04
 * 
 * Escreva um programa para ler dois números reais e escrever o maior deles. O maior
 * dos números deve ser determinado por uma função inline, chamada max, que recebe dois
 * números reais passados por valor, determina o maior dos dois valores e retorna este valor.
 */

#include <iostream>

using namespace std;

inline float max(float a, float b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	float a, b;

	cout << "Número 01: ";
	cin >> a;
	cout << "Número 02: ";
	cin >> b;

	cout << endl << "Maior: " << max(a, b) << endl;

	return 0;
}
