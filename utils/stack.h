/**
 * Implementation stack
 *
 *
 * Stack *stack = init();
 * printf("size: %li\n", stack->size);
 * printf("isEmpty: %d\n", stack->isEmpty);
 * print(stack);
 *
 * stack->push(stack, 11);
 * push(stack, -13);
 * push(stack, 43);
 * push(stack, -7843);
 *
 * printf("size: %li\n", stack->size);
 * printf("isEmpty: %d\n", stack->isEmpty);
 * print(stack);
 *
 * stack->pop(stack);
 * stack->pop(stack);
 *
 * printf("size: %li\n", stack->size);
 * printf("isEmpty: %d\n", stack->isEmpty);
 * stack->print(stack);
 * stack->clear(stack);
 *
 * stack->clear(stack);
 * printf("size: %li\n", stack->size);
 * printf("isEmpty: %d\n", stack->isEmpty);
 * stack->print(stack);
 *
 */


#include <stdio.h>
#include <stdbool.h>


#ifndef __STACK_H__
#define __STACK_H__


typedef struct _Stack {

    int *array;

    int head;
    int tail;

    size_t size;
    bool isEmpty;

    int (*push)(struct _Stack *stack, int value);
    int (*pop)(struct _Stack *stack);
    int (*clear)(struct _Stack *stack);
    void (*print)(struct _Stack *stack);

} Stack;


static int
push(Stack *stack, int value) {
    // stack->array = realloc(stack->array, sizeof(int) * stack->size + 1);
    stack->array[stack->size] = value;
    stack->size += 1;

    if (stack->size > 0) {
        stack->isEmpty = false;
    }

    return 0;
}

static int
pop(Stack *stack) {

    // stack->array = realloc(stack->array, sizeof(int) * stack->size + 1);

    stack->array[stack->size] = '\0';

    stack->size -= 1;

    if (stack->size == 0) {
        stack->isEmpty = true;
    }

    return 0;
}

static void
print(Stack *stack) {

    if (stack->isEmpty == true) {
        puts("Stack is empty");
        return;
    }

    int i = 0;
    printf("Stack: ");
    while (i < stack->size) {
        if (i > 0 && i < stack->size - 1) printf("%d,", stack->array[i]);
        else printf("%d", stack->array[i]);
        ++i;
    }
    puts("");
}


static int
clear(Stack *stack) {
    stack->isEmpty = true;
    stack->size = 0;
    stack->array = NULL;
    return 0;
}


Stack *
init() {
    Stack *stack;
    stack = malloc(sizeof(Stack));
    stack->array = malloc(sizeof(int));
    stack->size = 0;
    stack->isEmpty = true;

    stack->push = push;
    stack->clear = clear;
    stack->print = print;
    stack->pop = pop;

    return stack;
}


#endif // __STACK_H__
