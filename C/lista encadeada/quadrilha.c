#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do nó da lista encadeada
struct No
{
    char data[50];   // Armazena a palavra
    struct No *next; // Ponteiro para o próximo nó
};

// Função para criar um novo nó
struct No *createNo(char *word)
{
    struct No *newNo = (struct No *)malloc(sizeof(struct No));
    strcpy(newNo->data, word); // Copia a palavra para o campo 'data'
    newNo->next = NULL;        // Próximo nó é NULL
    return newNo;
}

// Função para inserir uma palavra ao final da lista
struct No *insertEnd(struct No *lista, char *word)
{
    struct No *newNo = createNo(word);

    if (lista == NULL)
    {
        return newNo;
    }

    struct No *last = lista;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNo;
    return lista;
}

// Função para imprimir a lista encadeada
void printList(struct No *No)
{
    while (No != NULL)
    {
        printf("%s ", No->data);
        No = No->next;
    }
    printf("\n");
}

int main()
{
    struct No *lista = NULL;

    // Inserindo palavras da estrofe como nós da lista encadeada
    lista = insertEnd(lista, "Joao");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "Teresa");
    lista = insertEnd(lista, "que");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "Raimundo");
    lista = insertEnd(lista, "que");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "Maria");
    lista = insertEnd(lista, "que");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "Joaquim");
    lista = insertEnd(lista, "que");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "Lili");
    lista = insertEnd(lista, "que");
    lista = insertEnd(lista, "nao");
    lista = insertEnd(lista, "amava");
    lista = insertEnd(lista, "ninguem");

    // Imprime a lista encadeada
    printf("Lista encadeada representando a primeira estrofe do poema Quadrilha:\n");
    printList(lista);

    return 0;
}
