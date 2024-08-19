//crie um programa em c que leia um numero inteiro e armazene-o em uma variável. use um ponteiro para imprimir o valor armazenado

#include<stdio.h>

int main() {
    int numero;
    int *p;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    p = &numero;
    
    printf("O valor armazenado é: %d\n", *p);

    return 0;
}