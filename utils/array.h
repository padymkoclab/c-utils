/*

 */

#ifndef __ARRAY_H__
#define __ARRAY_H__


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


bool reverseIntArray(int *array, const size_t length) {
    int *copy_;
    copy_ = calloc(length, sizeof(int));
    copy_ = array;

    for (int i = 0; i < length; ++i) {
        array[i] = copy_[length - i - 1];
    }
    free(copy_);
    return true;
}


int maxIntArray(int *array, size_t length) {
    if (length == 0) {
        return '\0';
    }
    int max;
    for (int i = 0; i < length; ++i) {
        if (array[i] > max) {
            max = array[i];
        };
    }
    return max;
}


int minIntArray(int *array, size_t length) {
    if (length == 0) {
        return '\0';
    }
    int min;
    for (int i = 0; i < length; ++i) {
        if (array[i] < min) {
            min = array[i];
        };
    }
    return min;
}


bool rangeIntArray(int *array, const int start, const int end, const int step) {

    int index = 0;
    if (step > 0) {
        for (int value = start; value < end; value += step) {
            array[index] = value;
            ++index;
        }
        return true;
    } else if (step < 0) {
        for (int value = start; value > end; value += step) {
            array[index] = value;
            ++index;
        }
        return true;
    }
    return false;
}


int joinIntArrayToString(char *str, int *array, const size_t length) {
    int i;

    char *buffer;
    buffer = calloc(10, sizeof(char));

    for (i = 0; i < length; ++i) {
        sprintf(buffer, "%d", array[i]);
        strcat(str, buffer);
    }
    free(buffer);
    return 0;
}


unsigned int indefOfLeftIntegerArray(int number, int *array, size_t length) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == number) return i;
    }
    return -1;
}


unsigned int indefOfRightIntegerArray(int number, int *array, size_t length) {
    for (int i = length; i > 0; --i) {
        if (array[i] == number) return i;
    }
    return -1;
}


// Need rewrite for change object in-place
bool sliceIntegerArray(int *array ) {
    return true;
}


#endif // __ARRAY_H__
