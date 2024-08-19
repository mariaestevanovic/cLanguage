//desenvolva uma função em c que recebam um ponteiro para um float e atualize o valor para a metade. em seguida, crie um programa que leia um valor float, chame a função e imprima o valor atualizado.
#include <stdio.h>

void dividirValor(float *p) {
    *p = *p / 2;
}

int main() {
    float valor;

    printf("Digite um valor float: ");
    scanf("%f", &valor);

    printf("Valor antes da atualização: %.2f\n", valor);

    dividirValor(&valor);

    printf("Valor depois da atualização: %.2f\n", valor);

    return 0;
}