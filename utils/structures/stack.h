/**
 * Implementation a stack
 *
 * Stack is a data structure that works based on principle of last-in first-out (LIFO).
 * It means the last element that was added to the stack must be the first one to be removed.
 *
 */


#ifndef __STACK_H__
#define __STACK_H__


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define STACK_ERROR "StackError"
#define STACK_ERROR_IS_EMPTY "Stack is empty."
#define STACK_ERROR_IS_FULL "Stack is full."
#define STACK_ERROR_CREATION "Can`t create a stack."
#define STACK_ERROR_UNCORRECT_SIZE "Stack`s size must be at least 1."
#define STACK_ERROR_WAS_DESTROYED "Nothing to print, since a stack was destroyed."


typedef struct _stack {
    int *array;
    unsigned int size;
    unsigned int max_size;
} stack_t;


stack_t *
stack_new(unsigned int size) {

    stack_t *stack;

    if (size < 1) {
        fprintf(stderr, "%s: %s\n", STACK_ERROR, STACK_ERROR_UNCORRECT_SIZE);
        return NULL;
    }

    stack = (stack_t *)malloc(sizeof(stack_t));

    if (!stack) {
        fprintf(stderr, "%s: %s\n", STACK_ERROR, STACK_ERROR_CREATION);
        return NULL;
    }

    stack->array = (int *)malloc(sizeof(int) * size);
    stack->size = 0;
    stack->max_size = size;

    return stack;
}


void
stack_destroy(stack_t **stack) {
    memset((*stack)->array, 0, sizeof(int) * (*stack)->max_size);
    free((*stack)->array);
    free(*stack);
    *stack = NULL;
}


bool
stack_is_empty(stack_t *stack)
{

    return (stack->size == 0) ? true : false;
}


bool
stack_is_full(stack_t *stack)
{

    return (stack->max_size == stack->size) ? true : false;
}


bool
stack_push(stack_t *stack, const int value)
{
    if (stack_is_full(stack) == true) {
        fprintf(stderr, "%s: %s\n", STACK_ERROR, STACK_ERROR_IS_FULL);
        return false;
    }

    stack->array[stack->size] = value;
    stack->size += 1;

    return true;
}


bool
stack_pop(stack_t *stack, int *value)
{
    if (stack_is_empty(stack) == true) {
        fprintf(stderr, "%s: %s\n", STACK_ERROR, STACK_ERROR_IS_EMPTY);
        return false;
    }

    *value = stack->array[stack->size - 1];
    stack->array[stack->size - 1] = 0;
    stack->size -= 1;

    return 0;
}


void
stack_print(stack_t *stack)
{
    if (stack != NULL) {
        if (stack_is_empty(stack) == true)
            puts("[]");
        else {
            putchar('[');
            for (int i = 0; i < stack->size; ++i) {
                printf("%d", stack->array[i]);
                if (i != stack->size - 1)
                    printf(", ");
            }
            puts("]");
        }
    } else
        fprintf(stderr, "%s: %s\n", STACK_ERROR, STACK_ERROR_WAS_DESTROYED);
}


void
stack_clear(stack_t *stack)
{
    stack->size = 0;
    memset(stack->array, 0, sizeof(int) * stack->max_size);
}


bool
stack_get_tail(stack_t *stack, int *value)
{
    if (stack_is_empty(stack) == true)
        return false;
    *value = stack->array[0];
    return true;
}


bool
stack_get_head(stack_t *stack, int *value)
{
    if (stack_is_empty(stack) == true)
        return false;
    *value = stack->array[stack->size - 1];
    return true;
}


void
stack_test()
{
    int value;
    bool status;
    stack_t *stack;

    stack = stack_new(10);
    stack_print(stack);

    stack_push(stack, -5);
    stack_push(stack, 4);
    stack_push(stack, -3);
    stack_push(stack, 1);
    stack_push(stack, 3);

    puts("Before clear");
    stack_print(stack);
    stack_clear(stack);
    puts("After clear");
    stack_print(stack);

    stack_push(stack, -5);
    stack_push(stack, 4);
    stack_push(stack, -3);
    stack_push(stack, 1);
    stack_push(stack, 3);

    status = stack_get_head(stack, &value);
    if (status == true)
        printf("Head is %d\n", value);
    else
        puts("Unknown head");

    status = stack_get_tail(stack, &value);
    if (status == true)
        printf("Tail is %d\n", value);
    else
        puts("Unknown tail");

    stack_pop(stack, &value);
    stack_pop(stack, &value);
    stack_pop(stack, &value);
    stack_pop(stack, &value);
    stack_pop(stack, &value);
    stack_pop(stack, &value);

    stack_print(stack);

    stack_destroy(&stack);
    stack_print(stack);

}


#endif // __STACK_H__
