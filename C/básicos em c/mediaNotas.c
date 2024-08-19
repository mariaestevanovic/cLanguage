//2 - desenvolva um programa em c que leia 5 notas de alunos, armazene-as em um vetor, e calcule a média das notas

#include <stdio.h>

int main () {
    int notas[5];
    int soma = 0;
    float media;

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%d", &notas[i]);
        soma += notas[i];
    }

    media = (float)soma / 5;

    printf("A média das notas dos alunos é: %.2f\n", media);

    return 0;
}