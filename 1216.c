#include <stdio.h>
#include <stdlib.h>

void calcular_media() {
    char linha_nome[100]; 
    char linha_distancia[100];
    
    double soma_distancias = 0.0;
    int contador_amigos = 0;

    while (fgets(linha_nome, sizeof(linha_nome), stdin) != NULL) {
        if (fgets(linha_distancia, sizeof(linha_distancia), stdin) == NULL) {
            break;
        }

        int distancia = atoi(linha_distancia);

        soma_distancias += distancia;
        contador_amigos++;
    }

    if (contador_amigos > 0) {
        double media = soma_distancias / contador_amigos;
        printf("%.1lf\n", media);
    }
}

int main() {
    calcular_media();
    return 0;
}