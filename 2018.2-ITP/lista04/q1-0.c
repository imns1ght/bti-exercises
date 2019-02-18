#include <stdio.h>

int maiorDos2(int a, int b);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("O maior número é %d\n", maiorDos2(a, b));

	return 0;
}

int maiorDos2(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
