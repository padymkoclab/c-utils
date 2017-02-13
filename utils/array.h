/**
 * Utils for working with single-dimention numeric arrayes
 */


#ifndef __ARRAY_H__
#define __ARRAY_H__


#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#include "func.h"


// for processing errors
extern int errno;


// determination size of an array (not from a pointer on this array)
#define SIZE_ARRAY(array) (sizeof(array) / sizeof(array[0]))

// a minimal value in an array
#define MIN_ARRAY(array, length, variable, status) \
{\
    if (length > 0) { \
        variable = array[0]; \
        for (int i = 1; i < length; ++i) \
            if (array[i] < variable) variable = array[i]; \
        status = 0; \
    } \
    else if (length == 0) status = 1; \
    else status = -1; \
}

// a maximal value in an array
#define MAX_ARRAY(array, length, variable, status) \
{\
    if (length > 0) { \
        variable = array[0]; \
        for (int i = 1; i < length; ++i) \
            if (array[i] > variable) variable = array[i]; \
        status = 0; \
    } \
    else if (length == 0) status = 1; \
    else status = -1; \
}

// determination sum of items of an array
// after processing variable status will be changed to:
// -1, 0, 1
#define SUM_ARRAY(array, length, variable, status) \
{\
    if (length > 0) \
        for (int i = 0; i < length; ++i) { \
            variable += array[i]; \
        status = 0; \
    } \
    else if (length == 0) status = 1; \
    else status = -1; \
}

// reverse an array of any numberic type in place
#define REVERSE_ARRAY(array, length, status) \
{ \
    if (length > 0) { \
        for (int i = 0; i < length / 2; ++i) { \
            SWAP(int, array[i], array[length - i - 1]); \
        } \
        *status = 0; \
    } \
    else if (length < 0) *status = -1; \
    else *status = 1; \
}


enum inter_direction_array
{
    LEFT_INTER_ARRAY  = 'l',
    RIGHT_INTER_ARRAY = 'r'
};


/*
    Fills an array of values in a passed range and with step.
    The step may be more or less 0.
    Return a non-zero value, if something went wrong.

    SIZE OF ARRAY IS A RESPONSIBILITY OF A PROGRAMMER.

    int arr1[10];
    range_int_array(arr1, 0, 10, 1);
    print_int_array(arr1, 10);

    int arr2[10];
    range_int_array(arr2, 0, -10, -1);
    print_int_array(arr2, 10);

    int arr3[4];
    range_int_array(arr3, 20, 10, -3);
    print_int_array(arr3, 4);

    int arr4[5];
    range_int_array(arr4, -20, -10, 2);
    print_int_array(arr4, 5);

    int arr5[5];
    range_int_array(arr5, -20, -10, -5);
    print_int_array(arr5, 5);

    int arr6[5];
    range_int_array(arr6, 20, 10, 5);
    print_int_array(arr6, 5);

    int arr7[5];
    int result = range_int_array(arr7, 20, 10, 0);
    if (result != 0) {
        puts("Raised error");
    }

 */
int
range_int_array(int array[], const int start, const int end, const int step) {

    int value;
    int index = 0;

    // the step must not be zero
    if (step == 0) {
        errno = EINVAL;
        perror("Step must be not zero");
        return -1;
    }

    if (step > 0) {
        for (value = start; value < end; value += step, ++index) {
            array[index] = value;

        }
    } else if (step < 0) {
        for (value = start; value > end; value += step, ++index) {
            array[index] = value;

        }
    }
    return 0;

}



/*
    #define CAT(a, b) #a #b

    Concatenate items of an integer array to string

    http://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr
    http://stackoverflow.com/questions/30931799/concatenate-char-array-and-int-array-and-store-in-string-array
    http://stackoverflow.com/questions/1597007/creating-c-macro-with-and-line-token-concatenation-with-positioning-macr
    http://stackoverflow.com/questions/4681325/join-or-implode-in-c
 */
int
join_array(char *str, const int array[], const size_t length) {

    int i;
    char *buffer;

    // WHAT IS
    buffer = calloc(10, sizeof(char));

    for (i = 0; i < length; ++i) {
        sprintf(buffer, "%d", array[i]);
        strcat(str, buffer);
    }
    free(buffer);
    return 0;
}


int
indef_of_array(const void *array, const size_t length, const int number, const char direction) {

    // for (int i = 0; i < length; ++i) {
    //     if (array[i] == number) return i;
    // }
    // for (int i = length; i > 0; --i) {
    //     if (array[i] == number) return i;
    // }
    return -1;
}


// Need rewrite for change object in-place
int
slice_array(int *array, int new_array[])
{
    return 0;
}


/*
    Returns mean value of all items in a integer array
 */
int
mean_array(int *array, size_t length)
{
    return 0;
}


/*
 */
int
sort_array(int *array, size_t length)
{
    return 0;
}


/*
 */
int
count_in_array(int *array, size_t length)
{
    return 0;
}


/*
 */
int
clear_array(int *array, size_t length)
{
    return 0;
}


/*
    http://stackoverflow.com/questions/8766258/alternative-to-multidimensional-array-in-c
 */
int
flatten_array()
{
    return 0;
}


int
pop_from_array() {
    return 0;
}


int
push_to_array() {
    return 0;
}


/*
    http://stackoverflow.com/questions/1696074/how-can-i-concatenate-two-arrays-in-c
 */
int
extend_array() {
    return 0;
}


#endif // __ARRAY_H__
