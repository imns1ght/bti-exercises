#include <stdio.h>
#include <string.h>

#define MAX 100

void setLetras(char letras[]);

int main()
{
    char frase[MAX];
    char letras[MAX];

    setLetras(letras);

    fgets(frase, MAX, stdin);
    
    for (int i = 0; i < strlen(frase); i++) {
        for (int j = 0; j < strlen(letras); j++) {
            if (frase[i] == letras[j]) {
                letras[j] = '@';
            }
        }
    }

    for (int i = 0; i < strlen(letras); i++) {
        if (letras[i] != '@') {
            printf("%c ", letras[i]);
        }
    }
    printf("\n");

    return 0;
}

/* Cria um array de letras minusculas */
void setLetras(char letras[])
{
    for (int i = 0; i < 26; i++) {
        letras[i] = i+97;

        if (i == 25) {
            letras[i+1] = '\0';
        }
    }
}