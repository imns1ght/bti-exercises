#include <stdio.h>

int main()
{
	int n;       
	int mult;    
	int fator = 2;   

  	scanf("%d", &n);

  	while (n > 1) {
    	mult = 0;
      	
		while (n % fator == 0) {
        	mult++;
        	n = n / fator; 
        }

      	if (mult != 0) {
        	printf("%d^%d ", fator, mult); 
        }

      	fator++; 
    }

	return 0;
}
