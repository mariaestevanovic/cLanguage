#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura de Fila
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Inicializa a fila
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Verifica se a fila está vazia
int isEmptyQueue(Queue* q) {
    return q->front == -1;
}

// Verifica se a fila está cheia
int isFullQueue(Queue* q) {
    return q->rear == MAX - 1;
}

// Enfileira um elemento
void enqueue(Queue* q, int value) {
    if (!isFullQueue(q)) {
        if (isEmptyQueue(q)) {
            q->front = 0;
        }
        q->data[++(q->rear)] = value;
    }
}

// Desenfileira um elemento
int dequeue(Queue* q) {
    if (!isEmptyQueue(q)) {
        int val = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return val;
    }
    return -1; // Retorna -1 se a fila estiver vazia
}

// Função para testar se as duas filas são iguais
void testarIgualdadeQueue(Queue* f1, Queue* f2) {
    if ((f1->rear - f1->front) != (f2->rear - f2->front)) {
        printf("As filas não são iguais. ");
        if ((f1->rear - f1->front) > (f2->rear - f2->front))
            printf("F1 é maior que F2.\n");
        else
            printf("F2 é maior que F1.\n");
        return;
    }

    for (int i = 0; i <= f1->rear; i++) {
        if (f1->data[i] != f2->data[i]) {
            printf("As filas não são iguais.\n");
            return;
        }
    }
    printf("As filas F1 e F2 são iguais.\n");
}

// Função para estatísticas (maior, menor, média) de uma fila
void estatisticasQueue(Queue* f) {
    if (isEmptyQueue(f)) {
        printf("A fila está vazia.\n");
        return;
    }

    int maior = f->data[f->front], menor = f->data[f->front];
    int soma = 0;
    int count = 0;

    for (int i = f->front; i <= f->rear; i++) {
        if (f->data[i] > maior)
            maior = f->data[i];
        if (f->data[i] < menor)
            menor = f->data[i];
        soma += f->data[i];
        count++;
    }

    double media = (double)soma / count;

    printf("Maior: %d, Menor: %d, Média: %.2f\n", maior, menor, media);
}

// Função para transferir os elementos de F1 para F2
void transferirQueue(Queue* f1, Queue* f2) {
    for (int i = f1->front; i <= f1->rear; i++) {
        enqueue(f2, f1->data[i]);
    }
    printf("Elementos transferidos de F1 para F2.\n");
}

// Função para contar o número de ímpares em uma fila
int contarImparesQueue(Queue* f) {
    int count = 0;
    for (int i = f->front; i <= f->rear; i++) {
        if (f->data[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Função para contar o número de pares em uma fila
int contarParesQueue(Queue* f) {
    int count = 0;
    for (int i = f->front; i <= f->rear; i++) {
        if (f->data[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    Queue f1, f2;
    initQueue(&f1);
    initQueue(&f2);

    enqueue(&f1, 5);
    enqueue(&f1, 10);
    enqueue(&f1, 15);

    enqueue(&f2, 5);
    enqueue(&f2, 10);
    enqueue(&f2, 15);

    testarIgualdadeQueue(&f1, &f2);

    estatisticasQueue(&f1);

    transferirQueue(&f1, &f2);

    printf("F1 possui %d números ímpares.\n", contarImparesQueue(&f1));
    printf("F1 possui %d números pares.\n", contarParesQueue(&f1));

    return 0;
}
