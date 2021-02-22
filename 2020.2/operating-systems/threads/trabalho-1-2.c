#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PI acos(-1)

// Limites
double a = 0;
double b;
double h;

// (Número de trapézios / número de threads)
int trapezoidsPerThread;
// Número de trapézios da última thread
int trapezoidsLastThread;

double (*f)(double);  // Ponteiro para a função desejada pelo usuário

double function1(double x) { return 5; }
double function2(double x) { return sin(2 * x) + cos(5 * x); }

void* calc(void* i) {
    double total;
    double* result;
    int local_a = *(int*)i * trapezoidsPerThread;
    int local_b = local_a + trapezoidsPerThread;

    for (double i = local_a; i < local_b; i++) {
        double x_i = (a + i) * h;
        total += (*f)(x_i);
    }

    result = &total;

    return result;
}

int main(int argc, char* argv[]) {
    int t = atoi(argv[2]);  // Número de threads
    int n = atoi(argv[3]);  // Número de trapézios
    pthread_t threads[t];
    double* threadsValues[t];  // Valores retornado pelas threads
    // (Número de trapézios / número de threads)
    trapezoidsPerThread = n / t;
    // Número de trapézios da última thread
    trapezoidsLastThread = n - trapezoidsPerThread * t;

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

    // for (double i = 1; i < n; i++) {
    //     double x_i = (a + i) * h;
    //     totalArea += (*f)(x_i);
    // }

    for (int i = 0; i < t; i++) {
        int* thread_a = &i;
        if (pthread_create(&threads[i], NULL, calc, thread_a) != 0) {
            printf("Erro ao criar a thread[%d]", i);
        } else {
            printf("Thread[%d] criada com sucesso!\n", i);
        }
    }

    // Espera as threads finalizarem suas rotinas e adiciona os resultados
    for (int i = 0; i < t; i++) {
        pthread_join(threads[i], (void*)&threadsValues[i]);
        totalArea += *threadsValues[i];
    }
    totalArea = h * totalArea;

    printf("\nÁrea total: %e\n", totalArea);

    return 0;
}