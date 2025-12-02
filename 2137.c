#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
int main() {
    int N;
    char *codigos[1000];
    char gerenciar[5];
    //Utilizando qsort da biblioteca
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            codigos[i] = malloc(5 * sizeof(char));
            scanf("%s", codigos[i]);
        }
        qsort(codigos, N, sizeof(char *), compare);
        for (int i = 0; i < N; i++) {
            printf("%s\n", codigos[i]);
            free(codigos[i]);
        }
    }
}