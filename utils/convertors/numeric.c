/**
 * Numerical conversations
 *
 * https://habrahabr.ru/post/124395/
 * http://www.zaurtl.ru/UkVT/UKVT6.html
 *
 */

#ifndef __NUMERIC_H__
#define __NUMERIC_H__


#include <math.h>
#include <errno.h>
#include <stdlib.h>

#include "../str.h"
#include "../number.h"
#include "../testing/unittest.h"


char *
numeric_arabic_to_roman(long int number)
{
    return 0;
}


long int
numeric_roman_to_arabic(char value[])
{
    return 0;
}


char *
numeric_arabic_to_vedic(long int number)
{
    return 0;
}


long long int
numeric_bin_to_dec(char value[])
{
    long int result = 0;
    size_t len = strlen(value);
    bool is_negative = false;

    if (str_startswith(value, "-") == true) {
        value = str_slice(value, 3, len);
        len -= 3;
        is_negative = true;
    } else {
        value = str_slice(value, 2, strlen(value));
        len -= 2;
    }

    for (int i = 0; i < len; ++i) {
        result += ((value[i] - '0') * pow(2, len - i - 1));
    }

    if (is_negative == true)
        result *= -1;

    return result;
}


char *
numeric_bin_to_oct(char value[])
{
    char *buffer, bin_value[5];
    bool is_negative = false;
    unsigned int rest, number, i;
    size_t len;

    if (str_startswith(value, "-") == true) {
        is_negative = true;
        value = str_slice(value, 3, strlen(value));
    } else
        value = str_slice(value, 2, strlen(value));


    len = strlen(value);
    rest = len % 3;

    buffer = malloc(sizeof(char) * 5);
    strcpy(buffer, "0o");



    if (rest == 2) {
        sprintf(bin_value, "0b00%d", value[0]);
        number = numeric_bin_to_dec(bin_value);

        // need itoa
        number_itoa(number);

        i = 1;
    } else if (rest == 1) {
        sprintf(bin_value, "0b0%d%d", value[0], value[1]);
        number = numeric_bin_to_dec(bin_value);
        i = 2;
    } else
        i = 0;

    len /= 3;
    for (; i < len; ++i) {
        sprintf(bin_value, "0b%d%d%d", value[0], value[1], value[2]);
        number = numeric_bin_to_dec(bin_value);
    }

    if (is_negative == false) {
        buffer = realloc(buffer, sizeof(char) * strlen(buffer) + 1);
        str_prepend(buffer, "-");
    }

    // puts(value);
    // puts(buffer);

    return buffer;
}


char *
numeric_bin_to_hex(char value[])
{
    return "";
}


char *
numeric_oct_to_bin(char value[])
{
    return "";
}


long long int
numeric_oct_to_dec(char value[])
{
    return 0;
}

char *
numeric_oct_to_hex(char value[])
{
    return "";
}


char *
numeric_dec_to_bin(long long int number)
{
    char *buffer, bit[2];
    long long unsigned int i = 1;
    bool is_negative = false;

    if (number == 0)
        return "0b0";
    else if (number < 0) {
        is_negative = true;
        number = llabs(number);
    }

    buffer = malloc(sizeof(char));

    while (number > 0) {
        buffer = realloc(buffer, sizeof(char) * i);
        sprintf(bit, "%d", (int)(number % 2));
        strcat(buffer, bit);
        number /= 2;
        ++i;
    }

    // reverse the string of bits in reversed order
    str_reverse(buffer);

    // prepend to the string of bits
    if (is_negative == true) {
        buffer = realloc(buffer, sizeof(char) * (i + 3));
        str_prepend(buffer, "-0b");
    } else {
        buffer = realloc(buffer, sizeof(char) * (i + 2));
        str_prepend(buffer, "0b");
    }

    return buffer;
}


char *
numeric_dec_to_oct(long long int number)
{
    return "";
}


char *
numeric_dec_to_hex(long long int number)
{
    return "";
}


char *
numeric_hex_to_bin(char value[])
{
    return "";
}


char *
numeric_hex_to_oct(char value[])
{
    return "";
}


long long int
numeric_hex_to_dec(char value[])
{
    return 0;
}



/**
 * Tests
 */

void
test_numeric_bin_to_oct()
{
    assertStringEquals(numeric_bin_to_oct("-0b110110001000101011001000111000110"), "-0o66105310706");
    assertStringEquals(numeric_bin_to_oct("-0b110000111110101000001100111111"), "-0o6076501477");
    assertStringEquals(numeric_bin_to_oct("-0b11011000101101000110001110"), "-0o330550616");
    // assertStringEquals(numeric_bin_to_oct("-0b10110101011101011011010"), "-0o26535332");
    // assertStringEquals(numeric_bin_to_oct("-0b1011111111101111011"), "-0o1377573");
    // assertStringEquals(numeric_bin_to_oct("-0b10110001100010000"), "-0o261420");
    // assertStringEquals(numeric_bin_to_oct("-0b1101111011101"), "-0o15735");
    // assertStringEquals(numeric_bin_to_oct("-0b1101000"), "-0o150");
    // assertStringEquals(numeric_bin_to_oct("-0b110010"), "-0o62");
    // assertStringEquals(numeric_bin_to_oct("-0b1000"), "-0o10");
    // assertStringEquals(numeric_bin_to_oct("0b0"), "0o0");
    // assertStringEquals(numeric_bin_to_oct("0b1"), "0o1");
    // assertStringEquals(numeric_bin_to_oct("0b1010001"), "0o121");
    // assertStringEquals(numeric_bin_to_oct("0b111000011"), "0o703");
    // assertStringEquals(numeric_bin_to_oct("0b1100101110101"), "0o14565");
    // assertStringEquals(numeric_bin_to_oct("0b1001001101100001"), "0o111541");
    // assertStringEquals(numeric_bin_to_oct("0b1101000010000110011"), "0o1502063");
    // assertStringEquals(numeric_bin_to_oct("0b11010110001100111010001"), "0o32614721");
    assertStringEquals(numeric_bin_to_oct("0b10111010011100000100000"), "0o27234040");
    assertStringEquals(numeric_bin_to_oct("0b10101100010011010101100100"), "0o254232544");
}


void
test_numeric_bin_to_dec()
{
    assertEquals(numeric_bin_to_dec("-0b1010011000101101001011101010111011010"), -89215325658);
    assertEquals(numeric_bin_to_dec("-0b10001011110011000111010101110010"), -2345432434);
    assertEquals(numeric_bin_to_dec("-0b10100011001111011111100001010"), -342343434);
    assertEquals(numeric_bin_to_dec("-0b1111011101110100010100111"), -32434343);
    assertEquals(numeric_bin_to_dec("-0b1010000010100110111011"), -2632123);
    assertEquals(numeric_bin_to_dec("-0b111001001101100111"), -234343);
    assertEquals(numeric_bin_to_dec("-0b10011010000110111"), -78903);
    assertEquals(numeric_bin_to_dec("-0b10001011000110"), -8902);
    assertEquals(numeric_bin_to_dec("-0b11101001"), -233);
    assertEquals(numeric_bin_to_dec("-0b1001110"), -78);
    assertEquals(numeric_bin_to_dec("-0b1"), -1);
    assertEquals(numeric_bin_to_dec("-0b0"), 0);
    assertEquals(numeric_bin_to_dec("0b1010"), 10);
    assertEquals(numeric_bin_to_dec("0b1100001100"), 780);
    assertEquals(numeric_bin_to_dec("0b10111000001"), 1473);
    assertEquals(numeric_bin_to_dec("0b1100000011101001"), 49385);
    assertEquals(numeric_bin_to_dec("0b1001011100100000101"), 309509);
    assertEquals(numeric_bin_to_dec("0b1011010110110011010001"), 2976977);
    assertEquals(numeric_bin_to_dec("0b100100110010111100011001001"), 77166793);
    assertEquals(numeric_bin_to_dec("0b10000110010010101011010100110"), 281630374);
    assertEquals(numeric_bin_to_dec("0b1010000000010010011001011100110"), 1342780134);
    assertEquals(numeric_bin_to_dec("0b101111000011000111011110111101111110"), 50518159230);
    assertEquals(numeric_bin_to_dec("0b11010101011011001011101110011111011000"), 229163067352);
    assertEquals(numeric_bin_to_dec("0b10001101111101011100001100001001111101101110"), 9755417419630);
    assertEquals(numeric_bin_to_dec("0b1100001101001100100101100010111111001101011000"), 53683426161496);
}


void
test_numeric_bin_to_hex()
{
    assertStringEquals(numeric_bin_to_hex("-0b110001111110101101001001000100101"), "-0x18fd69225");
    assertStringEquals(numeric_bin_to_hex("-0b100000110100110101100001010010"), "-0x20d35852");
    assertStringEquals(numeric_bin_to_hex("-0b100110111100101100001101001"), "-0x4de5869");
    assertStringEquals(numeric_bin_to_hex("-0b111010000111110001001"), "-0x1d0f89");
    assertStringEquals(numeric_bin_to_hex("-0b10010010011111101101"), "-0x927ed");
    assertStringEquals(numeric_bin_to_hex("-0b1111100111000000"), "-0xf9c0");
    assertStringEquals(numeric_bin_to_hex("-0b1100100111001"), "-0x1939");
    assertStringEquals(numeric_bin_to_hex("-0b11110010"), "-0xf2");
    assertStringEquals(numeric_bin_to_hex("-0b1011010"), "-0x5a");
    assertStringEquals(numeric_bin_to_hex("-0b110"), "-0x6");
    assertStringEquals(numeric_bin_to_hex("0b0"), "0x0");
    assertStringEquals(numeric_bin_to_hex("0b1110"), "0xe");
    assertStringEquals(numeric_bin_to_hex("0b1001000"), "0x48");
    assertStringEquals(numeric_bin_to_hex("0b1110110100"), "0x3b4");
    assertStringEquals(numeric_bin_to_hex("0b1010011010"), "0x29a");
    assertStringEquals(numeric_bin_to_hex("0b10110011100011"), "0x2ce3");
    assertStringEquals(numeric_bin_to_hex("0b11001010110011111010"), "0xcacfa");
    assertStringEquals(numeric_bin_to_hex("0b11011111000000111111001"), "0x6f81f9");
    assertStringEquals(numeric_bin_to_hex("0b100001000001111000010110"), "0x841e16");
    assertStringEquals(numeric_bin_to_hex("0b10100101011111111110111000111"), "0x14affdc7");
}


void
test_numeric_oct_to_bin()
{
    assertStringEquals(numeric_oct_to_bin("-0o42357576203"), "-0b100010011101111101111110010000011");
    assertStringEquals(numeric_oct_to_bin("-0o1663344347"), "-0b1110110011011100100011100111");
    assertStringEquals(numeric_oct_to_bin("-0o532532274"), "-0b101011010101011010010111100");
    assertStringEquals(numeric_oct_to_bin("-0o17441436"), "-0b1111100100001100011110");
    assertStringEquals(numeric_oct_to_bin("-0o447032"), "-0b100100111000011010");
    assertStringEquals(numeric_oct_to_bin("-0o40745"), "-0b100000111100101");
    assertStringEquals(numeric_oct_to_bin("-0o21463"), "-0b10001100110011");
    assertStringEquals(numeric_oct_to_bin("-0o676"), "-0b110111110");
    assertStringEquals(numeric_oct_to_bin("-0o123"), "-0b1010011");
    assertStringEquals(numeric_oct_to_bin("-0o4"), "-0b100");
    assertStringEquals(numeric_oct_to_bin("0o0"), "0b0");
    assertStringEquals(numeric_oct_to_bin("0o4"), "0b100");
    assertStringEquals(numeric_oct_to_bin("0o24"), "0b10100");
    assertStringEquals(numeric_oct_to_bin("0o1101"), "0b1001000001");
    assertStringEquals(numeric_oct_to_bin("0o3024"), "0b11000010100");
    assertStringEquals(numeric_oct_to_bin("0o27256"), "0b10111010101110");
    assertStringEquals(numeric_oct_to_bin("0o2375522"), "0b10011111101101010010");
    assertStringEquals(numeric_oct_to_bin("0o37245430"), "0b11111010100101100011000");
    assertStringEquals(numeric_oct_to_bin("0o527246151"), "0b101010111010100110001101001");
    assertStringEquals(numeric_oct_to_bin("0o3542122625"), "0b11101100010001010010110010101");
}


void
test_numeric_oct_to_dec()
{
    assertEquals(numeric_oct_to_dec("-0o52177537210"), -5670616712);
    assertEquals(numeric_oct_to_dec("-0o6156170210"), -834203784);
    assertEquals(numeric_oct_to_dec("-0o123315440"), -21863200);
    assertEquals(numeric_oct_to_dec("-0o37246655"), -8211885);
    assertEquals(numeric_oct_to_dec("-0o1511272"), -430778);
    assertEquals(numeric_oct_to_dec("-0o203254"), -67244);
    assertEquals(numeric_oct_to_dec("-0o4453"), -2347);
    assertEquals(numeric_oct_to_dec("-0o100"), -64);
    assertEquals(numeric_oct_to_dec("-0o133"), -91);
    assertEquals(numeric_oct_to_dec("-0o10"), -8);
    assertEquals(numeric_oct_to_dec("0o0"), 0);
    assertEquals(numeric_oct_to_dec("0o10"), 8);
    assertEquals(numeric_oct_to_dec("0o101"), 65);
    assertEquals(numeric_oct_to_dec("0o203"), 131);
    assertEquals(numeric_oct_to_dec("0o1500"), 832);
    assertEquals(numeric_oct_to_dec("0o115750"), 39912);
    assertEquals(numeric_oct_to_dec("0o2774314"), 784588);
    assertEquals(numeric_oct_to_dec("0o22570312"), 4911306);
    assertEquals(numeric_oct_to_dec("0o26026415"), 5778701);
    assertEquals(numeric_oct_to_dec("0o6546257150"), 899243624);
}


void
test_numeric_oct_to_hex()
{
    assertStringEquals(numeric_oct_to_hex("-0o104146302313"), "-0x2219984cb");
    assertStringEquals(numeric_oct_to_hex("-0o2125705411"), "-0x11578b09");
    assertStringEquals(numeric_oct_to_hex("-0o35247006"), "-0x754e06");
    assertStringEquals(numeric_oct_to_hex("-0o5422727"), "-0x1625d7");
    assertStringEquals(numeric_oct_to_hex("-0o1171346"), "-0x4f2e6");
    assertStringEquals(numeric_oct_to_hex("-0o51673"), "-0x53bb");
    assertStringEquals(numeric_oct_to_hex("-0o1015"), "-0x20d");
    assertStringEquals(numeric_oct_to_hex("-0o616"), "-0x18e");
    assertStringEquals(numeric_oct_to_hex("-0o52"), "-0x2a");
    assertStringEquals(numeric_oct_to_hex("-0o1"), "-0x1");
    assertStringEquals(numeric_oct_to_hex("0o0"), "0x0");
    assertStringEquals(numeric_oct_to_hex("0o7"), "0x7");
    assertStringEquals(numeric_oct_to_hex("0o101"), "0x41");
    assertStringEquals(numeric_oct_to_hex("0o1370"), "0x2f8");
    assertStringEquals(numeric_oct_to_hex("0o22741"), "0x25e1");
    assertStringEquals(numeric_oct_to_hex("0o247574"), "0x14f7c");
    assertStringEquals(numeric_oct_to_hex("0o572723"), "0x2f5d3");
    assertStringEquals(numeric_oct_to_hex("0o3704514"), "0xf894c");
    assertStringEquals(numeric_oct_to_hex("0o116053441"), "0x1385721");
    assertStringEquals(numeric_oct_to_hex("0o4321020776"), "0x234421fe");
}


void
test_numeric_dec_to_bin()
{
    assertStringEquals(numeric_dec_to_bin(-1234556789), "-0b1001001100101011101011101110101");
    assertStringEquals(numeric_dec_to_bin(-123657), "-0b11110001100001001");
    assertStringEquals(numeric_dec_to_bin(-78189), "-0b10011000101101101");
    assertStringEquals(numeric_dec_to_bin(-2322), "-0b100100010010");
    assertStringEquals(numeric_dec_to_bin(-111), "-0b1101111");
    assertStringEquals(numeric_dec_to_bin(-10), "-0b1010");
    assertStringEquals(numeric_dec_to_bin(-1), "-0b1");
    assertStringEquals(numeric_dec_to_bin(0), "0b0");
    assertStringEquals(numeric_dec_to_bin(1), "0b1");
    assertStringEquals(numeric_dec_to_bin(10), "0b1010");
    assertStringEquals(numeric_dec_to_bin(101), "0b1100101");
    assertStringEquals(numeric_dec_to_bin(1215), "0b10010111111");
    assertStringEquals(numeric_dec_to_bin(11254), "0b10101111110110");
    assertStringEquals(numeric_dec_to_bin(128916), "0b11111011110010100");
    assertStringEquals(numeric_dec_to_bin(9999999999), "0b1001010100000010111110001111111111");
}


void
test_numeric_dec_to_oct()
{
    assertStringEquals(numeric_dec_to_oct(-4641356648), "-0o42451275550");
    assertStringEquals(numeric_dec_to_oct(-518396430), "-0o3671415016");
    assertStringEquals(numeric_dec_to_oct(-61016181), "-0o350604165");
    assertStringEquals(numeric_dec_to_oct(-9663045), "-0o44671105");
    assertStringEquals(numeric_dec_to_oct(-351271), "-0o1256047");
    assertStringEquals(numeric_dec_to_oct(-47064), "-0o133730");
    assertStringEquals(numeric_dec_to_oct(-2370), "-0o4502");
    assertStringEquals(numeric_dec_to_oct(-733), "-0o1335");
    assertStringEquals(numeric_dec_to_oct(-98), "-0o142");
    assertStringEquals(numeric_dec_to_oct(-6), "-0o6");
    assertStringEquals(numeric_dec_to_oct(0), "0o0");
    assertStringEquals(numeric_dec_to_oct(8), "0o10");
    assertStringEquals(numeric_dec_to_oct(60), "0o74");
    assertStringEquals(numeric_dec_to_oct(435), "0o663");
    assertStringEquals(numeric_dec_to_oct(4137), "0o10051");
    assertStringEquals(numeric_dec_to_oct(13254), "0o31706");
    assertStringEquals(numeric_dec_to_oct(857854), "0o3213376");
    assertStringEquals(numeric_dec_to_oct(9092310), "0o42536326");
    assertStringEquals(numeric_dec_to_oct(57597345), "0o333556641");
    assertStringEquals(numeric_dec_to_oct(260608603), "0o1742111133");
}

void
test_numeric_dec_to_hex()
{
    assertStringEquals(numeric_dec_to_hex(-1211334314), "-0x48337eaa");
    assertStringEquals(numeric_dec_to_hex(-675066595), "-0x283cb2e3");
    assertStringEquals(numeric_dec_to_hex(-67441572), "-0x40513a4");
    assertStringEquals(numeric_dec_to_hex(-5673277), "-0x56913d");
    assertStringEquals(numeric_dec_to_hex(-512854), "-0x7d356");
    assertStringEquals(numeric_dec_to_hex(-57740), "-0xe18c");
    assertStringEquals(numeric_dec_to_hex(-5614), "-0x15ee");
    assertStringEquals(numeric_dec_to_hex(-24), "-0x18");
    assertStringEquals(numeric_dec_to_hex(-37), "-0x25");
    assertStringEquals(numeric_dec_to_hex(-5), "-0x5");
    assertStringEquals(numeric_dec_to_hex(0), "0x0");
    assertStringEquals(numeric_dec_to_hex(1), "0x1");
    assertStringEquals(numeric_dec_to_hex(34), "0x22");
    assertStringEquals(numeric_dec_to_hex(214), "0xd6");
    assertStringEquals(numeric_dec_to_hex(3735), "0xe97");
    assertStringEquals(numeric_dec_to_hex(33699), "0x83a3");
    assertStringEquals(numeric_dec_to_hex(965878), "0xebcf6");
    assertStringEquals(numeric_dec_to_hex(2995704), "0x2db5f8");
    assertStringEquals(numeric_dec_to_hex(88834694), "0x54b8286");
    assertStringEquals(numeric_dec_to_hex(983093295), "0x3a98d02f");
}


void
test_numeric_hex_to_bin()
{
    assertStringEquals(numeric_hex_to_bin("-0x16874cf1f"), "-0b101101000011101001100111100011111");
    assertStringEquals(numeric_hex_to_bin("-0x1878b2b"), "-0b1100001111000101100101011");
    assertStringEquals(numeric_hex_to_bin("-0x575098"), "-0b10101110101000010011000");
    assertStringEquals(numeric_hex_to_bin("-0x118994"), "-0b100011000100110010100");
    assertStringEquals(numeric_hex_to_bin("-0xe9573"), "-0b11101001010101110011");
    assertStringEquals(numeric_hex_to_bin("-0x15d21"), "-0b10101110100100001");
    assertStringEquals(numeric_hex_to_bin("-0x21d3"), "-0b10000111010011");
    assertStringEquals(numeric_hex_to_bin("-0x22c"), "-0b1000101100");
    assertStringEquals(numeric_hex_to_bin("-0x46"), "-0b1000110");
    assertStringEquals(numeric_hex_to_bin("-0x2"), "-0b10");
    assertStringEquals(numeric_hex_to_bin("0x0"), "0b0");
    assertStringEquals(numeric_hex_to_bin("0x8"), "0b1000");
    assertStringEquals(numeric_hex_to_bin("0x1d"), "0b11101");
    assertStringEquals(numeric_hex_to_bin("0x1e2"), "0b111100010");
    assertStringEquals(numeric_hex_to_bin("0x1865"), "0b1100001100101");
    assertStringEquals(numeric_hex_to_bin("0x1721b"), "0b10111001000011011");
    assertStringEquals(numeric_hex_to_bin("0x4fbd7"), "0b1001111101111010111");
    assertStringEquals(numeric_hex_to_bin("0x776e95"), "0b11101110110111010010101");
    assertStringEquals(numeric_hex_to_bin("0x66ca5c"), "0b11001101100101001011100");
    assertStringEquals(numeric_hex_to_bin("0x2a058991"), "0b101010000001011000100110010001");
}


void
test_numeric_hex_to_oct()
{
    assertStringEquals(numeric_hex_to_oct("-0xce8c5b92"), "-0o31643055622");
    assertStringEquals(numeric_hex_to_oct("-0x9a5552"), "-0o46452522");
    assertStringEquals(numeric_hex_to_oct("-0x31a86db"), "-0o306503333");
    assertStringEquals(numeric_hex_to_oct("-0x75e8e7"), "-0o35364347");
    assertStringEquals(numeric_hex_to_oct("-0xe2b8b"), "-0o3425613");
    assertStringEquals(numeric_hex_to_oct("-0x7350"), "-0o71520");
    assertStringEquals(numeric_hex_to_oct("-0x1629"), "-0o13051");
    assertStringEquals(numeric_hex_to_oct("-0x13c"), "-0o474");
    assertStringEquals(numeric_hex_to_oct("-0x2a"), "-0o52");
    assertStringEquals(numeric_hex_to_oct("-0x9"), "-0o11");
    assertStringEquals(numeric_hex_to_oct("0x0"), "0o0");
    assertStringEquals(numeric_hex_to_oct("0x8"), "0o10");
    assertStringEquals(numeric_hex_to_oct("0x33"), "0o63");
    assertStringEquals(numeric_hex_to_oct("0x2b1"), "0o1261");
    assertStringEquals(numeric_hex_to_oct("0x756"), "0o3526");
    assertStringEquals(numeric_hex_to_oct("0x7f54"), "0o77524");
    assertStringEquals(numeric_hex_to_oct("0xd3a6b"), "0o3235153");
    assertStringEquals(numeric_hex_to_oct("0x3f2a24"), "0o17625044");
    assertStringEquals(numeric_hex_to_oct("0x8b234a"), "0o42621512");
    assertStringEquals(numeric_hex_to_oct("0x3a2617de"), "0o7211413736");
}


void
test_numeric_hex_to_dec()
{
    assertEquals(numeric_hex_to_dec("-0xa8830a52"), -2827160146);
    assertEquals(numeric_hex_to_dec("-0x16d3704"), -23934724);
    assertEquals(numeric_hex_to_dec("-0x4bb2908"), -79374600);
    assertEquals(numeric_hex_to_dec("-0x2ee8ce"), -3074254);
    assertEquals(numeric_hex_to_dec("-0xea9c0"), -960960);
    assertEquals(numeric_hex_to_dec("-0xa9fa"), -43514);
    assertEquals(numeric_hex_to_dec("-0x20f"), -527);
    assertEquals(numeric_hex_to_dec("-0x3d1"), -977);
    assertEquals(numeric_hex_to_dec("-0x15"), -21);
    assertEquals(numeric_hex_to_dec("-0x5"), -5);
    assertEquals(numeric_hex_to_dec("0x0"), 0);
    assertEquals(numeric_hex_to_dec("0x9"), 9);
    assertEquals(numeric_hex_to_dec("0x44"), 68);
    assertEquals(numeric_hex_to_dec("0xa9"), 169);
    assertEquals(numeric_hex_to_dec("0x21ae"), 8622);
    assertEquals(numeric_hex_to_dec("0xaff"), 2815);
    assertEquals(numeric_hex_to_dec("0x7bee7"), 507623);
    assertEquals(numeric_hex_to_dec("0x4bb6f1"), 4962033);
    assertEquals(numeric_hex_to_dec("0x4f39532"), 83072306);
    assertEquals(numeric_hex_to_dec("0x29248223"), 690258467);
}


void
test_numberic()
{
    test_numeric_bin_to_dec();
    test_numeric_bin_to_oct();
    test_numeric_dec_to_bin();
    // test_numeric_dec_to_oct();
}


#endif // __NUMERIC_H__
