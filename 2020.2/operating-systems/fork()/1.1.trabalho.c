#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

struct FamilyMember {
    pid_t id;
    char name[6];
    time_t born;
    time_t death;
};

void printDadDeathMessage(struct FamilyMember *dad) {
    time(&dad->death);
    printf("\n-> Falecimento do %s de PID=%d\n", dad->name, dad->id);
    printf("   Data de nascimento: %s", ctime(&dad->born));
    printf("   Data do falecimento: %s", ctime(&dad->death));
    printf("   Tempo de vida: %.0f anos\n", difftime(dad->death, dad->born));
}

void printChildrenDeathMessage(struct FamilyMember *child) {
    time(&child->death);
    printf("\n-> Falecimento do %s de PID=%d\n", child->name, getpid());
    printf("   Data de nascimento: %s", ctime(&child->born));
    printf("   Data do falecimento: %s", ctime(&child->death));
    printf("   Tempo de vida: %.0f anos\n",
           difftime(child->death, child->born));
}

int main() {
    struct FamilyMember children[4] = {{-1, "FILHO1", -1, -1},
                                       {-1, "FILHO2", -1, -1},
                                       {-1, "NETO1", -1, -1},
                                       {-1, "NETO2", -1, -1}};
    struct FamilyMember dad = {getpid(), "PAI", -1, -1};

    time(&dad.born);  // Nascimento do pai
    printf("-> Iniciando... Pai de PID=%d - %s\n", dad.id, ctime(&dad.born));
    sleep(14);  // Pai Criando filho aos 14 anos
    time(&children[0].born);
    printf("-> Nascimento do %s do %s de PID=%d - %s", children[0].name,
           dad.name, dad.id, ctime(&children[0].born));
    children[0].id = fork();  // Filho1

    if (!children[0].id) {
        sleep(12);  // Avô aos 26 anos
        time(&children[2].born);
        printf("-> Nascimento do %s filho do %s de PID=%d - %s",
               children[2].name, children[0].name, getpid(),
               ctime(&children[2].born));
        children[2].id = fork();  // Neto1

        if (!children[2].id) {
            sleep(12);  // Neto1 morrendo aos 12 anos.
            printChildrenDeathMessage(&children[2]);
        } else {
            sleep(18);  // Filho1 morrendo aos 30 anos.
            printChildrenDeathMessage(&children[0]);
        }
    } else {
        sleep(2);  // Pai criando filho aos 16 anos
        time(&children[1].born);
        printf("-> Nascimento do %s do %s de PID=%d - %s", children[1].name,
               dad.name, dad.id, ctime(&children[1].born));
        children[1].id = fork();  // Filho2

        if (!children[1].id) {
            sleep(16);  // Avô aos 30 anos
            time(&children[3].born);
            printf("-> Nascimento do %s filho do %s de PID=%d - %s",
                   children[3].name, children[1].name, getpid(),
                   ctime(&children[3].born));
            children[3].id = fork();  // Neto2

            if (!children[3].id) {
                sleep(18);  // Neto2 morrendo aos 18 anos.
                printChildrenDeathMessage(&children[3]);
            } else {
                sleep(14);  // Filho2 morrendo aos 30 anos.
                printChildrenDeathMessage(&children[1]);
            }

        } else {
            sleep(44);  // Pai morrendo aos 60 anos.
            printDadDeathMessage(&dad);
        }
    }

    return 0;
}