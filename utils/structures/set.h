/**
 * Implementation set
 */


#include <stdio.h>
#include <stdbool.h>


#ifndef __SET_H__
#define __SET_H__


typedef struct _Set {

    int *array;
    size_t length;

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

} Set;


#endif // __SET_H__
