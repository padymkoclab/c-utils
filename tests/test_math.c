
#include "../utils/tests.h"

#include "../utils/math.h"


static void
test_factorial() {
    assertEqual(factorial(-3), -1);
    assertEqual(factorial(-2), -1);
    assertEqual(factorial(-1), -1);
    assertEqual(factorial(0), 1);
    assertEqual(factorial(1), 1);
    assertEqual(factorial(2), 2);
    assertEqual(factorial(3), 6);
    assertEqual(factorial(4), 24);
    assertEqual(factorial(5), 120);
    assertEqual(factorial(6), 720);
    assertEqual(factorial(7), 5040);
    assertEqual(factorial(8), 40320);
    assertEqual(factorial(9), 362880);
    assertEqual(factorial(10), 3628800);
}


static void
test_fibonacci() {

    unsigned long int *array = calloc(0, sizeof(unsigned long int));

    assertEqual(fibonacci(array, 0), -1);

    array = realloc(array, sizeof(unsigned long int) * 1);
    assertEqual(fibonacci(array, 1), 0);
    assertEqual(array[0], 0);

    array = realloc(array, sizeof(unsigned long int) * 2);
    assertEqual(fibonacci(array, 2), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);

    array = realloc(array, sizeof(unsigned long int) * 3);
    assertEqual(fibonacci(array, 3), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);

    array = realloc(array, sizeof(unsigned long int) * 4);
    assertEqual(fibonacci(array, 4), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);

    array = realloc(array, sizeof(unsigned long int) * 5);
    assertEqual(fibonacci(array, 5), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);

    array = realloc(array, sizeof(unsigned long int) * 6);
    assertEqual(fibonacci(array, 6), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);

    array = realloc(array, sizeof(unsigned long int) * 7);
    assertEqual(fibonacci(array, 7), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);

    array = realloc(array, sizeof(unsigned long int) * 8);
    assertEqual(fibonacci(array, 8), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);

    array = realloc(array, sizeof(unsigned long int) * 9);
    assertEqual(fibonacci(array, 9), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);

    array = realloc(array, sizeof(unsigned long int) * 10);
    assertEqual(fibonacci(array, 10), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);

    array = realloc(array, sizeof(unsigned long int) * 11);
    assertEqual(fibonacci(array, 11), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);

    array = realloc(array, sizeof(unsigned long int) * 12);
    assertEqual(fibonacci(array, 12), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);

    array = realloc(array, sizeof(unsigned long int) * 13);
    assertEqual(fibonacci(array, 13), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);

    array = realloc(array, sizeof(unsigned long int) * 14);
    assertEqual(fibonacci(array, 14), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);

    array = realloc(array, sizeof(unsigned long int) * 15);
    assertEqual(fibonacci(array, 15), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);

    array = realloc(array, sizeof(unsigned long int) * 16);
    assertEqual(fibonacci(array, 16), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);
    assertEqual(array[15], 610);

    array = realloc(array, sizeof(unsigned long int) * 17);
    assertEqual(fibonacci(array, 17), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);
    assertEqual(array[15], 610);
    assertEqual(array[16], 987);

    array = realloc(array, sizeof(unsigned long int) * 18);
    assertEqual(fibonacci(array, 18), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);
    assertEqual(array[15], 610);
    assertEqual(array[16], 987);
    assertEqual(array[17], 1597);

    array = realloc(array, sizeof(unsigned long int) * 19);
    assertEqual(fibonacci(array, 19), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);
    assertEqual(array[15], 610);
    assertEqual(array[16], 987);
    assertEqual(array[17], 1597);
    assertEqual(array[18], 2584);

    array = realloc(array, sizeof(unsigned long int) * 20);
    assertEqual(fibonacci(array, 20), 0);
    assertEqual(array[0], 0);
    assertEqual(array[1], 1);
    assertEqual(array[2], 1);
    assertEqual(array[3], 2);
    assertEqual(array[4], 3);
    assertEqual(array[5], 5);
    assertEqual(array[6], 8);
    assertEqual(array[7], 13);
    assertEqual(array[8], 21);
    assertEqual(array[9], 34);
    assertEqual(array[10], 55);
    assertEqual(array[11], 89);
    assertEqual(array[12], 144);
    assertEqual(array[13], 233);
    assertEqual(array[14], 377);
    assertEqual(array[15], 610);
    assertEqual(array[16], 987);
    assertEqual(array[17], 1597);
    assertEqual(array[18], 2584);
    assertEqual(array[19], 4181);

    free(array);
}


static void
test_isArmstrongNumber() {
    for (int i = -10000; i < 10000; ++i) {
        if (i == 0 || i == 1 || i == 153 || i == 370 || i == 371 || i == 407) {
            assertTrue(isArmstrongNumber(i));;
        } else {
            assertFalse(isArmstrongNumber(i));;
        }
    }
}



int main (int argv, char **argc)
{
    test_factorial();
    test_fibonacci();
    test_isArmstrongNumber();
    return 0;
}
