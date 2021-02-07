#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int vetor_pipe[2], TAM;  // 0 para ler e 1 para escrever (convenção)
    pid_t pid;

    TAM = strlen(argv[1]) + 1;
    char buffer[TAM];

    pipe(vetor_pipe);
    pid = fork();

    if (!pid) {
        close(vetor_pipe[1]);  // fecha o caminho de escrita
        while (read(vetor_pipe[0], &buffer, TAM) > 0) {
            close(vetor_pipe[0]);  // fecha o caminho de leitura
        }
        printf("FILHO: o filho terminou e leu: %s\n", buffer);
        exit(EXIT_SUCCESS);
    } else {
        // fecha o caminho de leitura pois não será utilizado
        close(vetor_pipe[0]);
        sleep(2);
        write(vetor_pipe[1], argv[1], strlen(argv[1]) + 1);
        // fecha o caminho de escrita caracterizando o fim (EOF)
        close(vetor_pipe[1]);
        printf("PAI: o pai terminou e escreveu: %s\n", argv[1]);
        wait(NULL);
        printf("PAI: o filho terminou\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
