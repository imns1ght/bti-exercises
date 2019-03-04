/* Exercı́cio 03 
 * Escreva um programa para ler dois números reais e escrever o maior deles. O maior
 * dos números deve ser determinado por uma função, chamada max, que recebe três parâmetros:
 * dois números passados por valor e uma variável real passada por referência que armazenará o
 * valor do maior dos dois números passados por valor. A sua função não deve retornar nenhum
 * valor (isto é, o tipo de retorno da função é void).
 */

#include <iostream>

using namespace std;

void max(float a, float b, float &maior)
{
	if (a > b) {
		maior = a;
	} else {
		maior = b;
	}
}

int main(void)
{
	float a, b, maior;

	cout << "Número 01: ";
	cin >> a;
	cout << "Número 02: ";
	cin >> b;

	max(a, b, maior);
	cout << endl << "Maior: " << maior << endl;

	return 0;
}