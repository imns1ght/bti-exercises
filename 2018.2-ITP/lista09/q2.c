#include <stdio.h>
#include <string.h>

int main()
{
    int matricula;
    char fString[20];
    float n1, n2, n3;
    FILE *file, *file2;

    file = fopen("notas.csv", "r");
    file2 = fopen("aprovados.txt", "w");

    if(file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        while(fscanf(file, "%d %s %f %f %f", &matricula, fString, &n1, &n2, &n3) != EOF) {
            if (((n1+n2+n3)/3) >= 7) {
                fprintf(file2, "%d %s\n", matricula, fString);
            }
        }       
    }

    fclose(file);

    return 0;
}