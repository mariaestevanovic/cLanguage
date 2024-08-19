//desenvolva um programa em c que use malloc para alocar memoria para uma string de 50 caracteres, leia uma string do usuário e imprima-a.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *string;

    string = (char *)malloc(50 * sizeof(char));

    if (string == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite uma string (máximo 49 caracteres): ");
    fgets(string, 50, stdin);

    printf("Você digitou: %s\n", string);

    free(string);

    return 0;
}
