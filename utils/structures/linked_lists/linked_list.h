/**
 * Implementation a linked list for int values
 *
 */


#ifndef __LINKED_LIST__
#define __LINKED_LIST__


#include <stdio.h>
#include <stdbool.h>
#include <errno.h>


typedef struct _linked_list_node {
    int cargo;
    struct _linked_list_node *next;
} linked_list_node_t;


linked_list_node_t *
linked_list_new(const int value)
{
    linked_list_node_t *linked_list;
    linked_list = malloc(sizeof(linked_list_node_t));

    if (linked_list == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    linked_list->cargo = value;
    linked_list->next = NULL;

    return linked_list;
}


unsigned int
linked_list_get_length(linked_list_node_t *linked_list)
{
    unsigned int length = 0;
    linked_list_node_t *node;

    node = linked_list;

    while (node) {
        node = node->next;
        ++length;
    }

    return length;
}


bool
linked_list_push_right(linked_list_node_t *linked_list, const int value)
{
    linked_list_node_t *node;
    node = malloc(sizeof(linked_list_node_t));

    if (node == NULL) {
        errno = ENOMEM;
        return false;
    }

    node->cargo = value;
    node->next = NULL;

    linked_list_node_t *linked_list_node;
    linked_list_node = linked_list;

    while (linked_list_node->next != NULL) {
        linked_list_node = linked_list_node->next;
    }

    linked_list_node->next = node;

    return true;
}


bool
linked_list_push_left(linked_list_node_t **linked_list, const int value)
{
    linked_list_node_t *node;
    node = malloc(sizeof(linked_list_node_t));

    if (node == NULL) {
        errno = ENOMEM;
        return false;
    }

    node->cargo = value;
    node->next = *linked_list;

    *linked_list = node;

    return true;
}


bool
linked_list_pop_left(linked_list_node_t **linked_list, int *value)
{
    linked_list_node_t *head;
    head = *linked_list;

    *value = (*linked_list)->cargo;

    free(head);

    *linked_list = (*linked_list)->next;

    return true;
}


bool
linked_list_pop_right(linked_list_node_t **linked_list, int *value)
{
    linked_list_node_t *node;

    node = *linked_list;

    while (node->next->next != NULL)
        node = node->next;

    *value = node->cargo;

    free(node->next);

    node->next = NULL;

    return true;
}


void
linked_list_print(linked_list_node_t *linked_list)
{
    linked_list_node_t *linked_list_node;
    linked_list_node = linked_list;

    putchar('[');
    while (linked_list_node != NULL){
        printf("%d", linked_list_node->cargo);
        linked_list_node = linked_list_node->next;
        if (linked_list_node) {
            printf(", ");
        }
    }
    puts("]");
}


void
linked_list_reverse(linked_list_node_t **linked_list)
{
    // linked_list_node_t *prev, *current, *next;

    // prev = NULL;
    // current = *linked_list;

    // while (current != NULL) {
    //     next = current->next;
    //     current->next = prev;
    //     prev = current;
    //     current = next;
    // }
    // *linked_list = prev;

}


linked_list_node_t *
linked_list_find_left(linked_list_node_t *linked_list, const int value, int *index)
{
    linked_list_node_t *node = linked_list;

    while(node) {
        if (node->cargo == value)
            return node;
        node = node->next;
    }

    return NULL;
}


linked_list_node_t *
linked_list_find_right(linked_list_node_t *linked_list, const int value, int *index)
{
    linked_list_node_t *node = linked_list;

    while(node) {
        if (node->cargo == value)
            return node;
        node = node->next;
    }

    return NULL;
}


int
linked_list_index_left(linked_list_node_t *linked_list, const int value)
{
    linked_list_node_t *node = linked_list;
    int index, i;

    index = -1;
    i = 0;

    while(node) {
        if (node->cargo == value)
            index = i;

        node = node->next;
        ++i;
    }

    return index;
}


int
linked_list_index_right(linked_list_node_t *linked_list, const int value)
{

}


void
linked_list_sort(linked_list_node_t *linked_list, const int value)
{
}


void
linked_list_destroy(linked_list_node_t *linked_list)
{
}


void
linked_list_test()
{

    int value;
    // int index;
    unsigned int length;

    linked_list_node_t *linked_list;
    linked_list = linked_list_new(21);

    if (linked_list == NULL) perror("MemoryError");

    linked_list_push_right(linked_list, -2);
    linked_list_push_right(linked_list, 71);
    linked_list_push_right(linked_list, 110);

    length = linked_list_get_length(linked_list);
    printf("Length is %d\n", length);
    linked_list_print(linked_list);

    linked_list_push_left(&linked_list, -2);
    linked_list_push_left(&linked_list, 999);

    length = linked_list_get_length(linked_list);
    printf("Length is %d\n", length);
    linked_list_print(linked_list);

    if (linked_list_find_left(linked_list, -2, &index)) {
        puts("-2 is found");
    } else {
        puts("-2 is not found");

    }

    if (linked_list_find_left(linked_list, -1, &index)) {
        puts("-1 is found");
    } else {
        puts("-1 is not found");

    }

    index = linked_list_index_left(linked_list, -2);

    linked_list_pop_left(&linked_list, &value);
    printf("Got after pop: %d\n", value);
    // linked_list_print(linked_list);
    // linked_list_pop_right(&linked_list, &value);
    // printf("Got after pop: %d\n", value);

    // length = linked_list_get_length(linked_list);
    // printf("Length is %d\n", length);
    // linked_list_print(linked_list);


    // --------------------
    // linked_list_reverse(&linked_list);
    // linked_list_destroy(linked_list);
}

#endif // __LINKED_LIST__
