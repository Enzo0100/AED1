#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VAL 14
#define MAX_SUIT 4

int valor_para_int(char v) {
    if (v >= '2' && v <= '9') return v - '0';
    switch (v) {
        case '1': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        default: return 0;
    }
}

char int_para_valor(int i) {
    if (i >= 2 && i <= 9) return i + '0';
    switch (i) {
        case 1: return 'A';
        case 10: return 'T';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        default: return '?';
    }
}

int naipe_para_int(char n) {
    switch (n) {
        case 'H': return 0;
        case 'C': return 1;
        case 'D': return 2;
        case 'S': return 3;
        default: return -1;
    }
}

char int_para_naipe(int i) {
    switch (i) {
        case 0: return 'H';
        case 1: return 'C';
        case 2: return 'D';
        case 3: return 'S';
        default: return '?';
    }
}

typedef struct {
    int valor;
    int naipe;
    char valor_char;
    char naipe_char;
} Carta;

int comparar_cartas(const void *a, const void *b) {
    Carta *cartaA = (Carta *)a;
    Carta *cartaB = (Carta *)b;

    if (cartaA->naipe != cartaB->naipe) {
        return cartaA->naipe - cartaB->naipe;
    }
    return cartaA->valor - cartaB->valor;
}

int decodificar_numero(Carta z1, Carta z2, Carta z3) {
    Carta trio[3] = {z1, z2, z3};
    
    qsort(trio, 3, sizeof(Carta), comparar_cartas);
    
    Carta z_menor = trio[0];
    Carta z_meio = trio[1];
    Carta z_maior = trio[2];

    if (z1.valor == z_menor.valor && z2.valor == z_meio.valor && z3.valor == z_maior.valor) return 1;
    if (z1.valor == z_menor.valor && z2.valor == z_maior.valor && z3.valor == z_meio.valor) return 2;
    if (z1.valor == z_meio.valor && z2.valor == z_menor.valor && z3.valor == z_maior.valor) return 3;
    if (z1.valor == z_meio.valor && z2.valor == z_maior.valor && z3.valor == z_menor.valor) return 4;
    if (z1.valor == z_maior.valor && z2.valor == z_menor.valor && z3.valor == z_meio.valor) return 5;
    if (z1.valor == z_maior.valor && z2.valor == z_meio.valor && z3.valor == z_menor.valor) return 6;
    
    return 0;
}

int decodificar_naipe(Carta c1) {
    return c1.naipe;
}

void processar_caso_teste() {
    char s_cartas[4][4];
    Carta cartas_reveladas[4];
    
    if (scanf("%s %s %s %s", s_cartas[0], s_cartas[1], s_cartas[2], s_cartas[3]) != 4) return;

    for (int i = 0; i < 4; i++) {
        char valor_char, naipe_char;
        
        if (strlen(s_cartas[i]) == 2) {
            valor_char = s_cartas[i][0];
            naipe_char = s_cartas[i][1];
        } else {
             valor_char = s_cartas[i][0];
             naipe_char = s_cartas[i][1];
        }
        
        cartas_reveladas[i].valor_char = valor_char;
        cartas_reveladas[i].naipe_char = naipe_char;
        cartas_reveladas[i].valor = valor_para_int(valor_char);
        cartas_reveladas[i].naipe = naipe_para_int(naipe_char);
    }

    Carta carta_reveladora_Y = cartas_reveladas[0];
    
    Carta z1_apresentada = cartas_reveladas[1];
    Carta z2_apresentada = cartas_reveladas[2];
    Carta z3_apresentada = cartas_reveladas[3];

    int naipe_oculto_int = decodificar_naipe(carta_reveladora_Y);
    
    int k = decodificar_numero(z1_apresentada, z2_apresentada, z3_apresentada);

    int valor_Y = carta_reveladora_Y.valor;
    
    int valor_X_int = (valor_Y - 1 + k) % 13 + 1;

    char naipe_X_char = int_para_naipe(naipe_oculto_int);
    char valor_X_char = int_para_valor(valor_X_int);

    if (valor_X_char == 'A') valor_X_char = '1';
    
    printf("%c%c\n", valor_X_char, naipe_X_char);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 1;

    for (int i = 0; i < N; i++) {
        processar_caso_teste();
    }

    return 0;
}