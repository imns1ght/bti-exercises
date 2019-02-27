/* Imprime os números pares e não divisiveis por 3 de 1 a 100 */
#include <stdio.h>

int main () 
{
	int i;

	for (i = 1; i <= 100; i ++) {
		if(i % 2 == 0 && i % 3 != 0) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
