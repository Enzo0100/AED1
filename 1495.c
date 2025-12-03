#include <stdio.h>
#include <stdlib.h>

int comparar_diferencas(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, G;
    
    while (scanf("%d %d", &N, &G) != EOF) {
        
        int a, b;
        long long pontos = 0;
        
        int derrotas_diferenca[N];
        int num_derrotas = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            
            if (a > b) {
                pontos += 3;
            } else if (a == b) {
                pontos += 1;
                
                if (G > 0) {
                    pontos += 2; 
                    G--;         
                }
            } else { 
                derrotas_diferenca[num_derrotas++] = b - a;
            }
        }
        
        qsort(derrotas_diferenca, num_derrotas, sizeof(int), comparar_diferencas);
        
        for (int i = 0; i < num_derrotas; i++) {
            int diff = derrotas_diferenca[i];
            int custo_vitoria = diff + 1;
            
            if (G >= custo_vitoria) {
                pontos += 3; 
                G -= custo_vitoria;
            } else if (G == diff) {
                pontos += 1; 
                G -= diff;
            }
        }
        
        printf("%lld\n", pontos);
    }
    
    return 0;
}