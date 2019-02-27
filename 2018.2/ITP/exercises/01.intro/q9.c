#include <stdio.h>

int main()
{
	float p, t = 0;
	
	scanf("%f %f", &p, &t);
	printf("Nota: %0.2f", p + ((t * p) / 9));
	return 0;
}
