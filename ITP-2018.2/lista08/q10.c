#include <stdio.h>
#include <stdlib.h>

int obterInteiro(char s[]);

int main()
{
    char s[30];
    fgets(s, 30, stdin);
    printf("%d\n", obterInteiro(s));
	
	return 0;
}

int obterInteiro(char s[])
{  
    int n = 0;
    sscanf(s, "%d", &n);

    return n;
}