#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int tamanho;
    char cor;
} Andar;

int compararAndares(const void *a, const void *b) {
    const Andar *andarA = (const Andar *)a;
    const Andar *andarB = (const Andar *)b;
    return andarA->tamanho - andarB->tamanho;
}

void resolverCaso() {
    int n;
    if (scanf("%d", &n) != 1) return;

    Andar *andares = (Andar *)malloc(n * sizeof(Andar));
    if (andares == NULL) return;

    for (int i = 0; i < n; i++) {
        int valor;
        if (scanf("%d", &valor) != 1) {
            free(andares);
            return;
        }
        
        andares[i].tamanho = abs(valor);
        andares[i].cor = (valor > 0) ? 'A' : 'V';
    }

    qsort(andares, n, sizeof(Andar), compararAndares);

    int max_len_A = 0;
    int max_len_V = 0;
    int max_total = 0;

    for (int i = 0; i < n; i++) {
        int current_len_A = 0;
        int current_len_V = 0;

        if (andares[i].cor == 'A') {
            current_len_A = max_len_V + 1;
            
            if (current_len_A > max_len_A) {
                max_len_A = current_len_A;
            }
        } else {
            current_len_V = max_len_A + 1;

            if (current_len_V > max_len_V) {
                max_len_V = current_len_V;
            }
        }
        
        if (max_len_A > max_total) {
            max_total = max_len_A;
        }
        if (max_len_V > max_total) {
            max_total = max_len_V;
        }
    }

    printf("%d\n", max_total);

    free(andares);
}

int main() {
    int p;
    if (scanf("%d", &p) != 1) return 0;

    while (p--) {
        resolverCaso();
    }

    return 0;
}