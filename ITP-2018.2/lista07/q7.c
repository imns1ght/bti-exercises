#include <stdio.h>
#include <string.h>

int main()
{
    char frase[200];

    fgets(frase, 200, stdin);

    for (int i = 0; i < strlen(frase); i++) {
        switch(frase[i]) {
            case 'a':
                frase[i] = 52;
                break;
            case 'e':
                frase[i] = 51;
                break;
            case 'i':
                frase[i] = 49;
                break;
            case 's':
                frase[i] = 53;
                break;
            case 't':
                frase[i] = 55;                  
                break;
        }
    }

    printf("%s", frase);

    return 0;
}