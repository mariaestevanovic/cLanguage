//2- desenvolva uma função em c que receba um numero inteiro e retorne 1 se o numero for positivo e -1 se for negativo

#include <stdio.h>

int main () {
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num > 0){
        return 1;
    } else {
        return -1;
    }
}