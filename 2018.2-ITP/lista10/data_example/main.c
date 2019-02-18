#include "data.h"

//funcao main
int main() {

	//exercicio 1: criar uma tarefa lista1 que vai de 18/2/2018 ate 1/4/2018
	//corrija o dia inicial para 19
	//corrija o mes final para 3
	//escreva na tela as duas datas da tarefa
	Tarefa lista1 = {{18, 2, 2018},{1, 4, 2018}};
	lista1.dataInicial.dia = 19;
	lista1.dataFinal.mes = 3;

	printf("Lista 1:\n");
	printData(lista1.dataInicial);
	printData(lista1.dataFinal);

	//exercicio 2: criar uma tarefa lista2 cujas datas iniciais e finais sao
	//digitadas pelo usuario
	//se pelo menos uma das datas for invalida, solicite ao usuario uma nova data
	//escreva na tela as duas datas da tarefa
	//escreva na tela a diferença de dias usando a função diferencaDatas
	Tarefa lista2;
	do {
		printf("\nDigite a data inicial e a data final da lista 2: \n");
		scanf("%d %d %d", &lista2.dataInicial.ano, &lista2.dataInicial.mes, &lista2.dataInicial.dia);
		scanf("%d %d %d", &lista2.dataFinal.ano, &lista2.dataFinal.mes, &lista2.dataFinal.dia);

		if (!(dataValida(lista2.dataInicial) || dataValida(lista2.dataFinal))) {
			printf("\nData inválida. Digite novamente.\n");
		}
	} while (!(dataValida(lista2.dataInicial) || dataValida(lista2.dataFinal)));
	
	printf("\nLista2: \n");
	printData(lista2.dataInicial);
	printData(lista2.dataFinal);
	printf("\nDiferença de dias: %d\n", diferencaDatas(lista2.dataInicial, lista2.dataFinal));

	return 0;
}





