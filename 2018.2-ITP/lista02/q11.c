#include <stdio.h>

int main() 
{
	int renda, cred = 0;

	printf("Digite a renda mensal: ");
	scanf("%d", &renda);

	if ((renda < 700) && (renda >= 0)) {
		printf("Resultado: alto risco\n");
	
	} else if ((renda < 3200) && (renda >= 700)){
		printf("Digite se o histórico de crédito é bom: ");
		scanf("%d", &cred);

		if (cred) {
			printf("Resultado: médio risco\n");
		} else {
			printf("Resultado: alto risco\n");
		}

	} else if (renda >= 3200) {
		printf("Digite se o histórico de crédito é bom: ");
		scanf("%d", &cred);

		if (cred) {
			printf("Resultado: baixo risco\n");
		} else {
			printf("Resultado: médio risco\n");
		}
	}

	return 0;
}
