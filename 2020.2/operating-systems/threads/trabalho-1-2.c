#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PI acos(-1)

double function1(double x) { return 5; }
double function2(double x) { return sin(2 * x) + cos(5 * x); }

int main(int argc, char* argv[]) {
    int t = atoi(argv[2]);  // Número de threads
    int n = atoi(argv[3]);  // Número de trapézios
    double (*f)(double);    // Ponteiro para a função desejada pelo usuário
    char outputText[30];    // Texto a ser exibido ao final da execução
    pthread_t threads[t];
    double threadsReturns[t];  // Valores retornado pelas threads

    // Limites
    double a = 0;
    double b;

    // Verifica qual função o usuário deseja
    if (!strcmp(argv[1], "f1")) {
        b = 10;
        f = &function1;
        strcpy(outputText, "Área total: %.2f\n");
    } else if (!strcmp(argv[1], "f2")) {
        b = 2 * PI;
        f = &function2;
        strcpy(outputText, "Área total: %e\n");
    } else {
        // Verificação de erros básica
        printf("Por favor, passe como parâmetro \"f1\" ou \"f2\"\n");
        printf("Exemplo: ./trapezio f1 6 200\n\n");
        return 1;
    }

    double h = (b - a) / n;
    double totalArea = (f(a) + f(b)) / 2;

    for (double i = 1; i < n; i++) {
        double x_i = (a + i) * h;
        totalArea += (*f)(x_i);
    }

    totalArea = h * totalArea;

    printf(outputText, totalArea);

    return 0;
}