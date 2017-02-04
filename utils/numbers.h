
#ifndef __NUMBERS_H__
#define __NUMBERS_H__

#include <stdlib.h>
#include <string.h>
#include <sttbool.h>


/*
    Return length integer if without considering sign
 */
size_t
getLengthIntNumber(const int number) {
    size_t length = 1;
    int copy_number = (number < 0) ? -number : number;
    while ((copy_number = copy_number / 10) > 0) {
        ++length;
    }
    return length;
}


/*
    NotImplemented
    http://stackoverflow.com/questions/5459437/given-a-double-need-to-find-how-many-digits-in-total
 */
size_t
getLengthFloatNumber(const float number) {
    size_t length = 1;
    int copy_number = (number < 0) ? -number : number;

    char *buffer;
    buffer = calloc(20, sizeof(char));
    sprintf(buffer, "%f", number);

    while ((copy_number = copy_number / 10) > 0) {
        ++length;
    }
    return length;
}


/**
 * Return converted decimal as binary
 * FIXME
 */
char *
decToBin(const int n) {

    int is_negative = 0;
    if (n == 0) return "0";
    else if (n < 0) {
        is_negative = 1;
        n = n * (-1);
    }


    int val;
    char *result = malloc(sizeof(char));
    char buffer[2];

    while (n > 0) {
        val = n % 2;
        sprintf(buffer, "%d",val);
        strcat(result, buffer);
        n /= 2;
    }

    for (int i = 0; i < strlen(result) / 2; ++i) {
        val = result[strlen(result) - i - 1];
        result[strlen(result) - i - 1] = result[i];
        result[i] = val;
    }

    if (is_negative == 1) {
        memmove(result + 1, result, strlen(result) + 1);
        result[0] = '-';
    }

    return result;
}


// Not Implemented
static int
binToDec(char value[], int *number) {

}


#endif //__NUMBERS_H__
