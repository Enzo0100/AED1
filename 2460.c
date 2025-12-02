#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d", &N);

    int fila[N]; //array com o tamanho de pessoas na fila e alocação dos identificadores
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);
    int removidos[M]; //array das pessoas que sairam da fila e dos identificadores
    for (int i = 0; i < M; i++) {
        scanf("%d", &removidos[i]);
    }

    static int sairam[100001] = {0};

for(int i =0; i < M; i++){ //marca as pessoas que sairam da fila com 1
    sairam[removidos[i]] = 1;
}

 int primeira = 1;
    for (int i = 0; i < N; i++) { //imprime a lista com as pessoas restantes
        if (!sairam[fila[i]]) {
            if (!primeira) printf(" ");
            printf("%d", fila[i]);
            primeira = 0;
        }
    }

    printf("\n");
    return 0;

}
