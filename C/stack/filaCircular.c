#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // Retorna -1 se a pilha estiver vazia
}

// Função para testar se as duas pilhas são iguais
void testarIgualdade(Stack* p1, Stack* p2) {
    if (p1->top != p2->top) {
        printf("As pilhas não são iguais. ");
        if (p1->top > p2->top)
            printf("P1 é maior que P2.\n");
        else
            printf("P2 é maior que P1.\n");
        return;
    }
    for (int i = 0; i <= p1->top; i++) {
        if (p1->data[i] != p2->data[i]) {
            printf("As pilhas não são iguais.\n");
            return;
        }
    }
    printf("As pilhas P1 e P2 são iguais.\n");
}

// Função para estatísticas (maior, menor, média) de uma pilha
void estatisticas(Stack* p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
        return;
    }

    int maior = p->data[0], menor = p->data[0];
    int soma = 0;

    for (int i = 0; i <= p->top; i++) {
        if (p->data[i] > maior)
            maior = p->data[i];
        if (p->data[i] < menor)
            menor = p->data[i];
        soma += p->data[i];
    }

    double media = (double)soma / (p->top + 1);

    printf("Maior: %d, Menor: %d, Média: %.2f\n", maior, menor, media);
}

// Função para transferir os elementos de P1 para P2
void transferir(Stack* p1, Stack* p2) {
    for (int i = 0; i <= p1->top; i++) {
        push(p2, p1->data[i]);
    }
    printf("Elementos transferidos de P1 para P2.\n");
}

// Função para contar o número de ímpares em uma pilha
int contarImpares(Stack* p) {
    int count = 0;
    for (int i = 0; i <= p->top; i++) {
        if (p->data[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Função para contar o número de pares em uma pilha
int contarPares(Stack* p) {
    int count = 0;
    for (int i = 0; i <= p->top; i++) {
        if (p->data[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    Stack p1, p2;
    initStack(&p1);
    initStack(&p2);

    push(&p1, 5);
    push(&p1, 10);
    push(&p1, 15);

    push(&p2, 5);
    push(&p2, 10);
    push(&p2, 15);

    testarIgualdade(&p1, &p2);

    estatisticas(&p1);

    transferir(&p1, &p2);

    printf("P1 possui %d números ímpares.\n", contarImpares(&p1));
    printf("P1 possui %d números pares.\n", contarPares(&p1));

    return 0;
}
