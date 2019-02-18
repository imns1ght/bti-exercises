#include <stdio.h>

int main()
{
	int n, max = 0, numMeses = 0, zeros = 0; 						/* Quantidade de meses */
	int diasChuvosos[20];
	int meses[20];

	scanf("%d", &n);
	
	/* Set diasChuvosos[] */
	for (int i = 0; i < n; i++) {
		scanf("%d", &diasChuvosos[i]);
	}
	
	/* Set meses[] = 0 */
	for (int i = 0; i < n; i++) {
		meses[i] = 0;
	}

	max = diasChuvosos[0];
	/* Define os meses chuvosos e a quantidade máxima */
	for (int i = 0; i < n; i++) {
		if (max <= diasChuvosos[i]) {
			max = diasChuvosos[i];
			meses[i] = i+1;
			numMeses++;
		}
	}
	
	/* Zera elementos de meses[] que não condizem com o valor máximo */
	for (int i = 0; i < numMeses; i++) {
		if (max != diasChuvosos[i]) {
			meses[i] = 0;
		}
	}

	/* Imprime na tela o resultado final */
	for (int i = 0; i < n; i++) {
		if (meses[i] != 0) {
			printf("%d ", meses[i]);
		} 	
	}
	printf("%d\n", max);

	return 0;
}
