#include <stdio.h>
#include <string.h>

int main()
{	
	int cod;
	char pOrigem[50], pDestino[50], fpOrigem[50], fpDestino[50];
    	FILE *fvoos;
	
	fvoos = fopen("voos.csv", "r");
	scanf("%s", pOrigem);
	scanf("%s", pDestino);

	if (fvoos == NULL) {
		printf("Nao foi possivel abrir um arquivo\n");
    	} else {
		while (fscanf(fvoos, "%d %s %s", &cod, fpOrigem, fpDestino) != EOF) {
			if (pOrigem[0] == '*' && pDestino[0] == '*') {
				printf("%d %s %s\n", cod, fpOrigem, fpDestino);
			} else if (pOrigem[0] == '*') {
				if (!strcmp(pDestino, fpDestino)) {
					printf("%d %s %s\n", cod, fpOrigem, fpDestino);
				}
			} else if (pDestino[0] == '*') {
				if (!strcmp(pOrigem, fpOrigem)) {
					printf("%d %s %s\n", cod, fpOrigem, fpDestino);
				}
			} else {
				if (!strcmp(pOrigem, fpOrigem) && !strcmp(pDestino, fpDestino)) {
					printf("%d %s %s\n", cod, fpOrigem, fpDestino);
				}
			}
		}
	}
	fclose(fvoos);

	return 0;
}