#include <stdio.h>
#include <string.h>

#define SIZE 30

int main()
{
	char filename[SIZE], word[SIZE], bigger[SIZE];	
	FILE *file;

	printf("Digite o nome do arquivo: ");
	scanf("%s", filename);
	file = fopen(filename, "r");

	if (file == NULL) {
		printf("Não foi possível abrir o arquivo.\n");
	} else {
		while (fscanf(file, "%s", word) != EOF) {
			if (strlen(bigger) < strlen(word)) {
				strcpy(bigger, word);
			}
		}
		printf("Maior palavra: %s\n", bigger);
	}
	fclose(file);

	return 0;
}