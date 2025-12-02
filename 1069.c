#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char expressao[1001];
    int i;

    scanf("%d", &N);

    while (N--) {

        scanf("%s", expressao);

        int top = -1;
        int diamantes = 0;

        for (i = 0; expressao[i] != '\0'; i++) {

            if (expressao[i] == '<') {
                top++; 
            }
            else if (expressao[i] == '>') {
                if (top >= 0) {      
                    top--;          
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}