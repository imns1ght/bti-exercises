#include <stdio.h>

int fatorial(int x);

int main()
{
	int x;
	scanf("%d", &x);
	printf("O fatorial de %d é: %d\n", x, fatorial(x));

	return 0;
}

int fatorial(int x) {
	int fat = 1;

	for (int i = 1; i <= x; i++) {
		fat *= i;			
	}
	
	return fat;
}
