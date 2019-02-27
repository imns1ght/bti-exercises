#include <stdio.h>

int main(void)
{
	int n, tmp, soma;
	int cubo[10][10];

    	scanf("%d", &n);

    	/* Leitura da matriz */
    	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
	    		scanf("%d", &cubo[i][j]);
		}
    	}
	
    	for (int j = 0; j < n; j++) {
		tmp = soma;
		soma = 0;
		for (int i = 0; i < n; i++) {
			soma += cubo[i][j];
		}

		if (j > 0) {
			if (tmp != soma) {
				printf("não\n");
				return 0;
			}
		}
    	}
	printf("sim\n");

    	return 0;
}