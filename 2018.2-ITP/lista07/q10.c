#include <stdio.h>
#include <string.h>

int verifica(char palavra[]);

int main() 
{
    int dia, barra, mes = 0;
    char palavra[20];

    fgets(palavra, 20, stdin);

    if (strlen(palavra) != 6) {
        printf("nao\n");
        return 0;
    } 
    
    for (int i = 0; i < strlen(palavra); i++) {
        /* Verifica os dias */
        if (i < 2) {    
            if (i == 0) {
                if (palavra[i] >= 48 && palavra[i] <= 51) {
                    dia++;
                }
            } else if (i == 1) {
                if (palavra[i] >= 48 && palavra[i] <= 57) {
                    dia++;
                }
            }
        } else if (i == 2) { /* Verifica a barra */
            if (palavra[i] == 47) {
                barra++;
            }
        } else if (i > 2) { /* Verifica o mês */
            if (i == 3) {
                if (palavra[i] >= 48 && palavra[i] <= 49) {
                    mes++;
                }
            } else if (i == 4) {
                if (palavra[i-1] == 48 && palavra[i] == 48) {
                    printf("nao\n");
                    return 0;
                } else {
                    if (palavra[i] >= 48 && palavra[i] <= 57) {
                        mes++;
                    }
                }
            }

            /* Realiza a checagem final */
            if (verifica(palavra) == 0) {
                printf("nao\n");
                return 0;
            }
        }
    }

    if ((dia == 2) && (barra == 1) && (mes == 2)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}

int verifica(char palavra[])
{
    if (palavra[3] == 48 && palavra[4] == 52) {
        if (palavra[0] == 51 && palavra[1] > 48) {
            return 0;
        }

    } else if (palavra[3] == 48 && palavra[4] == 54) {
        if (palavra[0] == 51 && palavra[1] > 48) {
            return 0;
        }

    } else if (palavra[3] == 48 && palavra[4] == 57) {
        if (palavra[0] == 51 && palavra[1] > 48) {
            return 0;
        }

    } else if (palavra[3] == 49 && palavra[4] == 49) {
        if (palavra[0] == 51 && palavra[1] > 48) {
            return 0;
        }

    } else if (palavra[3] == 48 && palavra[4] == 50) {
        if (palavra[0] == 50 && palavra[1] > 56) {
            return 0;
        }

    } else if (palavra[3] == 49 && palavra[4] > 50) {
        return 0;

    } else if ((palavra[0] == 48 && palavra[1] == 48) || (palavra[0] == 51 && palavra[1] > 49)) {
        return 0;

    }
}