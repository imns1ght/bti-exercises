#include <stdio.h>

#define ILHAS 10

int main()
{
	int indicacoes[ILHAS];
	int ocorrencias[ILHAS];	
	indicacoes[0] = 0;
	ocorrencias[0] = 1;
	
	for (int i = 1; i < ILHAS; i++) {
		ocorrencias[i] = 0;
	}

	for (int i = 1; i <= ILHAS; i++) {
		scanf("%d", &indicacoes[i]);
		ocorrencias[indicacoes[i]]++;
			
		if (ocorrencias[indicacoes[i]] > 1 && indicacoes[i] != indicacoes[i-1]) {
			printf("%d\n", indicacoes[i]);
			return 0;
		}
	} 
	
	printf("%d", 0);

	return 0;
}
