#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, p, pos, qtdIdosos = 0, same = 0;
	int *fila, *filaFinal;

	scanf("%d %d" , &n, &pos);
	fila = malloc(sizeof(int)*n);
	filaFinal = malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &fila[i]);
	}
	p = fila[pos-1]; 

	for (int i = 0; i < pos-1; i++) {
		if (fila[i] == fila[pos-1]) {
			same++;
		}
	}

	/* Calcula quantos idosos e os armazena */
	for (int i = 0; i < n; i++) {
		if (fila[i] >= 65) {
			filaFinal[qtdIdosos] = fila[i];
			qtdIdosos++;
		}
	}

	/* Armazena os não-idosos */
	for (int i = 0, tmp = qtdIdosos; i < n; i++) {
		if (fila[i] < 65) {
			filaFinal[tmp] = fila[i];
			tmp++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (filaFinal[i] == p && same == 0) {
			printf("%d\n", i+1);
			break;
		} else if (filaFinal[i] == p) {
			same--;
		}
	}

	return 0;
}