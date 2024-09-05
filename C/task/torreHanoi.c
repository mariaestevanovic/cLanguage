// Maria Clara Oliveira Estevanovic Moura

// 3. Simulação do Jogo Torre de Hanói
// Implemente uma simulação do jogo Torre de Hanói, onde o objetivo é mover uma pilha de discos de um pino para outro seguindo 
// regras específicas: apenas um disco pode ser movido por vez, e um disco maior não pode ser colocado sobre um disco menor.
// Utilize pilhas para representar cada um dos três pinos, onde os discos são empilhados do maior (na base) ao menor (no topo).
// Comece com todos os discos no pino inicial e mova-os para o pino de destino, utilizando o pino auxiliar, se necessário. O jogo 
// deve respeitar a regra de que um disco maior não pode ser colocado sobre um disco menor. Por exemplo, se o pino inicial contém 
// os discos [3, 2, 1], o objetivo é movê-los para o pino de destino, utilizando o pino auxiliar conforme as regras do jogo.

#include <stdio.h>

// Função recursiva para mover os discos de um pino para outro
void moverDiscos(int num, char origem, char destino, char auxiliar) {
    if (num == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    moverDiscos(num - 1, origem, auxiliar, destino); // Move n-1 discos para o pino auxiliar
    printf("Mover disco %d de %c para %c\n", num, origem, destino); // Move o maior disco para o destino
    moverDiscos(num - 1, auxiliar, destino, origem); // Move os n-1 discos do auxiliar para o destino
}

int main() {
    int numDiscos = 3; // Número de discos
    moverDiscos(numDiscos, 'A', 'C', 'B'); // Inicia a movimentação dos discos da Torre de Hanói
    return 0;
}