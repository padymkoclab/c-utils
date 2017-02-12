/**
 * Implementation a queue
 *
 * Queue is a collection of objects that are added and removed based on the first-in first-out (FIFO) principle.
 * It means that the first element added to the queue will be first one to be removed from the queue.
 *
 */


#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define QUEUE_ERROR "QueueError"
#define QUEUE_ERROR_IS_EMPTY "Queue is empty."
#define QUEUE_ERROR_IS_FULL "Queue is full."
#define QUEUE_ERROR_CREATION "Can`t create a queue."
#define QUEUE_ERROR_UNCORRECT_SIZE "Queue`s size must be at least 1."
#define QUEUE_ERROR_WAS_DESTROYED "Nothing to print, since a queue was destroyed."


typedef struct _queue {
    int *array;
    unsigned int size;
    unsigned int max_size;
} queue_t;


queue_t *
queue_new(unsigned int size) {

    queue_t *queue;

    if (size < 1) {
        fprintf(stderr, "%s: %s\n", QUEUE_ERROR, QUEUE_ERROR_UNCORRECT_SIZE);
        return NULL;
    }

    queue = (queue_t *)malloc(sizeof(queue_t));

    if (!queue) {
        fprintf(stderr, "%s: %s\n", QUEUE_ERROR, QUEUE_ERROR_CREATION);
        return NULL;
    }

    queue->array = (int *)malloc(sizeof(int) * size);
    queue->size = 0;
    queue->max_size = size;

    return queue;
}


void
queue_destroy(queue_t **queue) {
    memset((*queue)->array, 0, sizeof(int) * (*queue)->max_size);
    free((*queue)->array);
    free(*queue);
    *queue = NULL;
}


bool
queue_is_empty(queue_t *queue)
{

    return (queue->size == 0) ? true : false;
}


bool
queue_is_full(queue_t *queue)
{

    return (queue->max_size == queue->size) ? true : false;
}


bool
queue_enqueue(queue_t *queue, const int value)
{
    if (queue_is_full(queue) == true) {
        fprintf(stderr, "%s: %s\n", QUEUE_ERROR, QUEUE_ERROR_IS_FULL);
        return false;
    }

    queue->array[queue->size] = value;
    queue->size += 1;

    return true;
}


bool
queue_dequeue(queue_t *queue, int *value)
{
    if (queue_is_empty(queue) == true) {
        fprintf(stderr, "%s: %s\n", QUEUE_ERROR, QUEUE_ERROR_IS_EMPTY);
        return false;
    }

    *value = queue->array[0];
    queue->array[0] = 0;
    queue->size -= 1;

    return 0;
}


void
queue_print(queue_t *queue)
{
    if (queue != NULL) {
        if (queue_is_empty(queue) == true)
            puts("[]");
        else {
            putchar('[');
            for (int i = 0; i < queue->size; ++i) {
                printf("%d", queue->array[i]);
                if (i != queue->size - 1)
                    printf(", ");
            }
            puts("]");
        }
    } else
        fprintf(stderr, "%s: %s\n", QUEUE_ERROR, QUEUE_ERROR_WAS_DESTROYED);
}


void
queue_clear(queue_t *queue)
{
    queue->size = 0;
    memset(queue->array, 0, sizeof(int) * queue->max_size);
}


bool
queue_get_tail(queue_t *queue, int *value)
{
    if (queue_is_empty(queue) == true)
        return false;
    *value = queue->array[queue->size - 1];
    return true;
}


bool
queue_get_head(queue_t *queue, int *value)
{
    if (queue_is_empty(queue) == true)
        return false;
    *value = queue->array[0];
    return true;
}


void
queue_test()
{
    int value;
    bool status;
    queue_t *queue;

    queue = queue_new(10);
    queue_print(queue);

    queue_enqueue(queue, -5);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, -3);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 3);

    puts("Before clear");
    queue_print(queue);
    queue_clear(queue);
    puts("After clear");
    queue_print(queue);

    queue_enqueue(queue, -5);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, -3);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 3);

    status = queue_get_head(queue, &value);
    if (status == true)
        printf("Head is %d\n", value);
    else
        puts("Unknown head");

    status = queue_get_tail(queue, &value);
    if (status == true)
        printf("Tail is %d\n", value);
    else
        puts("Unknown tail");

    queue_dequeue(queue, &value);
    queue_dequeue(queue, &value);
    queue_dequeue(queue, &value);
    queue_dequeue(queue, &value);
    queue_dequeue(queue, &value);
    queue_dequeue(queue, &value);

    queue_print(queue);

    queue_destroy(&queue);
    queue_print(queue);

}


#endif // __QUEUE_H__
