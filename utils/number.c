
#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "testing/unittest.h"


unsigned long int
number_length_int(const long int number)
{
    if (number == 0)
        return 1;
    return floor(log10(abs(number))) + 1;
}


// Not implemented
// http://stackoverflow.com/questions/5459437/given-a-double-need-to-find-how-many-digits-in-total
unsigned long int
number_get_length_float(const double number)
{
    char buffer[200];
    sprintf(buffer, "%g", number);

    return strlen(buffer);
}


// http://www.programmingsimplified.com/c/source-code/c-program-convert-decimal-to-binary
// http://stackoverflow.com/questions/6373093/how-to-print-binary-number-via-printf
// https://www.programiz.com/c-programming/examples/binary-decimal-convert
// http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
char *
number_dec_to_bin(int n)
{
    return NULL;
}


long int
number_bin_to_dec(char value[], int *number)
{
    return 0;
}


/**
 * Tests
 */


void
test_number_length_int()
{
    assertEquals(number_length_int(-10000000), 8);
    assertEquals(number_length_int(-1000000), 7);
    assertEquals(number_length_int(-100000), 6);
    assertEquals(number_length_int(-10000), 5);
    assertEquals(number_length_int(-1000), 4);
    assertEquals(number_length_int(-100), 3);
    assertEquals(number_length_int(-10), 2);
    assertEquals(number_length_int(-1), 1);
    assertEquals(number_length_int(0), 1);
    assertEquals(number_length_int(1), 1);
    assertEquals(number_length_int(10), 2);
    assertEquals(number_length_int(100), 3);
    assertEquals(number_length_int(1000), 4);
    assertEquals(number_length_int(10000), 5);
    assertEquals(number_length_int(100000), 6);
    assertEquals(number_length_int(1000000), 7);
    assertEquals(number_length_int(10000000), 8);
}


void
test_number_get_length_float()
{
    printf("%li\n", number_get_length_float(12.5448));
    printf("%li\n", number_get_length_float(0));
    printf("%li\n", number_get_length_float(0.01));
    printf("%li\n", number_get_length_float(.1));
    printf("%li\n", number_get_length_float(.12));
    printf("%li\n", number_get_length_float(.1212));
    printf("%li\n", number_get_length_float(.121243));
    printf("%li\n", number_get_length_float(23131.1121212312412312));
    printf("%li\n", number_get_length_float(11111111.23213412421));
    printf("%li\n", number_get_length_float(-1.1121212312412312));
}


void
test_number()
{
    test_number_length_int();
    test_number_get_length_float();
}


#endif //__NUMBER_H__
