/*

 */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>


int sumIntArray(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}


float sumFloatArray(float array[], int length) {
    float sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}


#endif // __ARRAY_H__
