#include <stdio.h>

float media(float notas[], int n);

int main()
{
	int n;
	int acima = 0;
	float notas[30];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%f", &notas[i]);
	}

	for (int j = 0; j < n; j++) {
		if (notas[j] >= media(notas, n)) {
			acima++;
		}
	}

	printf("%d\n", acima);


	return 0;
}

float media(float notas[], int n) {
	float soma = 0;
	float media = 0;
	
	for (int i = 0; i < n; i++) {
		soma += notas[i];
	}
	
	media = soma / n;

	return media;
}
