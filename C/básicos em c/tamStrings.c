//3- crie uma função que leia um vetor de strings e retorne o número do tamanho de caracteres de cada elemento

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função que retorna o tamanho de caracteres de cada elemento do vetor de strings
int* tamStrings(char **arr, int size) {
  //aloca um vetor de inteiros para armazenar os tamanhos
  int *tamanho = (int *)malloc(size * sizeof(int));
  if (tamanho == NULL) {
    printf("Erro ao alocar memória\n");
    return NULL;
  }
  //percorre o vetor de strings e calcula o tamanho de cada elemento
  for (int i = 0; i < size; i++) {
    tamanho[i] = strlen(arr[i]);
  }
  return tamanho;
}

int main() {
  int n;
  char **arr;
  int *tamanho;

  printf("Digite o número de strings: ");
  scanf("%d", &n);

  //aloca um vetor de strings
  arr = (char **)malloc(n * sizeof(char *));
  if (arr == NULL) {
    printf("Erro ao alocar memória\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    //aloca memória para cada string (até 100 caracteres)
    arr[i] = (char *)malloc(100 * sizeof(char));
    if (arr[i] == NULL) {
      printf("Erro ao alocar memória\n");
      for (int j = 0; j < i; j++) {
        //libera a memória alocada para as strings anteriores
        free(arr[j]);
      }
      free(arr);
      return 1;
    }
    printf("Digite a string %d: ", i + 1);
    //le a string do usuário
    scanf("%s", arr[i]);
  }

    //obtem os tamanhos das strings
    tamanho = tamStrings(arr, n);
    if (tamanho == NULL) {
        for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
        return 1;
    }

    //exibe os tamanhos das strings
    printf("Tamanhos das strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: %s (Tamanho: %d)\n", i + 1, arr[i], tamanho[i]);
    }

    //libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(tamanho);

    return 0;
}
