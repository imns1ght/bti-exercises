#include <stdio.h>

int main()
{
	int n, first = 0, second = 1, next = 1;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		if (i == n) {
			printf("%d ", first);
		}

		next = first + second;
		first = second;
		second = next;
	}

	return 0;
}
