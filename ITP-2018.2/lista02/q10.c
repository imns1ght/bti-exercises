#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c = 0;

	scanf("%d %d %d", &a, &b, &c);

	if ((a < b + c && a > abs(b - c)) || (b < a + c && b > abs(a - c)) || (c < a + b && c > abs(a - b))) {
		if (a == b && a == c && b == c) {
			printf("Existe\nClassificação: equilátero\n");
		} else if (a == b || a == c || b == c) {
			printf("Existe\nClassificação: isósceles\n");
		} else if (a != b && a != c && b != c) {
			printf("Existe\nClassificação: escaleno\n");
		}
	} else {
		printf("Não existe\n");
	}
	

	return 0;

}
