#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int a = 0;

void implementacao_filho1(int *a) {
    *a = *a + 1;
    printf("executando filho 1 = %d\n", getpid());
}

void implementacao_filho2(int *a) {
    *a = *a * 2;
    printf("executando filho 2 = %d\n", getpid());
}

int main() {
    int filho1, filho2, pid, status, i;
    int *mem;  // pointer to shared memory

    int valor = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    mem = shmat(valor, NULL, 0);

    if (mem < 0) {
        printf("Erro na alocação!\n");
        return 0;
    }

    *mem = 5;
    printf("Pai começou (PID=%d) e o valor do inteiro é: %d\n", getpid(), *mem);
    filho1 = fork();  // clone the process

    if (filho1 > 0) {
        filho2 = fork();
    }

    if (!filho1) {
        mem = shmat(valor, NULL, 0);
        sleep(1);
        implementacao_filho1(mem);
        printf("Filho 1 finalizou (PID=%d) e o valor do inteiro é: %d\n",
               getpid(), *mem);
        shmdt(mem);
        exit(0);
    } else if (!filho2) {
        mem = shmat(valor, NULL, 0);
        implementacao_filho2(mem);
        printf("Filho 2 finalizou (PID=%d) e o valor do inteiro é: %d\n",
               getpid(), *mem);
        shmdt(mem);
        exit(0);
    }

    for (i = 0; i < 2; i++) {
        wait(NULL);
    }

    shmctl(valor, IPC_RMID, NULL);
    printf("valor = %d\n", *mem);
    printf("Pai terminou\n");
    exit(0);

    return 0;
}