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
    *a = *a + 2;
    printf("executando filho 2 = %d\n", getpid());
}

int main() {
    int filho1, filho2, pid, status;
    char *mem;  // pointer to shared memory

    int seg_id = shmget(IPC_PRIVATE, 20 * sizeof(char),
                        IPC_CREAT | 0666);  // get shared memory segment

    printf("Pai começou (PID=%d)\n", getpid());

    filho1 = fork();  // clone the process
    if (!filho1) {
        implementacao_filho1(&a);
        mem = shmat(seg_id, NULL, 0);  // Attach shared memory segment.
        sprintf(mem, "escrevendo teste");
        printf("%s no processo PID = %d\n", mem, getpid());
        shmdt(mem);  // Detach shared memory segment.
        exit(0);
    }

    status = wait(NULL);
    if (filho1 > 0) {
        filho2 = fork();
        if (!filho2) {
            implementacao_filho2(&a);
            mem = shmat(seg_id, NULL, 0);  // Attach shared memory segment.
            printf("%s no processo PID = %d\n", mem, getpid());
            shmdt(mem);  // Detach shared memory segment.
            exit(0);
        }
    }

    status = wait(NULL);
    printf("(PID=%d) Processo sendo finalizado\n", getpid());
    printf("Valor final de a = %d\n", a);
    shmctl(seg_id, IPC_RMID, NULL);
    exit(0);
    printf("Pai terminou\n");

    return 0;
}