#include <stdio.h>

#define TAM_MAX 61
#define OFFSET 30

int contagem_botas[TAM_MAX][2];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        
        for (int i = 0; i < TAM_MAX; i++) {
            contagem_botas[i][0] = 0;
            contagem_botas[i][1] = 0;
        }
        
        int M;
        char L;
        
        for (int i = 0; i < N; i++) {
            if (scanf("%d %c", &M, &L) != 2) break;
            
            int indice = M - OFFSET;

            if (indice >= 0 && indice < TAM_MAX) {
                if (L == 'E') {
                    contagem_botas[indice][0]++;
                } else if (L == 'D') {
                    contagem_botas[indice][1]++;
                }
            }
        }
        
        int total_pares = 0;
        
        for (int i = 0; i < TAM_MAX; i++) {
            int pares_desse_tamanho = min(contagem_botas[i][0], contagem_botas[i][1]);
            
            total_pares += pares_desse_tamanho;
        }
        
        printf("%d\n", total_pares);
    }
    
    return 0;
}