#include <stdio.h>
#include <string.h>

int verify(int pos, char palavra[]);
int bombs(int pos, char palavra[]);

int main()
{
    int pos;
    char palavra[20];

    scanf("%s", palavra);
    scanf("%d", &pos);

    if (verify(pos, palavra) == -1) {
        printf("bum!\n");
    } else {
        printf("%d\n", verify(pos, palavra));
    }

    return 0;
}

int verify(int pos, char palavra[])
{
    if (palavra[pos] == '*') {
        return -1;
    } else {
        return bombs(pos, palavra);
    }
}

int bombs(int pos, char palavra[]) 
{
    int n = 0;

    if (palavra[pos + 1] == '*') {
        n++;
    }
    
    if (palavra[pos - 1] == '*') {
        n++;
    }

    return n;
}
