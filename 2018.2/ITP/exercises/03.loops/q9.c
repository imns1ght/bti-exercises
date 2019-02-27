#include <stdio.h>

int main()
{
	int n, soma = 0;
	scanf("%d", &n);

	if (n > 0) {
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				soma += i;
			}
		}

		if (soma == n) {
			printf("Perfeito\n");
		} else {
			printf("Não perfeito\n");
		}
	}

	return 0;
}
