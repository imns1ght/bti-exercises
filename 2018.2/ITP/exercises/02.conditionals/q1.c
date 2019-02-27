#include <stdio.h>

int main()
{
	int a, b, c = 0;
	
	printf("Digite dois números inteiros: ");
	scanf("%d %d", &a, &b);

	printf("Números escolhidos: %d %d\n", a, b);

	c = a;
	a = b;
	b = c;

	printf("Números alternados: %d %d\n", a, b);

	return 0;
}
