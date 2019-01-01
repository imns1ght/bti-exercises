#include <stdio.h>
#include <string.h>

void setLetrasMin(char letrasMin[]);
void setLetrasMai(char letrasMai[]);
void setOcorrenciasMai(int ocorrenciasMai[]);
void setOcorrenciasMin(int ocorrenciasMin[]);

int main()
{
    char frase[200];
    char letrasMai[27];
    char letrasMin[27];
    int ocorrenciasMai[27];
    int ocorrenciasMin[27];

    setLetrasMai(letrasMai);
    setLetrasMin(letrasMin);
    setOcorrenciasMai(ocorrenciasMai);
    setOcorrenciasMin(ocorrenciasMin);

    fgets(frase, 200, stdin);

    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ' && frase[i] != '\n' && frase[i] != '\0') {
            for (int j = 0; j < strlen(letrasMai); j++) {
                if (frase[i] == letrasMai[j]) {
                    ocorrenciasMai[j]++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ' && frase[i] != '\n' && frase[i] != '\0') {
            for (int j = 0; j < strlen(letrasMin); j++) {
                if (frase[i] == letrasMin[j]) {
                    ocorrenciasMin[j]++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        if (ocorrenciasMai[i] != 0) {
            printf("%c: %d\n", letrasMai[i], ocorrenciasMai[i]);
        }
    }

    for (int i = 0; i < 25; i++) {
        if (ocorrenciasMin[i] != 0) {
            printf("%c: %d\n", letrasMin[i], ocorrenciasMin[i]);
        }
    }

    return 0;
}

void setLetrasMai(char letrasMai[])
{
    for (int i = 0; i < 26; i++) {
        letrasMai[i] = i+65;

        if (i == 25) {
            letrasMai[i+1] = '\0';
        }
    }
}

void setLetrasMin(char letrasMin[])
{
    for (int i = 0; i < 26; i++) {
        letrasMin[i] = i+97;

        if (i == 25) {
            letrasMin[i+1] = '\0';
        }
    }
}

void setOcorrenciasMai(int ocorrenciasMai[])
{
   for (int i = 0; i < 27; i++) {
		ocorrenciasMai[i] = 0;
    }
}

void setOcorrenciasMin(int ocorrenciasMin[])
{
   for (int i = 0; i < 27; i++) {
		ocorrenciasMin[i] = 0;
    }
}
