
#ifndef __COMBINATIONS_H__
#define __COMBINATIONS_H__

#include <string.h>

#include "math.h"


/*
    The number of permutations of n objects taken r at a time is
    nPr = n(n - 1)(n - 2) ... (n - r + 1) = n! / (n - r)!
 */
static unsigned int
getCountPermutations(const char *array, const unsigned int count) {
    const size_t array_len = strlen(array);

    if (count < 0) return -1;
    if (count > array_len) return 0;

    return factorial(array_len) / factorial(array_len - count);
}


/*
    The number of combinations of n objects taken r at a time is
    nCr = n(n - 1)(n - 2) ... (n - r + 1)/r! = n! / r!(n - r)!
 */
static unsigned int
getCountCombinations(const char *array, const unsigned int count) {
    const size_t array_len = strlen(array);

    if (count < 0) return -1;
    else if (count > array_len) return 0;
    else if (count == 0) return 1;

    return factorial(array_len) / (factorial(count) * factorial(array_len - count));
}


/*
    (count + size - 1)!
    --------------------
    count! * (size - 1)!
 */
static unsigned int
getCountCombinationsWithReplacement(const char *array, const unsigned int count) {

    const size_t array_len = strlen(array);

    if (count < 0) return -1;
    else if (count > array_len) return 0;
    else if (count == 0) return 1;

    return factorial(count + array_len - 1) / (factorial(count) * factorial(array_len - 1));
}



#endif // __COMBINATIONS_H__
