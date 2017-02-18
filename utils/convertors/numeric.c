

#ifndef __NUMERIC_H__
#define __NUMERIC_H__


#include <math.h>
#include <errno.h>

#include "../str.h"
#include "../testing/unittest.h"


char *
numeric_arabic_to_roman()
{
    return 0;
}


long int
numeric_roman_to_arabic()
{
    return 0;
}


char *
numeric_arabic_to_vedic()
{
    return 0;
}


long int
numeric_bin_to_oct(long long int value)
{
    return 0;
}


long int
numeric_bin_to_dec(long long int value)
{
    return 0;
}


long int
numeric_bin_to_hex(long long int value)
{
    return 0;
}


// http://stackoverflow.com/questions/6373093/how-to-print-binary-number-via-printf
// http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
long long int
numeric_dec_to_bin(long int number)
{
    if (number == 0)
        return 0b0;

    int i = 1;
    long long int result = 0;

    while (number > 0) {
        result += (number % 2) * i;
        printf("%lld %d\n", result, i);
        number /= 2;
        i *= 10;
    }
    return result;
}


void
test_numeric_bin_to_dec()
{
    numeric_bin_to_dec(0b1010);
}


void
test_numeric_dec_to_bin()
{
    printf("%lld\n", numeric_dec_to_bin(9));
    // assertEquals(numeric_dec_to_bin(-1254512), -0b100110010010001110000);
    // assertEquals(numeric_dec_to_bin(-123657), -0b11110001100001001);
    // assertEquals(numeric_dec_to_bin(-78189), -0b10011000101101101);
    // assertEquals(numeric_dec_to_bin(-2322), -0b100100010010);
    // assertEquals(numeric_dec_to_bin(-111), -0b1101111);
    // assertEquals(numeric_dec_to_bin(-10), -0b1010);
    // assertEquals(numeric_dec_to_bin(-2), -0b10);
    // assertEquals(numeric_dec_to_bin(-1), -0b1);
    // assertEquals(numeric_dec_to_bin(0), 0b0);
    // assertEquals(numeric_dec_to_bin(1), 0b1);
    // assertEquals(numeric_dec_to_bin(2), 0b10);
    // assertEquals(numeric_dec_to_bin(10), 0b1010);
    // assertEquals(numeric_dec_to_bin(101), 0b1100101);
    // assertEquals(numeric_dec_to_bin(1215), 0b10010111111);
    // assertEquals(numeric_dec_to_bin(11254), 0b10101111110110);
    // assertEquals(numeric_dec_to_bin(128916), 0b11111011110010100);
    // assertEquals(numeric_dec_to_bin(1236647), 0b100101101111010100111);
}


void
test_numberic()
{
    test_numeric_dec_to_bin();
    test_numeric_bin_to_dec();
}


#endif // __NUMERIC_H__
