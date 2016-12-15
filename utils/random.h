/* */

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./str.h"

#define MAX_RANDOM_WORD_LENGTH 20


char get_random_item_array(char *array, size_t length) {
    int index = (rand() % length);
    return array[index];
}


char* get_random_word() {
    char *string, *word;
    int word_length;

    string = malloc(sizeof(char) * 50);
    string = get_ascii_lowercase();

    word_length = (rand() % MAX_RANDOM_WORD_LENGTH) + 1;

    word = malloc(sizeof(char) * word_length);

    for (int i = 0; i < word_length; ++i) {
        word[i] = get_random_item_array(string, strlen(string));
    }

    free(string);

    toCapitalizeString(word);

    return word;
}
