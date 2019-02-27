#include <stdio.h>

void positions(int n, int larg[], int cheg[], int pilot[]);
void advantage(int n, int larg[], int cheg[], int pilot[]);

int main()
{
	int n, max = 0, empate = 0, location = 0; /* Quantidade de pilotos */
	int larg[20], cheg[20], pilot[20];

	for (int i = 0; i < 20; i++) {
		pilot[i] = 0;
	}

	scanf("%d", &n);

	positions(n, larg, cheg, pilot);
	advantage(n, larg, cheg, pilot);

	/* Define o piloto com maior vantagem */
	for (int i = 0; i < n; i++) {
		if (pilot[i] > max) {
			max = pilot[i];
			location = larg[i];
		}
	}

	/* Verifica se houve empate entre os competidores */
	for (int i = 0; i < n; i++) {
		if (pilot[i] == max) {
			empate++;
		}

		if (empate > 1) {
			printf("empate\n");
			return 0;
		}
	}

	printf("%d\n", location);

	return 0;
}

/* Define as posições de largada e chegada dos pilotos */
void positions(int n, int larg[], int cheg[], int pilot[])
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &larg[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &cheg[i]);
	}
}

/* Define a vantagem entre os pilotos */
void advantage(int n, int larg[], int cheg[], int pilot[])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (larg[i] == cheg[j]) {
				pilot[i] = i-j;
			}
		}
	}	
}
