#include <stdio.h>

int main()
{
	int a, b, n;
	int dist = 0, max = 0;
	int hTerreno[30];
	scanf("%d", &n);
	
	/* Set hTerreno */
	for (int i = 0; i < n; i++) {
		scanf("%d", &hTerreno[i]);
	}
	
	/* Set max */
	for (int i = 0; i < n; i++) {
		if (hTerreno[i] > max) {
			max = hTerreno[i];
			a = i+1;
		}
	}	
	
	/* Calcula a distância */
	for(int i = a+1; i < n; i++) {
		if (hTerreno[i] == max) {
			b = i;
			dist = b - a;
		}
	}

	printf("%d", dist);

	return 0;
}
