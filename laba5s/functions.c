#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int getValidatedInput(const char* prompt) {
    int value;
    char term;
    while(1) {
        printf("%s", prompt);
        if(scanf("%d%c", &value, &term) == 2 && term == '\n') {
            return value;
        }
        while(getchar() != '\n');
        printf("Ошибка ввода. Требуется целое число.\n");
    }
}

bool initStack(Stack *stack, int capacity) {
    if(capacity <= 0) return false;
    stack->data = (int*)malloc(capacity * sizeof(int));
    if(!stack->data) return false;
    stack->capacity = capacity;
    stack->top = -1;
    return true;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool push(Stack *stack, int value) {
    if(isFull(stack)) return false;
    stack->data[++stack->top] = value;
    return true;
}

int pop(Stack *stack) {
    return isEmpty(stack) ? EMPTY_STACK_VALUE : stack->data[stack->top--];
}

void printStack(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Стек пуст\n");
        return;
    }
    for(int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

void findAndPrintUniqueElements(Stack *stack1, Stack *stack2) {
    Stack temp = {0};
    if(!initStack(&temp, stack1->capacity)) return;

    while(!isEmpty(stack1)) {
        int val = pop(stack1);
        bool found = false;
        for(int i = 0; i <= stack2->top; i++) {
            if(stack2->data[i] == val) {
                found = true;
                break;
            }
        }
        if(!found) push(&temp, val);
    }

    while(!isEmpty(&temp)) {
        int val = pop(&temp);
        printf("%d\n", val);
        push(stack1, val);
    }
    freeStack(&temp);
}

void freeStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->capacity = 0;
    stack->top = -1;
}
