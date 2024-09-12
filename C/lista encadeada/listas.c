#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
struct No
{
    int data;
    struct No *next;
};

// Função para criar um novo nó
struct No *createNo(int data)
{
    struct No *newNo = (struct No *)malloc(sizeof(struct No));
    newNo->data = data;
    newNo->next = NULL;
    return newNo;
}

// Inserir um elemento no início da lista
void insertAtBeginning(struct No **head, int data)
{
    struct No *newNo = createNo(data);
    newNo->next = *head;
    *head = newNo;
}

// Inserir um elemento na k-ésima posição
void insertAtKthPosition(struct No **head, int data, int k)
{
    if (k == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct No *current = *head;
    for (int i = 1; i < k - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Posição inválida!\n");
        return;
    }

    struct No *newNo = createNo(data);
    newNo->next = current->next;
    current->next = newNo;
}

// Excluir o primeiro elemento da lista
void deleteFirst(struct No **head)
{
    if (*head == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    struct No *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Excluir o último elemento da lista
void deleteLast(struct No **head)
{
    if (*head == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct No *current = *head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Excluir o k-ésimo elemento da lista
void deleteKth(struct No **head, int k)
{
    if (*head == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    if (k == 1)
    {
        deleteFirst(head);
        return;
    }

    struct No *current = *head;
    for (int i = 1; i < k - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Posição inválida!\n");
        return;
    }

    struct No *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Imprimir o primeiro elemento da lista
void printFirst(struct No *head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("Primeiro elemento: %d\n", head->data);
    }
}

// Imprimir o último elemento da lista
void printLast(struct No *head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    printf("Último elemento: %d\n", head->data);
}

// Imprimir o n-ésimo elemento da lista
void printNth(struct No *head, int n)
{
    for (int i = 1; i < n && head != NULL; i++)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Posição inválida!\n");
    }
    else
    {
        printf("Elemento %d: %d\n", n, head->data);
    }
}

// Retornar a quantidade de nós da lista
int countNos(struct No *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Retornar a soma dos valores dos nós
int sumNos(struct No *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int main()
{
    struct No *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtKthPosition(&head, 30, 2);

    printFirst(head);
    printLast(head);
    printNth(head, 2);

    printf("Quantidade de nós: %d\n", countNos(head));
    printf("Soma dos valores: %d\n", sumNos(head));

    deleteFirst(&head);
    deleteLast(&head);
    deleteKth(&head, 2);

    printf("Quantidade de nós após exclusões: %d\n", countNos(head));
    printf("Soma dos valores após exclusões: %d\n", sumNos(head));

    return 0;
}
