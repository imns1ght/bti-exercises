#include <stdio.h>

int main()
{
	int a, b = 0;

	scanf("%d %d", &a, &b);

	if (a % b == 0) {
		printf("Resultado: %d\n", a/b); 
	} 

	return 0;
}
