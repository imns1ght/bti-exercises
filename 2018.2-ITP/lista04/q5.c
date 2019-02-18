#include <stdio.h>

int mdc(int a, int b);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", mdc(a, b));

	return 0;
}

int mdc(int a, int b) {
	int restoDiv, result = 0;
	
	do {
    	restoDiv = a % b;
        a = b;
        b = restoDiv;


    } while (restoDiv != 0);

	return a;
}
