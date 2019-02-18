#include <stdio.h>

int main()
{
	int	m; /* Números sorteados */
	int n; /* Números da aposta */ 
	int acertos = 0;
	int sort[30];
	int apost[50];

	scanf("%d %d", &m, &n);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &sort[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &apost[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (sort[i] == apost[j]) {
				acertos++;
			}	
		}
	}

	printf("%d\n", acertos);

	return 0;
}
