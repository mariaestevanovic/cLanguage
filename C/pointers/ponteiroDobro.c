//escreva uma função em c que receba o ponteiro para um inteiro e atualize o valor desse inteiro para o seu dobro. em seguida, crie um programa que tenha um valor inteiro chame a função em imprimir o valor atualizado.

#include <stdio.h>

void dobrarValor(int *p) {
    *p = *p * 2;
}

int main() {
    int valor = 10;

    printf("Valor antes da atualização: %d\n", valor);

    dobrarValor(&valor);

    printf("Valor depois da atualização: %d\n", valor);

    return 0;
}
