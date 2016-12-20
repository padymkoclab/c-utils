/* Copyright */


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


#ifndef __STRING_H__
#define __STRING_H__


/*
    A logical type
 */
typedef enum {
    false,
    true,
} bool;


typedef struct _StringWithLength {
    char *str;
    size_t len;
} StringWithLength;


/*
    A Struct for hold 2D-array with count items
 */
typedef struct _ListStringsWithLength {
    char **array;
    size_t length;
} ListStringsWithLength;


char* get_characters_by_codes_range(int start_code, int end_code) {
    char *string;
    int i = 0;
    string = malloc(sizeof(char) * end_code - start_code);
    for (int code = start_code; code < end_code; ++code) {
        string[i] = code;
        ++i;
    }
    return string;
}


ListStringsWithLength* splitStringToList(char *original_string, char *delimiter) {

    int i = 0;
    char *word, *string;
    char **array_strings;
    ListStringsWithLength *string_list = malloc(sizeof(ListStringsWithLength));

    array_strings = malloc(sizeof(char) * 10000);

    size_t original_string_length = strlen(original_string);

    string = malloc(original_string_length * sizeof(char));

    strcpy(string, original_string);

    word = strtok(string, delimiter);
    while (word != NULL) {
        array_strings[i] = malloc(strlen(word) * sizeof(char));
        array_strings[i] = word;
        word = strtok(NULL, delimiter);
        ++i;
    }

    string_list->array = array_strings;
    string_list->length = i;

    return string_list;

};


char* get_ascii_lowercase() {
    return get_characters_by_codes_range(97, 123);
}


char* get_ascii_uppercase() {
    return get_characters_by_codes_range(65, 91);
}


char* get_ascii_letters() {
    return strcat(get_ascii_uppercase(), get_ascii_lowercase());
}


char* toUpperString(char *string) {
    int i = 0;
    do {
        string[i] = toupper(string[i]);
        ++i;
    } while (string[i] != '\0');
    return string;
}


char* toLowerString(char *string) {
    int i = 0;
    do {
        string[i] = tolower(string[i]);
        ++i;
    } while (string[i] != '\0');
    return string;
}


char* toTitleString(char *string) {
    int i = 0;
    bool is_new_word = true;

    while (string[i]) {
        if (is_new_word == true) {
            string[i] = toupper(string[i]);
            is_new_word = false;
        } else {
            if (string[i] == ' ') {
                is_new_word = true;
                ++i;
                continue;
            } else {
                string[i] = tolower(string[i]);
            }
        }
        ++i;
    }

    return string;
}


char* toCapitalizeString(char *string) {
    int i = 0;
    while (string[i]) {
        if (i > 0) {
            string[i] = tolower(string[i]);
        } else {
            string[i] = toupper(string[i]);
        }
        ++i;
    }
    return string;
}


char* toSwapCaseString(char *string) {
    int i = 0;
    do {
        if (isupper(string[i]) != 0) {
            string[i] = tolower(string[i]);
        } else if (islower(string[i]) != 0) {
            string[i] = toupper(string[i]);
        }
        ++i;
    } while (string[i] != '\0');
    return string;
}


/*
    Parse a text and return pointer to a ListStringsWithLength words and count it
 */
ListStringsWithLength* getWords(char *text) {

    // a variable for count words
    int count = 0;

    // keep length of the text
    size_t text_len = strlen(text);

    // a flag indicating the a beginning of a word
    bool new_word = false;

    // an index of a start found a word
    int index_start_word = 0;

    // 2D-array for found word
    // it will be same memory size as the original text
    char **words = malloc(text_len * sizeof(char));

    for (int i = 0; i <= text_len; ++i) {

        // if found ascii letter or digits and new no traced early
        // keep index of beginning a new word
        // and change the flag
        if (isalnum(text[i]) != 0) {
            if (new_word == false) {
                new_word = true;
                index_start_word = i;
            }

        // if it is not ascii letter or digits and a word traced early
        // it means the word ended
        } else {
            if (new_word == true) {

                // allocate a memory for a new word in the array of words
                words[count] = malloc(i - index_start_word * sizeof(char) + 1);

                // copy the found word from the text by indexes
                strncpy(words[count], text + index_start_word, i - index_start_word);

                // change the flag
                new_word = false;

                // increase the counter of words
                count++;
            }
        };
    }

    // bind the found words and it count to a structure and return it
    ListStringsWithLength *list_with_length = malloc(sizeof(ListStringsWithLength));

    list_with_length->length = count;
    list_with_length->list = words;

    return list_with_length;
}


int getCountWords(char *text) {
    ListStringsWithLength *list_with_length = getWords(text);
    return list_with_length->length;
}


/*
    Print information of a ListStringsWithLength
 */
void printListStringsWithLength(ListStringsWithLength *list_with_length) {
    printf("Total items: %li\n", list_with_length->length);
    puts("----------------------");
    for (int i = 0; i < list_with_length->length; ++i) {
        printf("%d. %s\n", i + 1, list_with_length->list[i]);
    }
}


#endif // __STRING_H__
