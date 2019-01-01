#include <stdio.h>

int qtdDivisores(int x);
int ehPrimo(int x);

int main()
{
	int x;
	scanf("%d", &x);
	printf("É primo? %d\n", ehPrimo(x));

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

int ehPrimo(int x) {
	if (qtdDivisores(x) == 2) {
		return 1;
	} else {
		return 0;
	}
}
