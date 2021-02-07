#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_SIZE 4

int main(int argc, char* argv[]) {
    int vetor_pipe_ida[2], vetor_pipe_volta[2];
    pid_t pid;
    char buffer[MAX_SIZE];
    int num, resposta;

    pipe(vetor_pipe_ida);
    pipe(vetor_pipe_volta);
    pid = fork();

    if (!pid) {
        close(vetor_pipe_ida[1]);  // fecha o caminho deste pipe, pois não será
                                   // utilizado.
        while (read(vetor_pipe_ida[0], buffer, MAX_SIZE) > 0)
            ;
        sscanf(buffer, "%d", &num);
        close(vetor_pipe_ida[0]);
        printf("FILHO: o filho leu: %d\n", num);
        num += 1;
        sprintf(buffer, "%d", num);

        close(vetor_pipe_volta[0]);
        write(vetor_pipe_volta[1], buffer, MAX_SIZE);
        close(vetor_pipe_volta[1]);
        printf("FILHO: o filho escreveu: %d\n", num);
        printf("FILHO: o filho terminou\n");
        exit(EXIT_SUCCESS);
    } else {
        num = atoi(argv[1]);
        sprintf(buffer, "%d", num);
        close(vetor_pipe_ida[0]);
        write(vetor_pipe_ida[1], buffer, MAX_SIZE);
        close(vetor_pipe_ida[1]);
        printf("PAI: o pai escreveu: %s\n", buffer);

        close(vetor_pipe_volta[1]);

        while (read(vetor_pipe_volta[0], buffer, MAX_SIZE) > 0) {
            close(vetor_pipe_volta[0]);
        }

        sscanf(buffer, "%d", &num);
        printf("PAI: o pai leu: %d\n", num);
        wait(NULL);
        printf("PAI: o filho terminou\n");
        printf("PAI: o pai terminou\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
