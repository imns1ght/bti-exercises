#include <stdio.h>

int main()
{
	int a, b, restoDiv, result;
	scanf("%d %d", &a, &b);
		
	do {
		restoDiv = a % b;
		a = b;
		b = restoDiv;

		if (restoDiv != 0) {
			result = restoDiv;
		}

	} while (restoDiv != 0);
	
	printf("%d\n", result);

	return 0;
}
