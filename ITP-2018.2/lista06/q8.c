#include <stdio.h>

int main()
{
	int n; /* Quantidade de meses */
	int nums[20]; /* Quantidade de dias chuvosos */
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	for (int i = 0; i < n; i++) {
		int cont = 0;

		for (int j = 0; j < n; j++) {
			if (nums[i] > nums[j]) {
				cont++;
			}
		}

		printf("%d ", cont);
	}
	
	return 0;
}
