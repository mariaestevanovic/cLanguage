//desenvolva uma função em c que use um ponteiro para alterar o valor de uma variável inteira

#include<stdio.h>

int main() {
    int numero = 10;
    int *p = &numero;

    printf("Valor antes da alteração: %d\n", numero);

    *p = 42;

    printf("Valor depois da alteração: %d\n", numero);

    return 0;
}