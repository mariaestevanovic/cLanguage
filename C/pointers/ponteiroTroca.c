//crie uma função em cque receba dois ponteiros para inteiros e troque os valores apontados por esses ponteiros. em seguida, crie um programa que leia os valores inteiros chama a função entre os valores após a troca.

#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int main() {
    int valor1, valor2;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    printf("Valores antes da troca: %d e %d\n", valor1, valor2);

    trocarValores(&valor1, &valor2);

    printf("Valores após a troca: %d e %d\n", valor1, valor2);

    return 0;
}