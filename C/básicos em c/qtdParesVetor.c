//3- crie uma função em c que receba um vetor de inteiros e seu tamanho, e retorne a quantidade de elementos pares no vetor.

#include <stdio.h>

int main () {
    //declara e inicializa o vetor
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //calcula o tamanho do vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
     //variável para armazenar a soma dos elementos
    int pares = 0;

    //percorre o vetor para encontrar os numeros pares
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    printf("A quantidade de elementos pares são: %d\n", pares);

    //retorna a soma de todos os elementos do vetor
    return 0;
}