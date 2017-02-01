/**
 * Implementation linked list
 */


// https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
// http://www.thegeekstuff.com/2012/08/c-linked-list-example/

#include <stdio.h>
#include <stdlib.h>


typedef struct _LinkedListNode {
    int cargo;
    struct _LinkedListNode *next;
} linkedlist_node_t;


static linkedlist_node_t *
NewLinkedList(int cargo) {
    linkedlist_node_t *LinkedListHead = NULL;
    LinkedListHead = malloc(sizeof(linkedlist_node_t));
    (*LinkedListHead).cargo = cargo;
    (*LinkedListHead).next = NULL;
    return LinkedListHead;
}


static size_t
getLengthLinkedList(linkedlist_node_t *LinkedListHead) {

    if (LinkedListHead->next == NULL) return 1;

    linkedlist_node_t *current_node = LinkedListHead;

    size_t length = 0;
    while (current_node != NULL) {
        length += 1;
        current_node = current_node->next;
    }
    return length;
}


static void
printLinkedList(linkedlist_node_t *LinkedListHead) {
    printf("[");
    if (LinkedListHead->next != NULL) {
        linkedlist_node_t *current_node = LinkedListHead;
        while (current_node != NULL) {
            printf("%d", current_node->cargo);
            if (current_node->next != NULL) printf(", ");
            current_node = current_node->next;
        }
    } else {
        printf("%d", LinkedListHead->cargo);
    }
    printf("]\n");
}


static int
appendToLinkedList(linkedlist_node_t *LinkedListHead, int cargo) {
    linkedlist_node_t *current_node = LinkedListHead;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = malloc(sizeof(linkedlist_node_t));
    current_node->next->cargo = cargo;
    current_node->next->next = NULL;
    return 0;
}


static int
prependToLinkedList(linkedlist_node_t **LinkedListHead, int cargo) {
    linkedlist_node_t *new_node;
    new_node = (linkedlist_node_t*)malloc(sizeof(linkedlist_node_t));
    new_node->cargo = cargo;
    new_node->next = *LinkedListHead;
    (*LinkedListHead) = new_node;
    return 0;
}


static int
popFromEndLinkedList(linkedlist_node_t *LinkedListHead) {
    int value;
    if (LinkedListHead->next == NULL) {
        value = LinkedListHead->cargo;
        free(LinkedListHead);
        return value;
    }
    linkedlist_node_t *latest_node = LinkedListHead;
    while (latest_node->next->next != NULL) {
        latest_node = latest_node->next;
    }
    value = latest_node->next->cargo;
    free(latest_node->next);
    latest_node->next = NULL;
    return value;
}


int
popFromBeginLinkedList(linkedlist_node_t **LinkedListHead) {
    int value;
    if (*LinkedListHead == NULL) {
        return '\0';
    }
    linkedlist_node_t *next_node = NULL;
    next_node = (*LinkedListHead)->next;
    value = (*LinkedListHead)->cargo;
    free(*LinkedListHead);
    *LinkedListHead = next_node;
    return value;
}


int
isEmptyLinkedList(linkedlist_node_t *LinkedListHead) {
    return (*LinkedListHead).next == NULL;
}


int
findInLinkedList(linkedlist_node_t *LinkedListHead) {
    return 0;
}


int
indexOfLinkedList(linkedlist_node_t *LinkedListHead) {
    return -1;
}


void
sortLinkedList(linkedlist_node_t *LinkedListHead) {

}


void
reverseLinkedList(linkedlist_node_t *LinkedListHead) {

}


int
DestroyLinkedList(linkedlist_node_t *LinkedListHead) {
    linkedlist_node_t *current_node = LinkedListHead;
    while (current_node->next != NULL) {
        free(current_node);
        current_node = current_node->next;
    }
    return 0;
}
