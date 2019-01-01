#include <stdio.h>

#define MAX 20

int verifica(int n, int gabarito[], int aluno[]);
void setGabarito(int n, int gabarito[]);
void setAluno(int n, int aluno[]);

int main()
{
	int n;
	int result;
	int aluno[MAX];
	int gabarito[MAX];

	scanf("%d", &n);
	
	result = verifica(n, gabarito, aluno);
	if (result > 1) {
		printf("%d acertos\n", result);
	} else {
		printf("%d acerto\n", result);
	}

	return 0;
}

int verifica(int n, int gabarito[], int aluno[]) {
	int acertos = 0;
	setGabarito(n, gabarito);
	setAluno(n, aluno);

	for (int i = 0; i < n; i++) {
		if (aluno[i] == gabarito[i]) {
			acertos++;
		}
	}

	return acertos; 
}

void setGabarito(int n, int gabarito[]) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &gabarito[i]);
	}
}

void setAluno(int n, int aluno[]) {	
	for (int i = 0; i < n; i++) {
		scanf("%d", &aluno[i]);
	}
}

