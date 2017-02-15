/**
 * Utils for working with single-dimention numeric arrayes
 */


#ifndef __ARRAY_H__
#define __ARRAY_H__


#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef TESTING_DISPLAY_ALL
    #undef TESTING_DISPLAY_ALL
    #define TESTING_DISPLAY_ALL 1
#endif


#include "testing/unittest.h"
#include "func.h"
#include "pprint.h"


// determination size of an array (not from a pointer on this array)
#define array_size(array) (sizeof(array) / sizeof(array[0]))

// a minimal value in an array
#define array_min(array, length, variable) \
{\
    if (length > 0) { \
        variable = array[0]; \
        for (int i = 1; i < length; ++i) { \
            if (array[i] < variable) \
                variable = array[i]; \
        } \
    } \
}

// a maximal value in an array
#define array_max(array, length, variable) \
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
#define array_sum(array, length, variable) \
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
#define array_reverse(array, length) \
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


// reverse an array of any numberic type in place
#define array_shuffle(array, length)


#define array_range(type, array, length, start, end, step) \
{ \
    unsigned int index = 0; \
    for (type i = start; i < end; i += step) { \
        array[index] = i; \
        ++index; \
    } \
}


/*
    Fills an array of values in a passed range and with step.
    The step may be more or less 0.
    Return a non-zero value, if something went wrong.

    SIZE OF ARRAY IS A RESPONSIBILITY OF A PROGRAMMER.
 */
int
array_range_int(int array[], const int start, const int end, const int step)
{
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
array_join(char *str, const int array[], const size_t length)
{

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
array_index_of(const void *array, const size_t length, const int number, const char direction)
{

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
flattenarray()
{
    return 0;
}


int
array_remove() {
    return 0;
}


int
array_insert()
{
    return 0;
}


/*
    http://stackoverflow.com/questions/1696074/how-can-i-concatenate-two-arrays-in-c
 */
int
extend_array()
{
    return 0;
}


/**
 * Tests
 */


void
test_array_size()
{
    int array1[789];
    assertEquals(array_size(array1), 789);

    long int array2[0];
    assertEquals(array_size(array2), 0);

    float array3[1];
    assertEquals(array_size(array3), 1);

    double array4[1000000];
    assertEquals(array_size(array4), 1000000);
}


void
test_array_min()
{
    float value_f;
    int value_i;

    float array1[1] = {0.25};
    array_min(array1, 1, value_f)
    assertEquals(value_f, 0.25);

    float array2[5] = {0.954, -78.21, 0.25, 1, 0};
    array_min(array2, 5, value_f)
    assertEquals(value_f, -78.21);
    printf("%f\n", value_f);

    float array3[10] = {1, 89, -98.43, 0.954, -78.21, 0.25, 1, -98.43, 0, 0.954};
    array_min(array3, 10, value_f)
    assertEquals(value_f, -98.43);

    float array4[5] = {789.123, 789.122, 789.126, 789.125, 789.124};
    array_min(array4, 5, value_f)
    assertEquals(value_f, 789.122);

    int array5[5] = {189, 689, 789, 789, 124};
    array_min(array5, 5, value_i)
    assertEquals(value_i, 124);

    int array6[5] = {-78, -98, -14, -21, -124};
    array_min(array6, 5, value_i)
    assertEquals(value_i, -124);

    int array7[10] = {-189, -689, 789, -789, 124, 21, 78, 11, -98, 213};
    array_min(array7, 10, value_i)
    assertEquals(value_i, -789);

    int array8[1] = {689};
    array_min(array8, 1, value_i)
    assertEquals(value_i, 689);
}


void
test_array_max()
{

}


void
test_array_sum()
{

}


void
test_array_reverse()
{

}


void
test_array_shuffle()
{

}


void
test_array_range()
{
    int array1[10];
    array_range(int, array1, 10, 0, 10, 1);
    ARRAY_PRINT(array1, 10, "%d");

    float array2[10];
    array_range(float, array2, 10, -1, 1, 0.2);
    ARRAY_PRINT(array2, 10, "%f");

    double array3[10];
    array_range(double, array3, 10, 0.63, 2.9, 0.25);
    ARRAY_PRINT(array3, 10, "%g");

    // PRINT_TEST_ARRAY_FAIL("AA", "AA", 1, ">", array1, array2, 10);

}


void
test_array()
{
    test_array_size();
    test_array_min();
    test_array_max();
    test_array_sum();
    test_array_reverse();
    test_array_shuffle();
    // test_array_range();
}


#endif // __ARRAY_H__
