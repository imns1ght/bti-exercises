#include <stdio.h>

int main() 
{
	int a, b, c, d, maior = 0;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a > b) {
		maior = a;
	} else {
		maior = b;
	} 
	
	if (maior < c) {
		maior = c;
	} else if (maior < d) {
		maior = d;
	} 
	printf("Maior: %d", maior);
}
