//3 - crie um programa em c que leia 20 números inteiros e armazene-os em um vetor. depois, exiba apenas os números pares armazenados

#include <stdio.h>

int main () {
    int numeros[20];

    for (int i = 0; i < 20; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("Os números pares são: "); 

    for (int i = 0; i < 20; i++) {
        if (numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);
        }
    }

    return 0;
}