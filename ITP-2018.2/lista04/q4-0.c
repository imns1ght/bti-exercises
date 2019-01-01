#include <stdio.h>

int somaDivisoresProprios(int x);

int main()
{
	int x;
	scanf("%d", &x);
	printf("A soma dos divisores próprios de %d é: %d\n", x, somaDivisoresProprios(x));

	return 0;
}

int somaDivisoresProprios(int x) {
	int sum = 0;
	
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}

	return sum;	
}

