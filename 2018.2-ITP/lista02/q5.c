#include <stdio.h>

int main()
{
    int a = 0;

	printf("Digite o mês: ");
	scanf("%d", &a);

	if (a == 2) {
		printf("29 dias\n");
	} else if ((a == 4) || (a == 6) || (a == 9) || (a == 11)) {
		printf("30 dias\n");
	} else {
		printf("31 dias\n");
	}

	return 0;	
}
