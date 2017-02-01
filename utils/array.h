/*

 */

#ifndef __ARRAY_H__
#define __ARRAY_H__


/*
    Return sum integer items in an array
 */
static int
sumIntArray(const int array[], const unsigned int length) {

    int sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum;
}


/*
    Reverse an integer array in place
 */
static int
reverseIntArray(const int *array, const unsigned int length) {

    int *copy_;

    copy_ = calloc(length, sizeof(int));
    copy_ = array;

    for (int i = 0; i < length; ++i) {
        array[i] = copy_[length - i - 1];
    }

    free(copy_);
    return 0;
}


/*
    Return max integer in an array
 */
static int
maxIntArray(const int *array, const unsigned int length) {

    int max;

    for (int i = 0; i < length; ++i) {
        if (array[i] > max) max = array[i];
    }
    return max;
}


/*
    Return min integer in an array
 */
static int
minIntArray(const int *array, const unsigned int length) {

    int min;

    for (int i = 0; i < length; ++i) {
        if (array[i] < min) min = array[i];
    }
    return min;
}


/*
    Push items to an array in range and with step
 */
static int
rangeIntArray(const int *array, const int start, const int end, const int step) {

    int index = 0;

    if (step > 0) {
        for (int value = start; value < end; value += step) {
            array[index] = value;
            ++index;
        }
        return 0;
    } else if (step < 0) {
        for (int value = start; value > end; value += step) {
            array[index] = value;
            ++index;
        }
        return 0;
    }
    return -1;
}


/*
    Concatenate items of an integer array to string
 */
static int
joinIntArrayToString(char *str, const int *array, const unsigned int length) {

    int i;
    char *buffer;

    // WHAT IS
    buffer = calloc(10, sizeof(char));

    for (i = 0; i < length; ++i) {
        sprintf(buffer, "%d", array[i]);
        strcat(str, buffer);
    }
    free(buffer);
    return 0;
}


static unsigned int
indefOfLeftIntegerArray(int number, int *array, size_t length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == number) return i;
    }
    return -1;
}


static unsigned int
indefOfRightIntegerArray(int number, int *array, size_t length) {
    for (int i = length; i > 0; --i) {
        if (array[i] == number) return i;
    }
    return -1;
}


// Need rewrite for change object in-place
static int
sliceIntegerArray(int *array ) {
    return 0;
}


#endif // __ARRAY_H__
