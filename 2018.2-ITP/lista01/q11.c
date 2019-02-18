#include <stdio.h>

int main()
{
	int n = 0;

	scanf("%d", &n);
	printf("Resposta: %d\n", (n % 3 == 0) && (n % 5 != 0) && (n != 0));

/* Alternative	
	if ((n % 3 == 0) && (n % 5 != 0) && (n != 0)) {
		printf("Resposta: 1\n");
	} else {
		printf("Resposta: 0\n");	
	}
*/
	return 0;
}