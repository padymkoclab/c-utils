/*

 */


#ifndef __MATH_H__
#define __MATH_H__


unsigned long int factorial(const long int n) {
    if (n == 1) {
        return n;
    }
    return n * factorial(n - 1);
}


static unsigned long int get_value_sequence_fibonacci(const unsigned int index) {
    if (index == 0 || index == 1) {
        return index;
    }
    return get_value_sequence_fibonacci(index - 1) + get_value_sequence_fibonacci(index - 2);
}

unsigned long int* fibonacci(const int length) {
    unsigned long int* array;
    array = malloc(length * sizeof(unsigned long int));
    for (int i = 0; i < length; ++i) {
        array[i] = get_value_sequence_fibonacci(i);
    }
    return array;
}


#endif // __MATH_H__
