#include <stdio.h>
#include <stdlib.h>

int ordena_cresc(const void *i, const void *j) {
    return (*(int*)i - *(int*)j);
}

int ordena_descre(const void *i, const void *j) {
    return (*(int*)j - *(int*)i);
}

int main() {
    int N;

    scanf("%d", &N);{

    int pares[N], impares[N];
    int num_pares = 0, num_impares = 0;

    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        if (valor % 2 == 0) {
            pares[num_pares++] = valor;
        } else {
            impares[num_impares++] = valor;
        }
    }
    qsort(pares, num_pares, sizeof(int), ordena_cresc);
    qsort(impares, num_impares, sizeof(int), ordena_descre);

    for (int i = 0; i < num_pares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < num_impares; i++) {
        printf("%d\n", impares[i]);
    }
    return 0;
    }
}