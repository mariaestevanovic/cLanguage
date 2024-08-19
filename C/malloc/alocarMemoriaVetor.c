//escreva um programa em c que use malloc para alocar memória para um vetor de estruturas que representam alunos (nome, idade, nota). leia os dados de 3 alunos e imprima-os.

#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno *alunos;
    int i;

    alunos = (struct Aluno *)malloc(3 * sizeof(struct Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("Idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        getchar();
    }

    printf("\nDados dos alunos:\n");
    for (i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n\n", alunos[i].nota);
    }

    free(alunos);

    return 0;
}