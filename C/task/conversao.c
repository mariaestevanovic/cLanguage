// Maria Clara Oliveira Estevanovic Moura

// 4. Conversão de Expressão Aritmética da Notação Infixa para a Notação Pós-Fixa
// Desenvolva um algoritmo para converter uma expressão aritmética da notação infixa (onde os operadores são colocados entre os 
// operandos) para a notação pós-fixa (também conhecida como notação polonesa reversa - RPN), onde os operadores são colocados após 
// seus operandos. O programa deve receber uma expressão aritmética em notação infixa. A expressão pode conter os operadores 
// +, -, *, /, e ^ (exponenciação), além de parênteses ( e ). A expressão pode incluir variáveis (representadas por letras) ou 
// números (opcionais). Exemplos de entrada incluem A + B * (C ^ D - E) ^ (F + G * H) - I, 3 + 4 * 2 / (1 - 5) ^ 2 ^ 3, A * (B + C) / D, e (A + B) * (C + D). 
// A saída deve ser a expressão correspondente em notação pós-fixa: A B C D ^ E - F G H * + ^ * + I -, 3 4 2 * 1 5 - 2 3 ^ ^ / +, A B C + * D /, e A B + C D + *, respectivamente.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Estrutura de pilha
typedef struct {
    char data[MAX]; // Array para armazenar os elementos da pilha
    int top; // Índice do topo da pilha
} Stack;

// Função para inicializar a pilha
void initStack(Stack* s) {
    s->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Função para empurrar um elemento para a pilha
void push(Stack* s, char c) {
    s->data[++(s->top)] = c;
}

// Função para remover um elemento do topo da pilha
char pop(Stack* s) {
    return s->data[(s->top)--];
}

// Função para obter o elemento no topo da pilha
char peek(Stack* s) {
    return s->data[s->top];
}

// Função para determinar a precedência dos operadores
int precedencia(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Função para converter uma expressão infixa para pós-fixa
void infixToPostfix(char* exp) {
    Stack s;
    initStack(&s); // Inicializa a pilha
    int i, k = 0;
    char output[MAX]; // Array para armazenar a expressão pós-fixa

    for (i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i]; // Adiciona operandos diretamente à saída
        } else if (exp[i] == '(') {
            push(&s, exp[i]); // Empurra '(' para a pilha
        } else if (exp[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                output[k++] = pop(&s); // Desempilha até encontrar '('
            }
            pop(&s); // Remove '(' da pilha
        } else {
            // Desempilha operadores de maior ou igual precedência
            while (!isEmpty(&s) && precedencia(exp[i]) <= precedencia(peek(&s))) {
                output[k++] = pop(&s);
            }
            push(&s, exp[i]); // Empurra o operador atual para a pilha
        }
    }

    // Desempilha todos os operadores restantes
    while (!isEmpty(&s)) {
        output[k++] = pop(&s);
    }

    output[k] = '\0'; // Termina a string de saída
    printf("Notação Pós-Fixa: %s\n", output); // Exibe a expressão pós-fixa
}

int main() {
    char exp[MAX] = "A+B*(C^D-E)^(F+G*H)-I"; // Exemplo de expressão infixa
    infixToPostfix(exp); // Converte e imprime a expressão pós-fixa
    return 0;
}