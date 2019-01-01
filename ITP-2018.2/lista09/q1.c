#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    int matricula;
    char fString[20];
    float n1, n2, n3;
    FILE *file;

    file = fopen("notas.csv", "r");
    scanf("%s", nome);

    if(file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        int error;
        while(fscanf(file, "%d %s %f %f %f", &matricula, fString, &n1, &n2, &n3) != EOF) {
            if (!strcmp(nome, fString)) {
                printf("%d %.2f\n", matricula, (n1+n2+n3)/3);
                error = 0;
                break;
            } else {
                error = 1;
            }
        }       

        if (error) {
            fprintf(stderr, "%s", "não encontrado\n");
        }    
    }

    fclose(file);

    return 0;
}