#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

int main()
{
	int num[27];
	char filename[SIZE], word[SIZE];
	FILE *file, *fletters;

	for (int i = 0; i < 27; i++) {
		num[i] = 0;
	}

	printf("Digite o nome do arquivo: ");
	scanf("%s", filename);
	file = fopen(filename, "r");
	fletters= fopen("fletters.txt", "w");

	if (file == NULL) {
		printf("Não foi possível abrir o arquivo.\n");
	} else {
		while (fscanf(file, "%s", word) != EOF) {
			for(int i = 0; i < strlen(word); i++) {
 				word[i] = tolower(word[i]);
			}

			for (int i = 0; i < strlen(word); i++) {
				if (word[i] >= 97 && word[i] <= 122) {
					num[word[i] - 97]++;
				}
			}
		}

		for (int i = 0, c = 97; i < 26; i++, c++) {
			fprintf(fletters, "%c %d\n", c, num[i]);
		}
	}
	fclose(file);
	fclose(fletters);

	return 0;
}