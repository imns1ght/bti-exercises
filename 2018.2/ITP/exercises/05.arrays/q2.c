#include <stdio.h>

void order(int uValues[], int n);

int main()
{
	int n;
	int nValues[10];
	int uValues[10];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		nValues[i] = i+1;	
	}

	for (int j = 0; j < n; j++) {
		scanf("%d", &uValues[j]);
	}

	order(uValues, n);
		
	for (int x = 0; x < n; x++) {
		if (nValues[x] != uValues[x]) {
			printf("não\n");
			return 0;
		}
	}

	printf("sim\n");

	return 0;
}

void order(int uValues[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (uValues[j] > uValues[i]) {
				int temp = uValues[i];
				uValues[i] = uValues[j];
				uValues[j] = temp;
			}
		}
	}	
}

