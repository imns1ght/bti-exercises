#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Erro ao criar processo\n");
        return 1;
    } else if (pid == 0) {
        printf("Esta é a execução do filho (PID=%d), cujo pai tem PID=%d\n",
               getpid(), getppid());
        for (;;);
    } else {
        wait(NULL);
        printf("Processo-filho finalizou\n");
    }

    return 0;
}