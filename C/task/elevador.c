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
typedef struct No
{
    int andar; // Armazena o andar solicitado
    struct No *next;
} No;

// Função para adicionar uma solicitação de andar à fila
void adicionarSolicitacao(No **front, No **rear, int andar)
{
    No *newNo = (No *)malloc(sizeof(No)); // Cria um novo nó
    newNo->andar = andar;                 // Atribui o andar solicitado
    newNo->next = NULL;
    if (*rear == NULL)
    {
        *front = newNo; // Se a fila está vazia, define o novo nó como o primeiro
        *rear = newNo;
    }
    else
    {
        (*rear)->next = newNo; // Adiciona a solicitação ao final da fila
        *rear = newNo;
    }
}

// Função que simula o movimento do elevador e processa as solicitações
void processarElevador(No **front)
{
    int andarAtual = 0; // O elevador começa no andar 0
    while (*front != NULL)
    {
        printf("Movendo do andar %d para o andar %d\n", andarAtual, (*front)->andar);
        andarAtual = (*front)->andar; // Atualiza o andar atual do elevador
        No *temp = *front;            // Remove a solicitação processada da fila
        *front = (*front)->next;
        free(temp); // Libera a memória
    }
    printf("Elevador parado no andar %d\n", andarAtual); // O elevador para no último andar processado
}

int main()
{
    No *front = NULL; // Ponteiro para o início da fila
    No *rear = NULL;  // Ponteiro para o final da fila

    adicionarSolicitacao(&front, &rear, 5); // Solicita o andar 5
    adicionarSolicitacao(&front, &rear, 3); // Solicita o andar 3
    adicionarSolicitacao(&front, &rear, 8); // Solicita o andar 8

    processarElevador(&front); // Processa as solicitações
    return 0;
}