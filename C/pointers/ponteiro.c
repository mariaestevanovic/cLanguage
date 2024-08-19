//escreva um programa em c que declare um ponteiro para um inteiro, atribua um valor a esse inteiro e, em seguida, imprima o valor do inteiro utilizando o ponteiro
#include<stdio.h>

//ponteiro com variavel int *p = &x, para ponteiro com vetor *p = x sem o &
int main() {
    int x = 10;
    int *p = &x;

    printf("O valor de x é: %d\n", *p);
    return 0;
}