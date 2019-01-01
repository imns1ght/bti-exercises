#include <stdio.h>

int main () 
{
    int i;
    int v[] = {3 , 14 , 9, 6, 5 , 11 , 12 , 2, 8, 13 , 7, 10 , 1 , 4};
    int *p = v; 

    for(i = 4; i < 9; i++) {
        printf ("%d ", p[i]);
    }
    return 0;
}