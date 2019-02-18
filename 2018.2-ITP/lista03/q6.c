/* Calcula o exponencial de a^b */
#include <stdio.h>

int main () {

	int a , b , i , res = 1;
	scanf ("%d %d", &a , &b);

	for(i = 1; i <= b; i++) {
		res *= a;
		printf ("%d\n", res);
	}

	return 0;
}
