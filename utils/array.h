/* Copyright 2016 setivolkylany */

#ifndef ARRAY_H
#define ARRAY_H

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


#endif // ARRAY_H
