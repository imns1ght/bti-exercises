#include <stdio.h>
#include <string.h>

int main()
{
	int gols1, gols2, partidas, pontos;
    	char time0[20], time1[20], time2[20];
    	FILE *ftimes, *fpartidas, *fclassificacao;

    	ftimes = fopen("times.txt", "r");
    	fpartidas = fopen("partidas.csv", "r");
    	fclassificacao = fopen("classificacao.txt", "w");

    	if (ftimes == NULL || fpartidas == NULL) {
		printf("Nao foi possivel abrir um arquivo\n");
    	} else {
		while (fscanf(ftimes, "%s", time0) != EOF) {
			partidas = 0, pontos = 0;
			while (fscanf(fpartidas, "%s %d %d %s", time1, &gols1, &gols2, time2 ) != EOF) {
				if (!strcmp(time0, time1)) {
					partidas++;
					if (gols1 > gols2) {
						pontos += 3;
					} else if (gols1 == gols2) {
						pontos += 1;
					}
				} else if (!strcmp(time0, time2)) {
					partidas++;
					if (gols1 < gols2) {
						pontos += 3;
					} else if (gols1 == gols2) {
						pontos += 1;
					}
				}
			}
			fseek(fpartidas, 0, SEEK_SET);
			fprintf(fclassificacao, "%s %d %d\n", time0, partidas, pontos);
		}
	}

    	fclose(ftimes);
    	fclose(fpartidas);
    	fclose(fclassificacao);

    	return 0;
}