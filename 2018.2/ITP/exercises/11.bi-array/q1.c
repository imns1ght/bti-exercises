#include <stdio.h>

int main(void)
{
	int m, n;   /* Linhas x Colunas */
    	int qtdCobertos = 0, qtdNaoCobertos = 0;
    	int campo[10][10];

    	scanf("%d %d", &m, &n);

    	/* Leitura da matriz */
    	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
	    		scanf("%d", &campo[i][j]);
		}
    	}

    	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
	    		if (campo[i][j] == 1) {
				int cont = 0;
				if (i > 0 && campo[i-1][j] == 2) {
		    			cont++;
				} else if (j > 0 && campo[i][j-1] == 2) {
		    			cont++;
				} else if (j < n-1 && campo[i][j+1] == 2) {
		    			cont++;
				} else if (i < m-1 && campo[i+1][j] == 2) {
		    			cont++;
				}

				if (cont > 0) {
					qtdCobertos++;
				} else {
					qtdNaoCobertos++;
				}
	    		}
		}
   	 }
	printf("%d %d\n", qtdCobertos, qtdNaoCobertos);

    	return 0;
}