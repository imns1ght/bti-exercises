#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PI acos(-1)

double function1(double x) { return 5; }
double function2(double x) { return sin(2 * x) + cos(5 * x); }

// Limites
double a = 0;
double b;
double h;
long t;
long n;
double threadsValues[10];  // Valores retornado pelas threads
double (*f)(double);       // Ponteiro para a função desejada pelo usuário

void* calc(void* id) {
    long idThread = (long)id;
    threadsValues[idThread] = 0;

    // (Número de trapézios / número de threads)
    long trapsPerThread = n / (t - 1);
    // Número de trapézios da última thread
    long trapsLastThread = n % (t - 1);

    long local_a = idThread * trapsPerThread;
    long local_b =
        local_a + (idThread == (t - 1) ? trapsLastThread : trapsPerThread);
    fprintf(stderr, "local_a = %ld\n", local_a);
    fprintf(stderr, "local_b = %ld\n", local_b);

    for (long i = local_a; i < local_b; i++) {
        if (i != 0) {
            double x_i = (a + i) * h;
            fprintf(stderr, "x_i [%d]= %f\n", i, x_i);
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
        printf("\nÁrea total: %e\n", totalArea);
    }
    totalArea = h * totalArea;

    printf("\nÁrea total: %e\n", totalArea);
    printf("h=%f\n", h);

    return 0;
}