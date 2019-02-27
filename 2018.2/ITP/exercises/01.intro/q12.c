#include <stdio.h>

int main()
{
	int hr, min, seg = 0;

	scanf("%d %d %d", &hr, &min, &seg);
	printf("%d", ((hr * 3600) + (min * 60) + (seg)));

	return 0;	
}
