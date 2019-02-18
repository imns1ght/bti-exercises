#include <stdio.h>
#include <string.h>

int main()
{  
    int verify = 0;
    char code[20];

    fgets(code, 20, stdin);
    
    if (strlen(code) > 5) {
        printf("nao\n");
        return 0;
    }

    for (int i = 0; i < strlen(code); i++) {
        if (i < 2) {
            if (code[i] >= 48 && code[i] <= 57) {
                verify = 1;
            } else {
                verify = 0;
                break;
            }
        } else if (i == 2) {
            if (code[i] != '-') {
                verify = 0;
                break;
            } 
            
        } else if (i == 3) {
            code[0] = code[0]-'0';
            code[1] = code[1]-'0';
            code[i] = code[i] - '0';
        
            if (code[i] == (2*code[0] + 3*code[1]) % 7) {
                verify = 1;
                break;
            } else {
                verify = 0;
                break;
            }
        }
    }

    if (verify == 1) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}