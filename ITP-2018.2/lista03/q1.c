#include <stdio.h>

int main()
{
	int x, n = 0;
	scanf("%d %d", &x, &n);	
	
	for (int i = 1; i <= n; i++) {	
		if (i < n) {
			printf("%d, ", x);
		} else {
			printf("%d", x);
		}
	}

	return 0;
}
