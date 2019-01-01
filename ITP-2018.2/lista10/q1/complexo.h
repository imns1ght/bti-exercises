#ifndef NUMERO_COMPLEXO
#define NUMERO_COMPLEXO

#include <stdio.h>

typedef struct {
	float real, imaginaria;
} NumeroComplexo;

// retorna um novo numero complexo que eh a soma x + y
NumeroComplexo soma ( NumeroComplexo x , NumeroComplexo y ) ;
// retorna um novo numero complexo que eh a diferenca x - y
NumeroComplexo diferenca ( NumeroComplexo x , NumeroComplexo y ) ;
// retorna um novo numero complexo que eh o produto xy
NumeroComplexo produto ( NumeroComplexo x , NumeroComplexo y ) ;
// retorna um novo numero complexo que eh o conjugado de x
NumeroComplexo conjugado ( NumeroComplexo x ) ;
// escreve o numero complexo x no seguinte formato : a + bi , onde a parte real e b parte imaginaria
// se a parte imaginaria for negativa , omita o sinal de +
// exemplo : para a = 3 e b = -2 , a funcao deve escrever 3 -2 i e nao 3+ -2 i
void printNumeroComplexo ( NumeroComplexo x ) ;
// retorna 1 ou 0 dependendo se x e y possuem mesmos valores ou nao
int saoIguais ( NumeroComplexo x , NumeroComplexo y ) ;
// zera a parte imaginaria do numero complexo referenciado por ptr
void zerarImaginaria ( NumeroComplexo * ptr ) ;

#endif