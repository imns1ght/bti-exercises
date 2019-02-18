#include <stdio.h>
#include <string.h>

int main()
{
    char frase[200];
    int palavras = 0;
    int tmp = 0;

    fgets(frase, 200, stdin);

    for (int i = 0; i < strlen(frase); i++) {   
        if (frase[i] != ' ') {
            tmp = 1;   
        } 
        
        if (frase[i] == ' ' || frase[i] == '\n') {
            palavras += tmp;
        }

    }
    printf("%d\n", palavras);

    return 0;
}