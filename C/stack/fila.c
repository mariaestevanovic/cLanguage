#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Fila {
    int capacidade;
    int *dados;
    int primeiro;
    int ultimo;
    int nItens;
};

void criarFila(struct Fila *f, int c) {
    f->capacidade = c;
    f->dados = (int*) malloc(f->capacidade * sizeof(int));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}

void inserir(struct Fila *f, int v) {
    if (f->nItens == f->capacidade) {
        printf("Fila cheia!\n");
        return;
    }

    f->ultimo = (f->ultimo + 1) % f->capacidade;
    f->dados[f->ultimo] = v;
    f->nItens++;
}

void remover(struct Fila *f) {
    if (f->nItens == 0) {
        printf("Fila vazia!\n");
        return;
    }

    int removido = f->dados[f->primeiro];
    f->primeiro = (f->primeiro + 1) % f->capacidade;
    f->nItens--;
    printf("Removido: %d\n", removido);
}

void mostrarFila(struct Fila *f) {
    int i, count;
    for (i = 0, count = f->primeiro; i < f->nItens; i++) {
        printf("%d ", f->dados[count]);
        count = (count + 1) % f->capacidade;
    }
    printf("\n");
}

int main() {
    struct Fila fila;
    criarFila(&fila, 5);

    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);

    mostrarFila(&fila);

    remover(&fila);
    mostrarFila(&fila);

    inserir(&fila, 40);
    inserir(&fila, 50);
    inserir(&fila, 60);
    mostrarFila(&fila);

    remover(&fila);
    mostrarFila(&fila);

    free(fila.dados);

    return 0;
}
