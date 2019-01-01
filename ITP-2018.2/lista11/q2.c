#include <stdio.h>

int main(void)
{
	int x; 				   /* Origem do fluxo */
	int m, n;	 		/* Linhas e Colunas */
	int muro[10][10];

	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &muro[i][j]);
		}
	}
	scanf("%d", &x);

	for (int i = 0; i < m; i++) {
		if (muro[i][x] == 1) {
			x--;
		} else if (muro[i][x] == 2) {
			x++;
		}

		if ((x > n - 1) || (x < 0)) {
			printf("ops\n");
			return 0;
		}
	}
	printf("%d\n", x);

	return 0;
}