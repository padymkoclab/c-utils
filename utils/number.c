
#ifndef __NUMBER_H__
#define __NUMBER_H__

#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "./testing/unittest.h"


unsigned long int
number_length_int(long long int number)
{
    if (number < 0)
        number = llabs(number);
    else if (number == 0)
        return 1;
    return floor(log10(number)) + 1;
}


// Not implemented, not possible keep precise fractional
//
// http://www.geeksforgeeks.org/convert-floating-point-number-string/
// http://stackoverflow.com/questions/5459437/given-a-double-need-to-find-how-many-digits-in-total
// http://stackoverflow.com/questions/7228438/convert-double-float-to-string
// http://git.musl-libc.org/cgit/musl/blob/src/stdio/vfprintf.c?h=v1.1.6
unsigned long int
number_length_float(const double number)
{
    char buffer[200];
    sprintf(buffer, "%g", number);
    // printf("%li %s\n", strlen(buffer), buffer);
    return 0;
}


char *
number_itoa(long long int number)
{
    unsigned int len;

    if (number < 0) {
        len = number_length_int(number) + 1;
    } else if (number == 0)
        len = 1;
    else
        len = number_length_int(number);

    char *buffer = calloc(len, sizeof(char));
    sprintf(buffer, "%lli", number);
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
test_number_length_float()
{
    number_length_float(-8401877284.049988);
    number_length_float(-394382923.841476);
    number_length_float(-78309923.410416);
    number_length_float(-7984400.391579);
    number_length_float(-911647.379398);
    number_length_float(-19755.136967);
    number_length_float(-3352.227509);
    number_length_float(-768.229604);
    number_length_float(-27.777472);
    number_length_float(-5.539700);
    number_length_float(-1.1121212312412312);
    number_length_float(-0.01);
    number_length_float(0);
    number_length_float(0.01);
    number_length_float(.1);
    number_length_float(.12);
    number_length_float(.1212);
    number_length_float(.121243);
    number_length_float(0.477397);
    number_length_float(6.288709);
    number_length_float(36.478448);
    number_length_float(513.400912);
    number_length_float(9522.297382);
    number_length_float(91619.509459);
    number_length_float(635711.729527);
    number_length_float(7172969.579697);
    number_length_float(14160256.087780);
    number_length_float(606968879.699707);
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
test_number()
{
    test_number_length_int();
    test_number_length_float();
    test_number_itoa();
}


#endif //__NUMBER_H__
