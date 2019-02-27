#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c = 0;
	float resultado = 0;

	scanf("%d %d %d", &a, &b, &c);
	
	resultado = c - (c*((a+b) * (a+b)))/sqrt(b);
	resultado = c - ((3*a + 2*b)/resultado);

	printf("%f", resultado);

	return 0;	
}
