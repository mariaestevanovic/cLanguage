//utilizando a linguagem c, escreva um programa que crie uma pilha, insira alguns valores, e então teste as operações push, pop, peek. verifique se a pilha está funcionando corretamente em casos normais e em caso de limite (ex: empilhar em uma pilha cheia, desempilhar em uma pilha vazia).

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int top;
    int items[MAX];
} Stack;

void initialize(Stack *s) { //initialize the stack
    s->top = -1;
}

int isFull(Stack *s) { //to check if the stack is full
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) { //to check if the stack is empty
    return s->top == -1;
}

void push(Stack *s, int value) { //to add a value to the stack (push)
    if (isFull(s)) {
        printf("Erro: Pilha cheia, nao e possivel empilhar o valor %d.\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("Valor %d empilhado.\n", value);
    }
}

int pop(Stack *s) { //to remove a value from the stack (pop)
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia, nao e possivel desempilhar.\n");
        return -1;
    } else {
        int value = s->items[(s->top)--];
        printf("Valor %d desempilhado.\n", value);
        return value;
    }
}

int peek(Stack *s) { //to see the value on top of the stack (peek)
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia, nao ha valor para visualizar.\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  //stack overflow

    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Valor no topo da pilha: %d\n", topValue);
    }

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);  //stack underflow

    return 0;
}