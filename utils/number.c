
#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "./testing/unittest.h"


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


char *
number_itoa(long long int number)
{
    unsigned int len = (number == 0) ? 1: log10(abs(number));
    char *buffer = calloc(len, sizeof(char));
    sprintf(buffer, "%lli", number);
    printf("%d %li\n", len, strlen(buffer));
    return buffer;
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
test_number_itoa()
{
    assertStringEquals(number_itoa(-68012292987), "-68012292987");
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
}


void
test_number()
{
    test_number_length_int();
    // test_number_get_length_float();
    test_number_itoa();
}


#endif //__NUMBER_H__
