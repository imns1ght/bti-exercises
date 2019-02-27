#include <stdio.h>

int maiorDos2(int a, int b);
int maiorDos3(int a, int b, int c);

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("O maior número é %d\n", maiorDos3(a, b, c));

	return 0;
}

int maiorDos2(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int maiorDos3(int a, int b, int c) {
	if (maiorDos2(a, b) > c) {
		return maiorDos2(a, b);
	} else {
		return c;
	}
}
