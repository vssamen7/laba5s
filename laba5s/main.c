/*
Задание: Создать два стека для целых чисел. Максимальные размеры стеков вводится с экрана.
Вывести из первого стека все элементы которых нет во втором стеке, учитывая порядок хранения в стеке.

Студент: Алейник И.С.
Дата: 12.05.2023
*/
#include <stdio.h>
#include "functions.h"

int main() {
    Stack s1, s2;
    
    // Инициализация стеков
    while(!initStack(&s1, getValidatedInput("Размер первого стека: "))) {
        printf("Некорректный размер!\n");
    }
    
    while(!initStack(&s2, getValidatedInput("Размер второго стека: "))) {
        printf("Некорректный размер!\n");
    }

    // Заполнение стеков
    printf("Введите элементы первого стека:\n");
    while(!isFull(&s1)) {
        push(&s1, getValidatedInput("> "));
    }

    printf("Введите элементы второго стека:\n");
    while(!isFull(&s2)) {
        push(&s2, getValidatedInput("> "));
    }

    // Вывод результатов
    printf("\nСодержимое первого стека:\n");
    printStack(&s1);

    printf("\nСодержимое второго стека:\n");
    printStack(&s2);

    printf("\nУникальные элементы первого стека:\n");
    findAndPrintUniqueElements(&s1, &s2);

    freeStack(&s1);
    freeStack(&s2);
    return 0;
}



