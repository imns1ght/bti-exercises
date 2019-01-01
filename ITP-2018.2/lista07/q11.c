#include <stdio.h>
#include <string.h>

int main()
{
    int cont, negative = 0;
    int palavraInt[30];
    char palavra[30];
    
    fgets(palavra, 30, stdin);

    for (int i = 0; i < 30; i++) {
        palavraInt[i] = 0;
    }

    if (palavra[0] == 45) {
        negative = 1;
    }

    for (int i = 0; i < strlen(palavra); i++, cont++) {        
        if (palavra[i] >= 48 && palavra[i] <= 57) {
            palavraInt[i] = palavra[i] - '0';
        }
    }
    
    if (negative) {
        printf("%c", 45);
    }
    
    for (int i = 0; i < cont; i++) {        
        if (palavraInt[i] != 0) {
            printf("%d", palavraInt[i]);
        }
    }

    return 0;
}