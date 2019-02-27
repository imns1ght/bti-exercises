#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ANO_UFRN	1958
#define MES_UFRN	6
#define DIA_UFRN	  25

struct Data {
	int dia, mes, ano;
};
typedef struct Data Data;

struct Tarefa {
	Data dataInicial, dataFinal;
};
typedef struct Tarefa Tarefa;

//retorna se as duas datas sao iguais ou nao
int datasIguais(Data d1, Data d2);

//escreve a data no formato AAAA/MM/DD
void printData(Data d);

//retorna a quantidade de dias do mes passado como parametro
//assuma ano nao bissexto (ou seja, fevereiro vai ate 28)
int numeroDiasNoMes(int mes);

//retorna a quantidade de dias entre duas datas
//use numeroDiasNoMes para facilitar os cálculos
int diferencaDatas(Data d1, Data d2);

//retorna verdadeiro/falso se d existe ou nao como data
//exemplo, para a data 30/02/2018 deve retornar falso
int dataValida(Data d);

#endif