#include <stdio.h>
#include <string.h>

int main()
{
    int maiusc = 0;
    int hifen = 0;
    int nums = 0;
    char palavra[20];

    fgets(palavra, 20, stdin);

    if (strlen(palavra) > 9) {
        printf("não\n");
        return 0;
    } else {
        for (int i = 0; i < strlen(palavra); i++) {
            if (i < 3) {
                if (palavra[i] >= 65 && palavra[i] <= 90) {
                    maiusc++;            
                }
            } else if (i == 3) {
                if (palavra[i] == 45) {
                    hifen++;
                }
            } else if (i > 3) {
                if (palavra[i] >= 48 && palavra[i] <= 57) {
                    nums++;
                }
            }
        }    
    }

    if ((maiusc == 3) && (hifen == 1) && (nums == 4)) {
        printf("sim\n");
    } else {
        printf("não\n");
    }

    return 0;
}