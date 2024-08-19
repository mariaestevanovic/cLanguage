//1- escreva uma função em c que receba um vetor de inteiros e seu tamanho, e imprima todos os elementos do vetor.

#include <stdio.h>

int main () {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}