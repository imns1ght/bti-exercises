#include <stdio.h>

int main()
{
	int a, b, c = 0;

	printf("Digite A: ");
	scanf("%d", &a);
	printf("Digite B: ");
	scanf("%d", &b);

	printf("Digite C: ");
	scanf("%d", &c);

	if ((a + b == c) || (a + c == b) || (b + c == a)) {
		printf("Um dos números é a soma dos outros dois\n");
	} else {
		printf("Nenhum dos números é a soma dos outros dois\n");
	}

	return 0;	
}
