#include <stdio.h>

int main()
{	
	int execs = 0;
	float sheetLength, sheetWidth, pocketLength;
	scanf("%f %f %f", &sheetLength, &sheetWidth, &pocketLength);

	
	 while ((sheetLength >= pocketLength) && (sheetWidth >= pocketLength)) {
		
		if (sheetLength > sheetWidth) {
			sheetLength = sheetLength/2;
		} else {
			sheetWidth = sheetWidth/2;
		}

		execs++;
	 }
	
	printf("%d", execs);

	return 0;
}
