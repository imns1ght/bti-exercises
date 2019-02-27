#include <stdio.h>

int qtdDivisores(int x);

int main()
{
	int x;
	scanf("%d", &x);
	printf("Quantidade de divisores: %d\n", qtdDivisores(x));

	return 0;
}

int qtdDivisores(int x) {
	int qtd = 0;

	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			qtd++;
		}
	}

	return qtd;
}
