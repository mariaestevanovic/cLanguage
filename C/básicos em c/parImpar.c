//1 - escreva um programa em c que solicite ao usuário um número inteiro e imprima na tela se esse número é par ou ímpar

#include <stdio.h>

int main() {
  int numero;

  printf("Digite um número inteiro: ");
  scanf("%d", &numero);

  if (numero % 2 == 0) {
    printf("O número %d é par.\n", numero);
  } else {
    printf("O número %d é ímpar.\n", numero);
  }

  return 0;
}