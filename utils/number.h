
#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "./testing/unittest.h"


unsigned long int
get_number_count_digits(long int number)
{
    if (number < 0)
        number = llabs(number);
    else if (number == 0)
        return 1;

    if (number < 999999999999997)
        return floor(log10(number)) + 1;

    unsigned long int count = 0;
    while (number > 0) {
        ++count;
        number /= 10;
    }
    return count;
}


int
number_get_digits(long int number, int **digits, unsigned int *len)
{
    number = labs(number);

    // termination count digits and size of a array as well as
    *len = get_number_count_digits(number);

    *digits = realloc(*digits, *len * sizeof(int));

    // fill up the array
    unsigned int index = 0;
    while (number > 0) {
        (*digits)[index] = (int)(number % 10);
        number /= 10;
        ++index;
    }

    // reverse the array
    unsigned long int i = 0, half_len = (*len / 2);
    int swap;
    while (i < half_len) {
        swap = (*digits)[i];
        (*digits)[i] = (*digits)[*len - i - 1];
        (*digits)[*len - i - 1] = swap;
         ++i;
    }

    return 0;
}



char *
number_itoa(long long int number)
{
    unsigned int len;

    if (number < 0) {
        len = get_number_count_digits(number) + 1;
    } else if (number == 0)
        len = 1;
    else
        len = get_number_count_digits(number);

    char *buffer = calloc(len, sizeof(char));
    sprintf(buffer, "%lli", number);
    return buffer;
}


/**
 * Tests
 */


void
test_get_number_count_digits()
{
    assertEquals(get_number_count_digits(-9155555555555555555), 19);
    assertEquals(get_number_count_digits(-1000000000000000000), 19);
    assertEquals(get_number_count_digits(-999999999999999999), 18);
    assertEquals(get_number_count_digits(-100000000000000000), 18);
    assertEquals(get_number_count_digits(-99999999999999999), 17);
    assertEquals(get_number_count_digits(-10000000000000000), 17);
    assertEquals(get_number_count_digits(-9999999999999999), 16);
    assertEquals(get_number_count_digits(-1000000000000000), 16);
    assertEquals(get_number_count_digits(-999999999999999), 15);
    assertEquals(get_number_count_digits(-100000000000000), 15);
    assertEquals(get_number_count_digits(-99999999999999), 14);
    assertEquals(get_number_count_digits(-10000000000000), 14);
    assertEquals(get_number_count_digits(-9999999999999), 13);
    assertEquals(get_number_count_digits(-1000000000000), 13);
    assertEquals(get_number_count_digits(-999999999999), 12);
    assertEquals(get_number_count_digits(-100000000000), 12);
    assertEquals(get_number_count_digits(-99999999999), 11);
    assertEquals(get_number_count_digits(-10000000000), 11);
    assertEquals(get_number_count_digits(-9999999999), 10);
    assertEquals(get_number_count_digits(-1000000000), 10);
    assertEquals(get_number_count_digits(-999999999), 9);
    assertEquals(get_number_count_digits(-100000000), 9);
    assertEquals(get_number_count_digits(-99999999), 8);
    assertEquals(get_number_count_digits(-10000000), 8);
    assertEquals(get_number_count_digits(-9999999), 7);
    assertEquals(get_number_count_digits(-1000000), 7);
    assertEquals(get_number_count_digits(-999999), 6);
    assertEquals(get_number_count_digits(-100000), 6);
    assertEquals(get_number_count_digits(-99999), 5);
    assertEquals(get_number_count_digits(-10000), 5);
    assertEquals(get_number_count_digits(-9999), 4);
    assertEquals(get_number_count_digits(-1000), 4);
    assertEquals(get_number_count_digits(-999), 3);
    assertEquals(get_number_count_digits(-100), 3);
    assertEquals(get_number_count_digits(-99), 2);
    assertEquals(get_number_count_digits(-10), 2);
    assertEquals(get_number_count_digits(-9), 1);
    assertEquals(get_number_count_digits(-1), 1);
    assertEquals(get_number_count_digits(0), 1);
    assertEquals(get_number_count_digits(1), 1);
    assertEquals(get_number_count_digits(9), 1);
    assertEquals(get_number_count_digits(10), 2);
    assertEquals(get_number_count_digits(99), 2);
    assertEquals(get_number_count_digits(100), 3);
    assertEquals(get_number_count_digits(999), 3);
    assertEquals(get_number_count_digits(1000), 4);
    assertEquals(get_number_count_digits(9999), 4);
    assertEquals(get_number_count_digits(10000), 5);
    assertEquals(get_number_count_digits(99999), 5);
    assertEquals(get_number_count_digits(100000), 6);
    assertEquals(get_number_count_digits(999999), 6);
    assertEquals(get_number_count_digits(1000000), 7);
    assertEquals(get_number_count_digits(9999999), 7);
    assertEquals(get_number_count_digits(10000000), 8);
    assertEquals(get_number_count_digits(99999999), 8);
    assertEquals(get_number_count_digits(100000000), 9);
    assertEquals(get_number_count_digits(999999999), 9);
    assertEquals(get_number_count_digits(1000000000), 10);
    assertEquals(get_number_count_digits(9999999999), 10);
    assertEquals(get_number_count_digits(10000000000), 11);
    assertEquals(get_number_count_digits(99999999999), 11);
    assertEquals(get_number_count_digits(100000000000), 12);
    assertEquals(get_number_count_digits(999999999999), 12);
    assertEquals(get_number_count_digits(1000000000000), 13);
    assertEquals(get_number_count_digits(9999999999999), 13);
    assertEquals(get_number_count_digits(10000000000000), 14);
    assertEquals(get_number_count_digits(99999999999999), 14);
    assertEquals(get_number_count_digits(100000000000000), 15);
    assertEquals(get_number_count_digits(999999999999999), 15);
    assertEquals(get_number_count_digits(1000000000000000), 16);
    assertEquals(get_number_count_digits(9999999999999999), 16);
    assertEquals(get_number_count_digits(10000000000000000), 17);
    assertEquals(get_number_count_digits(99999999999999999), 17);
    assertEquals(get_number_count_digits(100000000000000000), 18);
    assertEquals(get_number_count_digits(999999999999999999), 18);
    assertEquals(get_number_count_digits(1000000000000000000), 19);
    assertEquals(get_number_count_digits(9155555555555555555), 19);
}


void
test_number_itoa()
{
    assertStringEquals(number_itoa(-68012292987), "-68012292987");
    assertStringEquals(number_itoa(-6801229291), "-6801229291");
    assertStringEquals(number_itoa(-680122929), "-680122929");
    assertStringEquals(number_itoa(-29414028), "-29414028");
    assertStringEquals(number_itoa(-85922833), "-85922833");
    assertStringEquals(number_itoa(-39093372), "-39093372");
    assertStringEquals(number_itoa(-2091571), "-2091571");
    assertStringEquals(number_itoa(-54760), "-54760");
    assertStringEquals(number_itoa(-20930), "-20930");
    assertStringEquals(number_itoa(-1382), "-1382");
    assertStringEquals(number_itoa(-40), "-40");
    assertStringEquals(number_itoa(-7), "-7");
    assertStringEquals(number_itoa(0), "0");
    assertStringEquals(number_itoa(6), "6");
    assertStringEquals(number_itoa(92), "92");
    assertStringEquals(number_itoa(1849), "1849");
    assertStringEquals(number_itoa(35976), "35976");
    assertStringEquals(number_itoa(192476), "192476");
    assertStringEquals(number_itoa(3548910), "3548910");
    assertStringEquals(number_itoa(20047706), "20047706");
    assertStringEquals(number_itoa(533285721), "533285721");
    assertStringEquals(number_itoa(4552202867), "4552202867");
    assertStringEquals(number_itoa(45522028672), "45522028672");
    assertStringEquals(number_itoa(455220286733), "455220286733");
}


void
test_number_get_digits()
{
    int *digits;
    unsigned int len;

    digits = malloc(sizeof(int));
    long int number = 1529587;
    number_get_digits(number, &digits, &len);

    // printf("%li", number);
    for (int i = len; i > 0; --i) {
        // printf();
    }

    free(digits);

}


void
test_number()
{
    test_get_number_count_digits();
    test_number_itoa();

    int *digits;
    unsigned int len;
    long int number = -1000000;

    digits = malloc(sizeof(int));

    number_get_digits(number, &digits, &len);

    printf("%ld --> [", number);
    for (int i = 0; i < len; ++i) {
        if (i == len - 1)
            printf("%d", digits[i]);
        else
            printf("%d, ", digits[i]);
    }
    printf("]\n");

    free(digits);

    // printf("%ld\n", get_number_count_digits(999999999999999));
}


#endif //__NUMBER_H__
