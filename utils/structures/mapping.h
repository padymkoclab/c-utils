/**
 * Implementation ditionary (key-value storage)
 */

// http://www.cprogramming.com/tutorial/stl/stlmap.html
// http://stackoverflow.com/questions/2884068/what-is-the-difference-between-a-map-and-a-dictionary
// http://stackoverflow.com/questions/4551677/dictionary-map-key-value-pairs-data-structure-in-c
// https://gist.github.com/kgabis/3141664
// http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
// http://codereview.stackexchange.com/questions/63427/simple-key-value-store-in-c

#include <stdio.h>
#include <stdbool.h>


#ifndef __MAPPING_H__
#define __MAPPING_H__


typedef struct _keyvalue {
    char *key;
    int value;
} key_value_t;


typedef struct _Mapping {
    key_value_t *items;
} mapping_t;


int
mapping_add()
{
    return 0;
}


int
mapping_length()
{
    return 0;
}


int
mapping_get()
{
    return 0;
}


int
mapping_set()
{
    return 0;
}


int
mapping_del()
{
    return 0;
}


int
mapping_has()
{
    return 0;
}


int
mapping_print()
{
    return 0;
}


int
mapping_clear()
{
    return 0;
}


void
test_mapping()
{

}


#endif // __MAPPING_H__
