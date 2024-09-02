//construa um programa utilizando uma pilha que resolva o seguinte problema. 
//armazene as placas dos carros (apenas os números) que estão estacionados numa rua sem saída. 
//dado uma placa verifique se o carro está estacionado na rua.
//caso esteja informe a sequência de carros que deverá ser retirada para que o carro em questão consiga sair.

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>

#define MAX 100  //maximum stack size

typedef struct {
    int top;
    int items[MAX];
} Stack;

void initialize(Stack *s) { //to initialize the stack
    s->top = -1;
}

int isFull(Stack *s) { //to check if the stack is full
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) { //to check if the stack is empty
    return s->top == -1;
}

void push(Stack *s, int value) { //to add a value to the stack (push)
    if (isFull(s)) {
        printf("Error: Stack overflow, cannot add car with plate %d.\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("Car with plate %d parked.\n", value);
    }
}

int pop(Stack *s) { //to remove a value from the stack (pop)
    if (isEmpty(s)) {
        printf("Error: Stack underflow, no cars to remove.\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int searchCar(Stack *s, int plate) { //to search for a car by its plate number in the stack
    for (int i = 0; i <= s->top; i++) {
        if (s->items[i] == plate) {
            return i;  //return the index of the plate
        }
    }
    return -1;  //return -1 if the car is not in the stack
}

void removeCarsUntil(Stack *s, int plate) { //to remove cars until the specified car can exit
    Stack tempStack;
    initialize(&tempStack);

    //check if the car is in the stack
    int position = searchCar(s, plate);
    if (position == -1) {
        printf("Car with plate %d is not parked in the street.\n", plate);
        return;
    }

    printf("Car with plate %d found. Removing cars to allow exit:\n", plate);
    
    //remove cars until the desired car is found
    while (!isEmpty(s)) {
        int removedCar = pop(s);
        if (removedCar == plate) {
            printf("Car with plate %d can exit.\n", removedCar);
            break;
        } else {
            push(&tempStack, removedCar);
            printf("Car with plate %d temporarily removed.\n", removedCar);
        }
    }

    //re-stack the cars back to the original stack
    while (!isEmpty(&tempStack)) {
        int car = pop(&tempStack);
        push(s, car);
        printf("Car with plate %d parked again.\n", car);
    }
}

int main() {
    Stack parking;
    initialize(&parking);

    //parking cars
    push(&parking, 1234);
    push(&parking, 5678);
    push(&parking, 9101);
    push(&parking, 1121);
    push(&parking, 3141);

    //check if a car can exit and print the necessary removal sequence
    removeCarsUntil(&parking, 9101);

    return 0;
}

//bool removeCarsUntil(int plate, Stack parking) {
//  int sequence[10];
//  int car = pop(&parking);
//  int count = 0;
//  if(car == plate) {
//      print("Nenhum carro precisa ser retirado");
//      return true
//  } else{
//      sequence[count] = car;
//      count++;
//  }
//  while(!isEmpty(&parking)){
//      car = pop(&parking);
//      if(car != plate) {
//          strcat(sequence, " ");
//          strcat(sequence, "%d", car);
//      } else {
//          printf("Sequencia de carros a ser retirada");
//          printf("%s", sequence);
//          return true;
//      }
//  }
//  return false;
//}