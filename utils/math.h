/**
 * Math utils
 */


#ifndef __MATH_H__
#define __MATH_H__

#include <math.h>

#include "./numbers.h"
#include "./array.h"


static unsigned long int
factorial(const long int n)
{
    if (n == 1 || n == 0) {
        return 1;
    } else if (n < 0) {
        return -1;
    }
    return n * factorial(n - 1);
}


static unsigned long int
_get_value_sequence_fibonacci(const size_t index)
{
    if (index == 0 || index == 1) {
        return index;
    }
    return _get_value_sequence_fibonacci(index - 1) + _get_value_sequence_fibonacci(index - 2);
}

static int
fibonacci(unsigned long int *array, const size_t length)
{
    if (length < 1) return -1;
    for (int i = 0; i < length; ++i) {
        array[i] = _get_value_sequence_fibonacci(i);
    }
    return 0;
}


// Not implemented
static bool
is_prime_number(const int)
{
    return true;
}


static bool
is_armstrong_number(const size_t number)
{
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


static int
factors_number(const int number)
{

}


#endif // __MATH_H__
