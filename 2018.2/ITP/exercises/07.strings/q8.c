#include <stdio.h>
#include <string.h>

void reverse(char from[], char to[]);

int main()
{
    char fraseSpaces[100];
    char frase[100];
    char fraseRev[100];

    fgets(fraseSpaces, 100, stdin);

    for (int i = 0, j = 0; i <= strlen(fraseSpaces); i++, j++) {
        if (fraseSpaces[i] != ' ') {
            frase[j] = fraseSpaces[i];
        } else {
            j--;
        }
    }

    reverse(frase, fraseRev);
    
if (strcmp(frase, fraseRev) == 0) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}

void reverse(char from[], char to[])
{
	int i, j = 0;
		
	for (i = strlen(from)-1; i >= 0; --i) {
		if (from[i] != '\0' && from[i] != '\n') {
			to[j] = from[i];
			++j;
		}
	}
	
    to[j] = '\n';
    j++;
	to[j] = '\0';
}