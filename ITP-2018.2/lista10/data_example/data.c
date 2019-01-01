#include "data.h"

int datasIguais(Data d1, Data d2) {
	return d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano;
}

void printData(Data d) {
	printf("%d/%02d/%02d\n", d.ano, d.mes, d.dia);
}

int numeroDiasNoMes(int mes) {
	if (mes == 2) {
		return 28;
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		return 30;
	} else {
		return 31;
	}
}

int diferencaDatas(Data d1, Data d2) {
	int anos, meses = 0, dias;
	dias = (d2.ano - d1.ano) * 365;
	
	for (int i = d1.mes; i < d2.mes; i++) {
		dias -= numeroDiasNoMes(i);
	}
	dias  -=  (d2.dia - d1.dia);

	return abs(dias-1);
}

int dataValida(Data d) {
	if (d.dia > numeroDiasNoMes(d.mes) || d.mes > 12) {
		return 0;
	} else {
		return 1;
	}
}
