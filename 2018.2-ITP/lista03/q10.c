#include <stdio.h>
#include <math.h>

int main()
{
	int n, b, result = 0;
	scanf("%d %d", &n, &b);
		
	for (int i = 1; result < n; i++) {
		result = pow(b, i);

		if (result == n) {
			printf("sim\n");
			break;
		} 
	}

	if (result != n) {
		printf("não\n");
	}

	return 0;
}
