#include <stdio.h> 

int main() 
{
	int a;
	int m, n;
	int pagdigit[1000];
	int pag[1000];

	scanf("%d", &m);
	scanf("%d", &n); 

	for (int i = 0; i < m; i++) {
		pagdigit[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		pagdigit[a]++;
	}

	for (int i = 1, b = 0; i <= m; i++) {
		if (pagdigit[i] != 1) {
			pag[b] = i;
			printf("%d ", pag[b]);
			b++; 
		}
	}

	printf("\n");
	
	return 0;
}
