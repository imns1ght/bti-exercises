#include <stdio.h>

int main()
{
	int a, b, sumA = 0, sumB = 0;
	scanf("%d %d", &a, &b);

	for (int i = 1; i < a; i++) {
		if (a % i == 0) {
			sumA += i;
		}
	}
	
	for (int i = 1; i < b; i++) {
		if (b % i == 0) {
			sumB += i;
		}
	}

	if (sumA == b || sumB == a) {
		printf("sim\n");
	} else {
		printf("não\n");
	}

	return 0;
}
