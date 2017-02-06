/**
 * Utils for working with single-dimention numeric arrayes
 */


#ifndef __ARRAY_H__
#define __ARRAY_H__


#include <string.h>
#include <errno.h>

#include "func.h"


// return size of array (not from pointer on array)
#define SIZE_ARRAY(array) (sizeof(array) / sizeof(array[0]))

#define MIN_ARRAY(array, length)
#define MAX_ARRAY
#define IN_ARRAY

extern int errno;


/*
    Returns sum integer items in an array.

    int arr[4] = {1, -2, 3, -4};
    printf("Sum = %d\n", sum_int_array(arr, 4));
 */
static int
sum_int_array(const int array[], const size_t length) {

    int sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}


static int
sum_array(const void *array, const size_t length, void *sum) {

    if (length == 0) {
        errno = EINVAL;
        fprintf(stderr, "%s: Length must be more zero\n", strerror(errno));
        return -1;
    }
    void *c = (char*)89 + sizeof(int);
    memcpy(sum, &c, 10);
    // &sum = 32;

    // for (int i = 0; i < length; ++i) {
    //     sum += array[i];
    // }
    // return sum;
    return 0;
}


/*
    Reverse an integer array in place.

    int arr[4] = {1, -2, 3, -4};
    print_int_array(arr, 4);
    reverse_int_array(arr, 4);
    print_int_array(arr, 4);
 */
static int
reverse_int_array(int *array, const size_t length) {
    for (int i = 0; i < length / 2; ++i) {
        SWAP(int, array[i], array[length - i - 1]);
    }
    return 0;
}


/*
    Reverse an float array in place.

    float arrFloat[4] = {0.1, -2.12, 1.3, -4.2};
    print_float_array(arrFloat, 4);
    reverse_float_array(arrFloat, 4);
    print_float_array(arrFloat, 4);
 */
static int
reverse_float_array(float *array, const size_t length) {
    for (int i = 0; i < length / 2; ++i) {
        SWAP(float, array[i], array[length - i - 1]);
    }
    return 0;
}


/*
    Return max integer in an array.
 */
static int
max_int_array(const int *array, const size_t length) {

    if (length == 0) {
        errno = EINVAL;
        fprintf(stderr, "%s: Length must be more zero\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int max;
    for (int i = 0; i < length; ++i) {
        if (array[i] > max) max = array[i];
    }
    return max;
}


/*
    Return min integer in an array.
 */
static int
min_int_array(const int *array, const size_t length) {

    if (length == 0) {
        errno = EINVAL;
        fprintf(stderr, "%s: Length must be more zero\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int min;
    for (int i = 0; i < length; ++i) {
        if (array[i] < min) min = array[i];
    }
    return min;
}


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
static int
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
    Concatenate items of an integer array to string
 */
static int
joinIntArrayToString(char *str, const int *array, const unsigned int length) {

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


static unsigned int
indefOfLeftIntArray(int number, int *array, size_t length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == number) return i;
    }
    return -1;
}


static unsigned int
indefOfRightIntArray(int number, int *array, size_t length) {
    for (int i = length; i > 0; --i) {
        if (array[i] == number) return i;
    }
    return -1;
}


// Need rewrite for change object in-place
static int
sliceIntArray(int *array, int new_array[]) {
    return 0;
}


/*
    Returns mean value of all items in a integer array
 */
static int
meanIntArray(int *array, size_t length) {
    return 0;
}


/*
 */
static int
sortIntArray(int *array, size_t length) {
    return 0;
}


/*
 */
static int
countInIntArray(int *array, size_t length) {
    return 0;
}


/*
 */
static int
clearInIntArray(int *array, size_t length) {
    return 0;
}


#endif // __ARRAY_H__
