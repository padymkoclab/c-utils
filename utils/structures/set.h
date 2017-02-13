/**
 * Implementation a set
 *
 * http://stackoverflow.com/questions/2537681/how-to-implement-a-set
 * http://stackoverflow.com/questions/2630738/c-how-to-implement-set-data-structure
 * https://en.wikipedia.org/wiki/Set_(abstract_data_type)
 * Red-black tree
 * Hash table
 * http://stackoverflow.com/questions/29493668/simple-implementation-of-a-set-for-ints-in-c
 */


#include <stdio.h>
#include <stdbool.h>


#ifndef __SET_H__
#define __SET_H__


typedef struct _Set {
    int *array;
    size_t length;
} Set;


int (*pop) (struct _Set *this);
int (*in) (struct _Set *this, int value);
int (*print) (struct _Set *this);
int (*push) (struct _Set *this, int value);
int (*remove) (struct _Set *this, int value);
int (*clear) (struct _Set *this, int value);

int (*intersection) (struct _Set *this, struct _Set *set);
int (*difference) (struct _Set *this, struct _Set *set);
int (*union_) (struct _Set *this, struct _Set *set);
int (*symmetrical_difference) (struct _Set *this, struct _Set *set);


#endif // __SET_H__
