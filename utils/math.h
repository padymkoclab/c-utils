/*

 */


#ifndef __MATH_H__
#define __MATH_H__

#include <math.h>

#include "./numbers.h"
#include "./array.h"


static unsigned long int
factorial(const long int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    }
    return n * factorial(n - 1);
}


static unsigned long int
get_value_sequence_fibonacci(const unsigned int index) {
    if (index == 0 || index == 1) {
        return index;
    }
    return get_value_sequence_fibonacci(index - 1) + get_value_sequence_fibonacci(index - 2);
}

static int
fibonacci(unsigned long int *array, const int length) {
    if (length < 1) return -1;
    for (int i = 0; i < length; ++i) {
        array[i] = get_value_sequence_fibonacci(i);
    }
    return 0;
}


static bool
isArmstrongNumber(const unsigned int number) {
    size_t len = getLengthIntNumber(number);
    char *buffer;
    buffer = malloc(len * sizeof(char) + 1);

    sprintf(buffer, "%d", number);

    unsigned long int sum = 0, cube;

    for (int i = 0; i < len; ++i) {
        cube = (buffer[i] - '0') * (buffer[i] - '0') * (buffer[i] - '0');
        sum += cube;
    }

    free(buffer);

    return sum == number;
}


#endif // __MATH_H__
