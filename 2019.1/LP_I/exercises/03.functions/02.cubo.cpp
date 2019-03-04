/* Exercı́cio 02
 *
 * Escreva um programa para ler um número real, digamos x, e produzir como saı́da o
 * cubo deste número. O cálculo do cubo deve ser realizado por uma função, denominada cubo,
 * que recebe como parâmetro, por referência, um único número real, calcula o cubo deste número,
 * armazena o resultado no próprio parâmetro e não retorna valor (isto é, o tipo de retorno da
 * função é void).
 */

#include <iostream>

using namespace std;

void cubo(float &x)
{
	x = x * x * x;
}

int main(void)
{
	float x;

	cin >> x;	
	cubo(x);
	cout << x << endl;

	return 0;
}