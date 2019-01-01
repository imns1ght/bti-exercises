#include <stdio.h>

int somaDivisoresProprios(int x);
int amigos(int a, int b);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d e %d são amigos? %d\n", a, b, amigos(a, b));

	return 0;
}

int somaDivisoresProprios(int x) {
	int sum = 0;
	
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}

	return sum;	
}

int amigos(int a, int b) {
	if ((somaDivisoresProprios(a) == b) || somaDivisoresProprios(b) == a) {
		return 1;
	} else {
		return 0;
	}
}
