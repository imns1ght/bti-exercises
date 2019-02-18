#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hInicial, mInicial, hFinal, mFinal, hDiff, mDiff = 0;

	printf("Digite as horas do horário inicial: ");
	scanf("%d", &hInicial);
	printf("Digite os minutos do horário inicial: ");
	scanf("%d", &mInicial);
	printf("Digite as horas do horário final: ");
	scanf("%d", &hFinal);
	printf("Digite os minutos do horário final: ");
	scanf("%d", &mFinal);
	
	hDiff = abs(hFinal - hInicial);
		
	mDiff = abs(mFinal - mInicial);


	if (mDiff >= 60) {
		mDiff -= 60;
		hDiff++;
	}

	if (hDiff >= 24) {
		hDiff -= 24;
	}

	printf("Resultado: %dh%dmin", hDiff, mDiff);

	return 0;	
}
