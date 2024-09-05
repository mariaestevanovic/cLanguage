// Maria Clara Oliveira Estevanovic Moura

// 2. Simulação do Funcionamento de um Elevador em um Prédio
// Crie uma simulação para o funcionamento de um elevador em um prédio, onde as pessoas entram no elevador e solicitam andares 
// específicos. Use uma fila para armazenar as solicitaçõesde andares. O elevador processa cada solicitação na ordem em que foi 
// recebida, "movendo-se"para o andar desejado e então removendo a solicitação da fila. Se houver múltiplos elevadores, cada um 
// terá sua própria fila de solicitações a ser processada de forma independente. Por exemplo, se o elevador receber solicitações
// para os andares 5, 3 e 8, ele deve mover-se para o andar 5, depois para o andar 3, e por último para o andar 8. Novas 
// solicitações devem ser adicionadas ao final da fila do elevador.

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar cada solicitação na fila do elevador
typedef struct Node {
    int andar; // Armazena o andar solicitado
    struct Node* next;
} Node;

// Função para adicionar uma solicitação de andar à fila
void adicionarSolicitacao(Node** front, Node** rear, int andar) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cria um novo nó
    newNode->andar = andar; // Atribui o andar solicitado
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = newNode; // Se a fila está vazia, define o novo nó como o primeiro
        *rear = newNode;
    } else {
        (*rear)->next = newNode; // Adiciona a solicitação ao final da fila
        *rear = newNode;
    }
}

// Função que simula o movimento do elevador e processa as solicitações
void processarElevador(Node** front) {
    int andarAtual = 0; // O elevador começa no andar 0
    while (*front != NULL) {
        printf("Movendo do andar %d para o andar %d\n", andarAtual, (*front)->andar);
        andarAtual = (*front)->andar; // Atualiza o andar atual do elevador
        Node* temp = *front; // Remove a solicitação processada da fila
        *front = (*front)->next;
        free(temp); // Libera a memória
    }
    printf("Elevador parado no andar %d\n", andarAtual); // O elevador para no último andar processado
}

int main() {
    Node* front = NULL; // Ponteiro para o início da fila
    Node* rear = NULL; // Ponteiro para o final da fila

    adicionarSolicitacao(&front, &rear, 5); // Solicita o andar 5
    adicionarSolicitacao(&front, &rear, 3); // Solicita o andar 3
    adicionarSolicitacao(&front, &rear, 8); // Solicita o andar 8

    processarElevador(&front); // Processa as solicitações
    return 0;
}