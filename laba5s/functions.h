#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H

#include <stdbool.h>
#include <limits.h>

#define EMPTY_STACK_VALUE INT_MIN

typedef struct {
    int *data;
    int capacity;
    int top;
} Stack;

// Базовые операции стека
bool initStack(Stack *stack, int capacity);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
bool push(Stack *stack, int value);
int pop(Stack *stack);
void freeStack(Stack *stack);

// Вспомогательные функции
int getValidatedInput(const char* prompt);
void printStack(Stack *stack);
void findAndPrintUniqueElements(Stack *stack1, Stack *stack2);

#endif
