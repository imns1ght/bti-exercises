#include <stdio.h>

int main()
{
	float n1, n2, n3, m = 0;

	printf("Digite a primeira nota: ");
	scanf("%f", &n1);

	printf("Digite a segunda nota: ");
	scanf("%f", &n2);

	printf("Digite a terceira nota: ");
	scanf("%f", &n3);

	m = (n1 + n2 + n3) / 3;

	if (m >= 9.5) {
		printf("Conceito: A");
	} else if (m >= 8.5 && m < 9.5) {
		printf("Conceito: B");
	} else if (m >= 7 && m < 8.5) {
		printf("Conceito: C");
	} else if (m >= 6 && m < 7) {
		printf("Conceito: D");
	} else {
		printf("Conceito: F");
	}

	return 0;
}
