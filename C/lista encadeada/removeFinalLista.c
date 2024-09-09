#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Função para remover o último nó da lista encadeada
void removeLast(struct Node** head) {
    // Se a lista estiver vazia
    if (*head == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }

    // Se a lista tem apenas um nó
    if ((*head)->next == NULL) {
        free(*head);  // Libera o nó
        *head = NULL; // Define o ponteiro principal como NULL
        return;
    }

    // Percorre a lista até o penúltimo nó
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Libera o último nó
    free(temp->next);
    temp->next = NULL; // Ajusta o ponteiro do penúltimo nó para NULL
}

// Função para adicionar nós ao final da lista
void insertEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Lista original:\n");
    printList(head);

    removeLast(&head);
    printf("Lista após remover o último elemento:\n");
    printList(head);

    removeLast(&head);
    printf("Lista após remover o último elemento novamente:\n");
    printList(head);

    return 0;
}
