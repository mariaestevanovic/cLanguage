// Maria Clara Oliveira Estevanovic Moura

// 1. Simulação de Torneio de Pedra-Papel-Tesoura com Fila
// Desenvolva uma simulação de um torneio de Pedra-Papel-Tesoura onde os jogadores competem em pares e os vencedores continuam para
// a próxima rodada. Utilize uma fila para organizar os jogadores. A cada rodada, dois jogadores são removidos da fila e competem
// entre si. O vencedor da partida deve retornar ao final da fila, enquanto o perdedor é eliminado do torneio.O processo continua
// até que reste apenas um jogador na fila, que será o campeão do torneio. Por exemplo, se a fila inicial tiver 8 jogadores, o
// algoritmo deve continuar removendo pares de jogadores, competindo, e reordenando os vencedores até que reste apenas um vencedor
// final.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_JOGADORES 8 // Define o número máximo de jogadores

// Estrutura para representar cada nó da fila, armazenando o jogador
typedef struct No
{
    int jogador;
    struct No *next;
} No;

// Função para criar a fila de jogadores
No *criarFila(int numJogadores)
{
    No *front = NULL;
    No *rear = NULL;
    for (int i = 1; i <= numJogadores; i++)
    {
        No *newNo = (No *)malloc(sizeof(No)); // Cria um novo nó para o jogador
        newNo->jogador = i;                   // Atribui o número do jogador
        newNo->next = NULL;
        if (rear == NULL)
        {
            front = newNo; // Define o primeiro nó (início da fila)
            rear = newNo;
        }
        else
        {
            rear->next = newNo; // Adiciona o novo nó ao final da fila
            rear = newNo;
        }
    }
    return front;
}

// Função que simula a partida de Pedra-Papel-Tesoura entre dois jogadores
int pedraPapelTesoura(int jogador1, int jogador2)
{
    // Simula um vencedor aleatório (jogador1 ou jogador2)
    return (rand() % 2) ? jogador1 : jogador2;
}

// Função principal que simula o torneio
void torneio(No *front)
{
    while (front->next != NULL)
    {
        int jogador1 = front->jogador;
        front = front->next;
        int jogador2 = front->jogador;
        front = front->next;
        int vencedor = pedraPapelTesoura(jogador1, jogador2); // Determina o vencedor
        printf("Jogador %d venceu Jogador %d\n", vencedor, (vencedor == jogador1) ? jogador2 : jogador1);

        // O vencedor retorna ao final da fila
        No *newNo = (No *)malloc(sizeof(No));
        newNo->jogador = vencedor;
        newNo->next = NULL;

        if (front == NULL)
        {
            front = newNo;
        }
        else
        {
            No *temp = front;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNo;
        }
    }
    printf("Campeão do torneio: Jogador %d\n", front->jogador);
}

int main()
{
    srand(time(NULL));                   // Inicializa o gerador de números aleatórios
    No *fila = criarFila(MAX_JOGADORES); // Cria a fila de jogadores
    torneio(fila);                       // Inicia o torneio
    return 0;
}