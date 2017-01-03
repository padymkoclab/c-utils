
#include "../utils/tests.h"

#include "../utils/numbers.h"


static void
test_decToBin() {
    assertStringEqual(decToBin(-23432412), "-1011001011000110011011100");
    assertStringEqual(decToBin(-1134245412), "-1000011100110110011011000100100");
    assertStringEqual(decToBin(-7813422), "-11101110011100100101110");
    assertStringEqual(decToBin(-7812), "-1111010000100");
    assertStringEqual(decToBin(-20), "-10100");
    assertStringEqual(decToBin(-19), "-10011");
    assertStringEqual(decToBin(-18), "-10010");
    assertStringEqual(decToBin(-17), "-10001");
    assertStringEqual(decToBin(-16), "-10000");
    assertStringEqual(decToBin(-15), "-1111");
    assertStringEqual(decToBin(-14), "-1110");
    assertStringEqual(decToBin(-13), "-1101");
    assertStringEqual(decToBin(-12), "-1100");
    assertStringEqual(decToBin(-11), "-1011");
    assertStringEqual(decToBin(-10), "-1010");
    assertStringEqual(decToBin(-9), "-1001");
    assertStringEqual(decToBin(-8), "-1000");
    assertStringEqual(decToBin(-7), "-111");
    assertStringEqual(decToBin(-6), "-110");
    assertStringEqual(decToBin(-5), "-101");
    assertStringEqual(decToBin(-4), "-100");
    assertStringEqual(decToBin(-3), "-11");
    assertStringEqual(decToBin(-2), "-10");
    assertStringEqual(decToBin(-1), "-1");
    assertStringEqual(decToBin(0), "0");
    assertStringEqual(decToBin(1), "1");
    assertStringEqual(decToBin(2), "10");
    assertStringEqual(decToBin(3), "11");
    assertStringEqual(decToBin(4), "100");
    assertStringEqual(decToBin(5), "101");
    assertStringEqual(decToBin(6), "110");
    assertStringEqual(decToBin(7), "111");
    assertStringEqual(decToBin(8), "1000");
    assertStringEqual(decToBin(9), "1001");
    assertStringEqual(decToBin(10), "1010");
    assertStringEqual(decToBin(11), "1011");
    assertStringEqual(decToBin(12), "1100");
    assertStringEqual(decToBin(13), "1101");
    assertStringEqual(decToBin(14), "1110");
    assertStringEqual(decToBin(15), "1111");
    assertStringEqual(decToBin(16), "10000");
    assertStringEqual(decToBin(17), "10001");
    assertStringEqual(decToBin(18), "10010");
    assertStringEqual(decToBin(19), "10011");
    assertStringEqual(decToBin(20), "10100");
    assertStringEqual(decToBin(7812), "1111010000100");
    assertStringEqual(decToBin(7813422), "11101110011100100101110");
    assertStringEqual(decToBin(1134245412), "1000011100110110011011000100100");
    assertStringEqual(decToBin(23432412), "1011001011000110011011100");
}


int main (int argv, char **argc)
{
    test_decToBin();
    return 0;
}
