//1- escreva um programa em c que leia um vetor de 10 elementos inteiros e encontre o maior e o menor valor armazenado no vetor

#include <stdio.h>

int main () {
    int vetor[5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int maior = vetor[0];
    int menor = vetor[0];

    for (int i =1; i < 0; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        } else {
            menor = vetor[i];
        }
    }

    return 0;
}