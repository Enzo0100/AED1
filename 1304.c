#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int arr[1000];
    int topo;
} Pilha;

void empilhar(Pilha* p, int x) {
    p->arr[++(p->topo)] = x;
}

int desempilhar(Pilha* p) {
    return p->arr[(p->topo)--];
}

bool pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

typedef struct {
    int arr[1000];
    int frente, final;
} Fila;

void enfileirar(Fila* f, int x) {
    f->arr[f->final++] = x;
}

int desenfileirar(Fila* f) {
    return f->arr[f->frente++];
}

bool vazio(Fila* f) {
    return f->frente == f->final;
}

typedef struct {
    int arr[1000];
    int tamanho;
} FilaPrioridade;

void empilha_prioridade(FilaPrioridade* fp, int x) {
    fp->arr[fp->tamanho++] = x;
    int i = fp->tamanho - 1;
    while (i > 0 && fp->arr[i] > fp->arr[(i - 1) / 2]) {
        int temp = fp->arr[i];
        fp->arr[i] = fp->arr[(i - 1) / 2];
        fp->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int retira_prioridade(FilaPrioridade* fp) {
    int comeco = fp->arr[0];
    fp->arr[0] = fp->arr[--(fp->tamanho)];
    int i = 0, filho;
    while ((filho = 2 * i + 1) < fp->tamanho) {
        if (filho + 1 < fp->tamanho && fp->arr[filho + 1] > fp->arr[filho]) {
            filho++;
        }
        if (fp->arr[i] >= fp->arr[filho]) {
            break;
        }
        int temp = fp->arr[i];
        fp->arr[i] = fp->arr[filho];
        fp->arr[filho] = temp;
        i = filho;
    }
    return comeco;
}

bool prioridade_vazio(FilaPrioridade* fp) {
    return fp->tamanho == 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Pilha pilha = {.topo = -1};
        Fila fila = {.frente = 0, .final = 0};
        FilaPrioridade fila_prioridade = {.tamanho = 0};
        bool uma_pilha = true, uma_fila = true, fila_de_prioridade = true;
        for (int i = 0; i < n; ++i) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int x;
                scanf("%d", &x);
                if (uma_pilha) empilhar(&pilha, x);
                if (uma_fila) enfileirar(&fila, x);
                if (fila_de_prioridade) empilha_prioridade(&fila_prioridade, x);
            } else if (op == 2) {
                int x;
                scanf("%d", &x);
                bool valid_pilha = !pilha_vazia(&pilha) && desempilhar(&pilha) == x;
                bool valid_fila = !vazio(&fila) && desenfileirar(&fila) == x;
                bool valid_fila_prioridade = !prioridade_vazio(&fila_prioridade) && retira_prioridade(&fila_prioridade) == x;

                if (!valid_pilha) uma_pilha = false;
                if (!valid_fila) uma_fila = false;
                if (!valid_fila_prioridade) fila_de_prioridade = false;
            }
        }
        if (uma_pilha && !uma_fila && !fila_de_prioridade) {
            printf("stack\n");
        } else if (!uma_pilha && uma_fila && !fila_de_prioridade) {
            printf("queue\n");
        } else if (!uma_pilha && !uma_fila && fila_de_prioridade) {
            printf("priority queue\n");
        } else if (!uma_pilha && !uma_fila && !fila_de_prioridade) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}