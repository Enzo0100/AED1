#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        int permutacao[1000];
        int i;

        while (1) {
            int primeiro;
            scanf("%d", &primeiro);
            if (primeiro == 0) break;

            permutacao[0] = primeiro;
            for (i = 1; i < N; i++) {
                scanf("%d", &permutacao[i]);
            }

            // simulaa a pilha e verifica vagao
            int pilha[1000];
            int top = -1;
            int vagao = 1; 
            int possivel = 1;

            for (i = 0; i < N; i++) {
                int x = permutacao[i];

                while (top == -1 || pilha[top] != x) {
                    if (vagao > N) {
                        possivel = 0;
                        break;
                    }
                    pilha[++top] = vagao++;
                }

                if (!possivel) break;
                top--; // remove o top da pilha
            }

            if (possivel) printf("Yes\n");
            else printf("No\n");
        }

        printf("\n");
    }

    return 0;
}