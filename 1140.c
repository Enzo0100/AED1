#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[1100];
    while (fgets(frase, sizeof(frase), stdin) != NULL) {
        
        if (frase[0] == '*') {
            break;
        }

        int e_tautograma = 1; 
        char letra_inicial = tolower(frase[0]); 
        for (int i = 1; frase[i] != '\0'; i++) {
            if (frase[i - 1] == ' ') {
                if (tolower(frase[i]) != letra_inicial) {
                    e_tautograma = 0;
                    break; 
                }
            }
        }

        if (e_tautograma) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}