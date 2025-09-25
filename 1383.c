#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool verifica_numeros(int numeros[]) {
    int freq[SIZE + 1] = {0}; // Índice 0 não será usado

    for (int i = 0; i < SIZE; i++) {
        int valor = numeros[i];
        if (valor < 1 || valor > 9) return false; // Valores fora do intervalo
        freq[valor]++;
    }

    for (int i = 1; i <= SIZE; i++) {
        if (freq[i] != 1) return false;
    }
    return true;
}

bool verifica_linhas(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!verifica_numeros(matriz[i])) return false;
    }
    return true;
}

bool verifica_colunas(int matriz[SIZE][SIZE]) {
    int coluna[SIZE];
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            coluna[i] = matriz[i][j];
        }
        if (!verifica_numeros(coluna)) return false;
    }
    return true;
}

bool verifica_subgrades(int matriz[SIZE][SIZE]) {
    int bloco[SIZE];
    for (int linha = 0; linha < SIZE; linha += 3) {
        for (int coluna = 0; coluna < SIZE; coluna += 3) {
            int k = 0;
            for (int i = linha; i < linha + 3; i++) {
                for (int j = coluna; j < coluna + 3; j++) {
                    bloco[k++] = matriz[i][j];
                }
            }
            if (!verifica_numeros(bloco)) return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        bool valido = verifica_linhas(matriz) &&
                      verifica_colunas(matriz) &&
                      verifica_subgrades(matriz);

        printf("Instancia %d\n", instancia);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}