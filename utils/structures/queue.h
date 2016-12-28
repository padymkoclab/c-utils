/**
 * Implementation queue
 */


typedef struct _Queue {
    int *array;
    int (*isEmpty)();
    int (*size)();
    int (*clear)();
    int (*pop)();
    int (*push)();
}
