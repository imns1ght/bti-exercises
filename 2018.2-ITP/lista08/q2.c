#include <stdio.h>
#include <string.h>

int main () {
    char frase [200];
    fgets(frase, 200, stdin);    
    char *p = frase;
    
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == ' ') {
            p = &frase[i];        
            printf ("%s\n", p);
            break;
        }
    }

    return 0;
}
