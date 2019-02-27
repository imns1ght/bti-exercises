#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	float *coord, diffX = 0, diffY = 0, dist = 0;

	scanf("%d", &n);
	coord = malloc(sizeof(float)*(n*2));

	for (int i = 0; i < n*2; i++) {
		scanf("%f", &coord[i]);
	}

	for (int i = 0, j = 2, cont = 0; cont < n-1; i+=2, j+=2, cont++) {
		diffX = (coord[j] - coord[i]) * (coord[j] - coord[i]);
		diffY = (coord[j+1] - coord[i+1]) * (coord[j+1] - coord[i+1]);
		dist += sqrt(diffX+diffY);
	}
	
	printf("%.2f", dist);

	return 0;
}