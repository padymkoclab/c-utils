/* */

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./string.h"


char getRandCharFromString(char *str) {
    int index = (rand() % strlen(str));
    return str[index];
}

// Not implemented
bool generateUUID4(char *str){
    return true;
}


/*
 *   FIXME!!!! Does not work correct.
 *   How return None or undefined instead of NULL
 */
int getRandInt(const int min_length, const int max_length) {
    if (min_length == max_length) {
        return min_length;
    } else if (min_length > max_length) {
        return '\0';
    }
    int rand_n = rand();
    int result = rand_n % (max_length - min_length) + min_length;

    if (result == max_length - 1 && rand_n > (RAND_MAX / 2)) {
        result = max_length;
    }

    return result;
}


// Need update
char* getRandWord(unsigned int min_length, unsigned int max_length, char register_case) {

    if (min_length < 1 || max_length < 1 || min_length > max_length) {
        return false;
    }

    // const char choices_register[5] = "ulct";

    // if (indexOfString(choices_register, register_case) == -1) {
    //     return NULL;
    // };

    if (register_case == 'u' || register_case == 't' || register_case == 'l' || register_case == 'c') {

        char *word;
        int word_length;

        word_length = getRandInt(min_length, max_length);
        word = malloc(sizeof(char) * word_length);

        for (int i = 0; i < word_length; ++i) {
            word[i] = getRandCharFromString(ASCII_LOWERCASE);
        }

        if (register_case == 'u') {
            toUpperCase(word);
        } else if (register_case == 't') {
            toTitleCase(word);
        } else if (register_case == 'c') {
            toCamelCase(word);
        }

        return word;
    }
    return false;
}


bool shuffleIntArray(int *array, const size_t length) {
    int rand_index;
    for (int i = 0; i < length; ++i) {
        rand_index = getRandInt(0, length - 1);

        // swap elements
        int temp = array[i];
        array[i] = array[rand_index];
        array[rand_index] = temp;
    }
    return true;
}


#endif // __RANDOM_H__
