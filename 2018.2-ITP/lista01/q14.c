#include <stdio.h>

int main()
{
	int a, b, c = 0;

	scanf("%d%d%d", &a, &b, &c);
	printf("Resposta: %d", (a + b == c) || (a + c == b) || (b + c == a));

	return 0;
}