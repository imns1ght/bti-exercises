/* Exercı́cio 01
 *
 * Escreva um programa para ler um número real, digamos x, e produzir como saı́da
 * o cubo deste número. O cálculo do cubo deve ser realizado por uma função, denominada
 * cubo, que recebe como parâmetro um único número real e retorna o valor do cubo do número
 * recebido.
 */

#include <iostream>

using namespace std;

float cubo(float x)
{
	return x * x * x;
}

int main(void)
{
	float x;
	cin >> x;

	cout << cubo(x) << endl;

	return 0;
}