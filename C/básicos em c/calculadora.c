//2 - desenvolva um programa em c que solicite ao usuário dois números inteiros e imprima na tela que leia dois números inteiros e imprima a soma, subtração, multiploicação e divisão desses números

#include <stdio.h>

int main () {
  int numero1, numero2;
  int sum, sub, mult, div;

  printf("Digite o primeiro número inteiro: ");
  scanf("%d", &numero1);

  printf("Digite o segundo número inteiro: ");
  scanf("%d", &numero2);

  sum = numero1 + numero2;
  sub = numero1 - numero2;
  mult = numero1 * numero2;
  div = numero1 / numero2;

  printf("A soma de %d e %d é %d\n", numero1, numero2, sum);
  printf("A subtração de %d e %d é %d\n", numero1, numero2, sub);
  printf("A multiplicação de %d e %d é %d\n", numero1, numero2, mult);
  printf("A divisão de %d e %d é %d\n", numero1, numero2, div);

  return 0;
}