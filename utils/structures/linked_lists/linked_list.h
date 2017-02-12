/**
 * Implementation a linked list for int values
 *
 */


#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


#include <stdio.h>
#include <stdbool.h>
#include <errno.h>


#define LINKED_LIST_ERROR_INDEX_MUST_BE_MORE_MINUS_1 "ValueError: Index must be more or equal -1"
#define LINKED_LIST_ERROR_IS_EMTPY "ValueError: A linked list is empty"


typedef struct _linked_list_node {
    int cargo;
    struct _linked_list_node *next;
} linked_list_node_t;



/**
 * Description
 */

linked_list_node_t *
__linked_list_create_new_node(const int value)
{
    linked_list_node_t *node;
    node = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));

    if (node == NULL) {
        errno = ENOMEM;
        fprintf(stderr, "MemoryError: Can`t create new node of a linked list\n");
        return NULL;
    }

    node->cargo = value;
    node->next = NULL;

    return node;

}


linked_list_node_t *
linked_list_new(const int value)
{

    return __linked_list_create_new_node(value);
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


linked_list_node_t *
linked_list_insert(linked_list_node_t **linked_list, const int value, const int index)
{
    unsigned int i;
    linked_list_node_t *new_node;
    linked_list_node_t *linked_list_node;

    // an index must be from -1 to an infinity+
    if (index < -1) {
        fprintf(stderr, "%s\n", LINKED_LIST_ERROR_INDEX_MUST_BE_MORE_MINUS_1);
        return NULL;
    }

    // create a new node, return NULL if it is not possible
    new_node = __linked_list_create_new_node(value);
    if (!new_node) return NULL;

    // a pointer to the head
    linked_list_node = *linked_list;

    // append to the end
    if (index == -1) {
        while (linked_list_node->next != NULL) {
            linked_list_node = linked_list_node->next;
        }
        linked_list_node->next = new_node;

    // prepend to the head
    } else if (index == 0) {
        new_node->next = *linked_list;
        *linked_list = new_node;

    // insert the new node by the index
    } else {
        for (i = 0; linked_list_node->next != NULL; ++i, linked_list_node = linked_list_node->next) {
            if ((i + 1) == index) {
                new_node->next = linked_list_node->next;
                linked_list_node->next = new_node;
                return new_node;
            }
        }

        // if the index is more than count items, then append it to the end
        linked_list_node->next = new_node;
    }

    return new_node;
}


bool
linked_list_remove(linked_list_node_t **linked_list, int *value, const int index)
{
    unsigned int i;
    linked_list_node_t *current, *prev;

    // false, if a linked list is empty
    if (*linked_list == NULL) {
        fprintf(stderr, "%s\n", LINKED_LIST_ERROR_IS_EMTPY);
        return false;
    }

    current = *linked_list;
    prev = NULL;

    // an index must be from -1 to an infinity+
    if (index < -1) {
        fprintf(stderr, "%s\n", LINKED_LIST_ERROR_INDEX_MUST_BE_MORE_MINUS_1);
        return false;

    // remove the last item
    } else if (index == -1) {
        while (current->next) {
            prev = current;
            current = current->next;
        }
        *value = current->cargo;
        free(current);
        if (prev)
            prev->next = NULL;
        *linked_list = (*linked_list)->next;
        return true;

    // remove the first item
    } else if (index == 0) {
        *value = (*linked_list)->cargo;
        free(current);
        *linked_list = (*linked_list)->next;
        return true;

    // remove an item by index, if present
    } else {
        i = 0;
        while (current) {
            if (i == index) {
                *value = current->cargo;
                prev->next = current->next;
                free(current);
                return true;
            }
            prev = current;
            current = current->next;
            ++i;
        }
        return false;
    }

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
    linked_list_node_t *prev, *current, *next;

    current = *linked_list;
    prev = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *linked_list = prev;

}


unsigned int
linked_list_count(linked_list_node_t *linked_list, const int value, const unsigned int start_index)
{
    linked_list_node_t *node = linked_list;
    unsigned int count = 0;
    unsigned int i  = 0;

    while (node) {
        if (node->cargo == value) {
            if (i >= start_index)
                ++count;
        }
        node = node->next;
        ++i;
    }

    return count;
}


linked_list_node_t *
linked_list_find(linked_list_node_t *linked_list, const int value, int *keep_index, const int start_index)
{
    int i = 0;
    linked_list_node_t *node, *found_node;

    if (start_index < -1) {
        fprintf(stderr, "%s\n", LINKED_LIST_ERROR_INDEX_MUST_BE_MORE_MINUS_1);
        return NULL;
    }

    // a pointer to the head
    node = linked_list;

    found_node = NULL;

    while(node) {
        if (node->cargo == value) {
            if (start_index == -1) {
                *keep_index = i;
                found_node = node;
            } else if (i >= start_index){
                *keep_index = i;
                return node;
            }
        }
        node = node->next;
        ++i;
    }

    // if the index is more than length of a linked list
    // keep_index must be -1, what mean "Not Found"
    if (start_index != -1 && i < start_index) {
        *keep_index = -1;
    }

    return found_node;
}


linked_list_node_t *
linked_list_index(linked_list_node_t *linked_list, const unsigned int index)
{
    linked_list_node_t *node = linked_list;
    int i = 0;

    while(node) {
        if (i == index)
            return node;
        node = node->next;
        ++i;
    }
    return NULL;
}


void
linked_list_destroy(linked_list_node_t **linked_list)
{
    linked_list_node_t *current, *next;

    current = *linked_list;
    next = NULL;

    while (current != NULL) {
        free(current);
        next = current->next;
        current = next;
    }
    *linked_list = NULL;
}


// Not implemented
// learn algorith of sorting
void
linked_list_sort(linked_list_node_t **linked_list)
{

}


void
linked_list_traverse(linked_list_node_t *linked_list, void (*callback)())
{
    linked_list_node_t *node;

    node = linked_list;
    while (node) {
        callback(node);
        node = node->next;
    }
}


/**
 * Tests
 */


void
test_linked_list_find(linked_list_node_t *linked_list)
{
    int index;

    int data[8][2] = {
        {-2, 0},
        {-2, 3},
        {-2, 4},
        {-2, -1},
        {-2, 10},
        {-200, 10},
        {-200, -1},
        {-200, 0},
    };

    for (int i = 0; i < 8; ++i) {
        if (linked_list_find(linked_list, data[i][0], &index, 0))
            printf("Loop up %d from %d is found on index %d\n", data[i][0], data[i][1], index);
        else
            printf("Look up %d from %d is not found\n", data[i][0], data[i][1]);
    }
}

void
test_linked_list_insert(linked_list_node_t **linked_list)
{
    linked_list_insert(linked_list, -2, -1);
    linked_list_insert(linked_list, 71, 0);
    linked_list_insert(linked_list, 110, -1);
    linked_list_insert(linked_list, 10, 1);
    linked_list_insert(linked_list, 4, 3);
    linked_list_insert(linked_list, -2, 5);
    linked_list_insert(linked_list, 789, 1000);
}


void
test_linked_list_count(linked_list_node_t *linked_list)
{
    unsigned int count;

    count = linked_list_count(linked_list, -2, 0);
    printf("Found -2 from 0 in count %d\n", count);

    count = linked_list_count(linked_list, -2, 3);
    printf("Found -2 from 3 in count %d\n", count);

    count = linked_list_count(linked_list, -2, 4);
    printf("Found -2 from 4 in count %d\n", count);

    count = linked_list_count(linked_list, -2, 6);
    printf("Found -2 from 6 in count %d\n", count);

    count = linked_list_count(linked_list, 99999, 0);
    printf("Found 99999 from 0 in count %d\n", count);

}


void
test_linked_list_index(linked_list_node_t *linked_list)
{
    linked_list_node_t *node;
    static const int data[6] = {2, 8, 1, 9999, 0, 7};

    for (int i = 0; i < 6; ++i) {
        node = linked_list_index(linked_list, data[i]);
        if (node)
            printf("Node on index %d has value %d\n", data[i], node->cargo);
        else
            printf("Node on index %d is not exists\n", data[i]);
    }
}


void
test_linked_list_reverse(linked_list_node_t *linked_list)
{
    puts("Before reversed");
    linked_list_reverse(&linked_list);
    puts("After reversed");
    linked_list_print(linked_list);
}


void
test_linked_list_remove(linked_list_node_t *linked_list)
{
    int value;
    bool status;
    static const int data[12] = {-2, 7, 4, -1, 7, 0, 999, 0, 1, 0, -1, 0};

    for (int i = 0; i < 12; ++i) {
        status = linked_list_remove(&linked_list, &value, data[i]);
        if (status == true)
            printf("Removed item on index %d on got value: %d\n", data[i], value);
        else
            printf("Removed item on index %d failed\n", data[i]);
        linked_list_print(linked_list);
    }
}


void
test_linked_list_sort(linked_list_node_t *linked_list)
{
    puts("Before sort");
    linked_list_print(linked_list);
    linked_list_sort(&linked_list);
    puts("After sort");
    linked_list_print(linked_list);
}


static void _test_power(linked_list_node_t *node) { node->cargo *= 2; }

void
test_linked_list_traverse(linked_list_node_t *linked_list)
{

    linked_list_traverse(linked_list, *_test_power);
}


void
linked_list_test()
{
    unsigned int length;
    linked_list_node_t *linked_list;

    linked_list = linked_list_new(21);

    test_linked_list_insert(&linked_list);

    length = linked_list_get_length(linked_list);
    printf("Length is %d\n", length);

    // test_linked_list_find(linked_list);
    // test_linked_list_count(linked_list);
    // test_linked_list_index(linked_list);
    // test_linked_list_reverse(linked_list);
    // test_linked_list_remove(linked_list);
    // test_linked_list_traverse(linked_list);
    test_linked_list_sort(linked_list);

    linked_list_destroy(&linked_list);
    puts("After destroy");
    linked_list_print(linked_list);
}

#endif // __LINKED_LIST_H__
