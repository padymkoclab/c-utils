/* Copyright */

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct StringArrayStruct {
    char **array;
    size_t length;
} StringArray;


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


StringArray split_string(char *original_string, char *delimiter) {
    int i = 0;
    char *word, *string;
    char **array_strings;
    StringArray result;

    array_strings = malloc(sizeof(char) * 100);

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

    result.array = array_strings;
    result.length = i;

    return result;
}


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


