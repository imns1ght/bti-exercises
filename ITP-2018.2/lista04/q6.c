#include <stdio.h>

int qtdDobras(float sheetLength, float sheetWidth, float pocketLength);

int main()
{
	float sheetLength, sheetWidth, pocketLength;
    scanf("%f %f %f", &sheetLength, &sheetWidth, &pocketLength);

    printf("%d\n", qtdDobras(sheetLength, sheetWidth, pocketLength));
	
	return 0;
}

int qtdDobras(float sheetLength, float sheetWidth, float pocketLength) {
	int execs = 0;
	
    while ((sheetLength >= pocketLength) && (sheetWidth >= pocketLength)) {
    	if (sheetLength > sheetWidth) {
        	sheetLength = sheetLength/2;
        } else {
        	sheetWidth = sheetWidth/2;
        }
        execs++;
	}

	return execs;
}
