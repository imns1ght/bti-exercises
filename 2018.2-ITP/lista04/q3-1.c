#include <stdio.h>

int fatorial(int x);
int coefBinomial(int n, int k);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("O coeficiente binomial de %d, %d é: %d\n", n, k, coefBinomial(n, k));

	return 0;
}

int fatorial(int x) {
	int fat = 1;

	for (int i = 1; i <= x; i++) {
		fat *= i;			
	}
	
	return fat;
}

int coefBinomial(int n, int k) {
	int result = 0;

	result = fatorial(n)/(fatorial(k)*(fatorial(n - k)));

	return result;
}
