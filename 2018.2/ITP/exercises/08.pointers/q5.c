#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, acertos = 0;
    int *gab, *resp;
    
    scanf("%d", &n);
    gab = malloc(sizeof(int)*n);
    resp = malloc(sizeof(int)*n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &gab[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &resp[i]);
    }

    for (int i = 0; i < n; i++) {
        if (resp[i] == gab[i]) {
            acertos++;
        }
    }

    if (acertos > 1) {
        printf("%d acertos", acertos);
    } else {
        printf("%d acerto", acertos);
    }

    return 0;
}