#include <stdio.h>
#include <math.h>

int main()
{
	float v, a, t, x, y, w = 0;
	float g = 9.8*9.8;

	printf("Digite a velocidade inicial (m/s): ");
	scanf("%f", &v);
	printf("Digite o angulo inicial (radianos): ");
	scanf("%f", &a);
	printf("Digite o instante de tempo (segundos): ");
	scanf("%f", &t);
	
	x = v*cos(a)*t;
	y = (g*t)*(g*t) / 2;
	y = y - v*sin(a)*t;

	printf("O objeto esta em: %f %f\n", x, y);
	return 0;
}
