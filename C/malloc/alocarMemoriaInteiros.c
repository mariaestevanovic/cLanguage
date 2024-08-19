//escreva um programa em c que use malloc para alocar memória para um vetor de 10 inteiros, lei =a os valores do usuário e imprima-os.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int i;

    vetor = (int *)malloc(10 * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Os números digitados foram:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
}