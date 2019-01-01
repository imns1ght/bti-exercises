#include <stdio.h>

int main()
{
	int a, b, c = 0;

	printf("Quantos pontos possui o time: ");
	scanf("%d", &a);
	printf("Quantas partidas restam: ");
	scanf("%d", &b);
	printf("Quantos pontos são necessários: ");
	scanf("%d", &c);

	if (a >= c) {
		printf("O time já está classificado\n");
	} else if (a + (b * 3) >= c) {
		printf("É possível se classificar\n");
	} else {
		printf("Não é possível se classificar\n");
	}

	return 0;	
}
