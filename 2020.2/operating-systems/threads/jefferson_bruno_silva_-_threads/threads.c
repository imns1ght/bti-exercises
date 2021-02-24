#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PI acos(-1)

double function1(double x) { return 5; }
double function2(double x) { return sin(2 * x) + cos(5 * x); }

double a = 0;  // Limite a
double b;      // Limite b, definido de acordo com a função desejada
double h;      // Necessário o número de trapézios e os limites 'a' e 'b'
long t;        // Número de threads
long n;        // Número de trapézios
double threadsValues[10];  // Resultados das threads
double (*f)(double);       // Ponteiro para a função desejada pelo usuário

void* calc(void* id) {
    long idThread = (long)id;
    threadsValues[idThread] = 0;

    // Previne problemas com divisões não-inteiras
    long trapsPerThread = n / (t - 1);
    long trapsLastThread = n % (t - 1);

    long local_a = idThread * trapsPerThread;
    long local_b =
        local_a + (idThread == (t - 1) ? trapsLastThread : trapsPerThread);

    for (long i = local_a; i < local_b; i++) {
        if (i != 0) {
            double x_i = (a + i) * h;
            threadsValues[idThread] += (*f)(x_i);
        }
    }
}

long main(long argc, char* argv[]) {
    t = atoi(argv[2]);  // Número de threads
    n = atoi(argv[3]);  // Número de trapézios
    pthread_t threads[t];

    // Verifica qual função o usuário deseja
    if (!strcmp(argv[1], "f1")) {
        b = 10;
        f = &function1;
    } else if (!strcmp(argv[1], "f2")) {
        b = 2 * PI;
        f = &function2;
    } else {
        // Verificação de erros básica
        printf("Por favor, passe como parâmetro \"f1\" ou \"f2\"\n");
        printf("Exemplo: ./trapezio f1 6 200\n\n");
        return 1;
    }

    h = (b - a) / n;
    double totalArea = (f(a) + f(b)) / 2;

    for (long i = 0; i < t; i++) {
        pthread_create(&threads[i], NULL, calc, (void*)(i));
    }

    // Espera as threads finalizarem suas rotinas
    for (long i = 0; i < t; i++) {
        pthread_join(threads[i], NULL);
        totalArea += threadsValues[i];
    }
    totalArea = h * totalArea;
    printf("Área total: %.2e\n", totalArea);

    return 0;
}