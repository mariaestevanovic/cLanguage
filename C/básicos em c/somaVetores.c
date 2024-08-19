//2- desenvolva uma função em c que receba o vetor de inteiros e seu tamanho, e retorne a soma de todos os elementos do vetor.

#include <stdio.h>

int main () {
    //declara e inicializa o vetor
    int vetor[] = {1, 2, 3, 4, 5};
    //calcula o tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
     //variável para armazenar a soma dos elementos
    int soma = 0;

    //calcula a soma de todos os elementos do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    printf("A soma dos vetores é: %d\n", soma);

    //retorna a soma de todos os elementos do vetor
    return 0;
}