//3- crie uma função em c que receba um número inteiro e verifique se ele é primo, retornando 1 para verdadeiro e 0 para falso.

#include <stdio.h>

int main () {
    int num, primo = 1;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (num <= 1) {
        primo = 0;
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo){
        printf("%d é um número primo.\n", num);
    } else {
        printf("%d não é um número primo.\n", num);
    }
    
    return primo;
}