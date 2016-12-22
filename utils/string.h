/* Copyright */


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


#ifndef __STRING_H__
#define __STRING_H__

#ifndef DIGITS
#define DIGITS "0123456789"
#endif


/*
    A Struct for hold 2D-array with count items
 */
typedef struct _ListStringsWithLength {
    char **list;
    size_t length;
} ListStringsWithLength;


char* getCharactersByCodesRange(int start_code, int end_code) {
    char *string;
    int i = 0;
    string = malloc(sizeof(char) * end_code - start_code);
    for (int code = start_code; code < end_code; ++code) {
        string[i] = code;
        ++i;
    }
    return string;
}


#ifndef ASCII_LOWERCASE
#define ASCII_LOWERCASE getCharactersByCodesRange(97, 123)
#endif


#ifndef ASCII_UPPERCASE
#define ASCII_UPPERCASE getCharactersByCodesRange(65, 91)
#endif


#ifndef ASCII_LETTERS
#define ASCII_LETTERS strcat(ASCII_UPPERCASE, ASCII_LOWERCASE)
#endif


ListStringsWithLength* splitStringToListString(char *text, char *delimiter) {

    int i = 0;
    char *word, **list;
    ListStringsWithLength *list_strings_with_length = malloc(sizeof(ListStringsWithLength));

    size_t text_length = strlen(text);
    list = malloc(sizeof(char) * text_length);

    if (strstr(text, delimiter) == NULL || text_length <= strlen(delimiter)) {

        list[0] = malloc(sizeof(char) * text_length);
        strcpy(list[0], text);

        list_strings_with_length->length = 1;
        list_strings_with_length->list = list;

        return list_strings_with_length;
    }

    char *copy_text = malloc(text_length * sizeof(char) + 1);
    strcpy(copy_text, text);

    word = strtok(copy_text, delimiter);

    while (word != NULL) {
        list[i] = malloc(strlen(word) * sizeof(char));
        strcpy(list[i], word);
        word = strtok(NULL, delimiter);
        ++i;
    }

    list_strings_with_length->list = list;
    list_strings_with_length->length = i;

    return list_strings_with_length;

};


bool toUpperCase(char *str) {
    int i = 0;
    do {
        str[i] = toupper(str[i]);
        ++i;
    } while (str[i] != '\0');
    return true;
}


bool toLowerCase(char *str) {
    int i = 0;
    do {
        str[i] = tolower(str[i]);
        ++i;
    } while (str[i] != '\0');
    return true;
}


bool toTitleCase(char *str) {
    int i = 0;
    bool is_new_word = true;

    while (str[i]) {
        if (is_new_word == true) {
            str[i] = toupper(str[i]);
            is_new_word = false;
        } else {
            if (str[i] == ' ') {
                is_new_word = true;
                ++i;
                continue;
            } else {
                str[i] = tolower(str[i]);
            }
        }
        ++i;
    }
    return true;
}


bool toCapitalizeCase(char *str) {
    int i = 0;
    while (str[i]) {
        if (i > 0) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
        ++i;
    }
    return true;
}


bool toSwapCase(char *str) {
    int i = 0;
    do {
        if (isupper(str[i]) != 0) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i]) != 0) {
            str[i] = toupper(str[i]);
        }
        ++i;
    } while (str[i] != '\0');
    return true;
}


bool toCamelCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (i % 2 == 0) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
        ++i;
    }
    return true;
}


// Need rewrite for change object in-place
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


unsigned int getCountWords(char *str) {
    ListStringsWithLength *list_with_length = getWords(str);
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


bool startSwithString(char *str, char *prefix) {
    size_t prefix_len = strlen(prefix);
    if (strlen(str) >= prefix_len) {
        return 0 == strncmp(str, prefix, prefix_len);
    }
    return false;
}


bool endSwithString(char *str, char *ending) {
    size_t ending_len = strlen(ending);
    size_t str_len = strlen(str);
    if (str_len >= ending_len) {
        return 0 == strncmp(str + (str_len - ending_len), ending, ending_len);
    }
    return false;
}


bool containsString(char *str, char *substr) {
    size_t substr_len = strlen(substr);
    if (strlen(str) >= substr_len) {
        return 0 != strstr(str, substr);
    }
    return false;
}


/**
 * Return true is whole string contains only digits, otherwise return false.
 * @param  str string
 * @return     bool
 */
bool isNumericString(char *str) {
    int i = 0;
    do {
        if (isdigit(str[i]) == 0) {
            return false;
        };
        i++;
    } while (str[i] != '\0');
    return true;
}


bool reverseString(char *str) {

    const size_t str_len = strlen(str);
    const float half_len = str_len / 2;

    // FIXME: convert float to int with floor()
    //
    // half_len = (half_len % 2 == 0) ? half_len : half_len - 1;
    // const int middle_len;

    for (int i = 0; i < str_len; ++i) {
        str[i] = str[str_len - i - 1];
    }

    return 0;
}


bool sliceString(char *str, const unsigned int slice_from, const unsigned int slice_to) {

    unsigned int slice_to_copy = slice_to;

    size_t new_len_string = slice_to_copy - slice_from;

    if (slice_from < 0 || slice_to < 0 || (slice_from > slice_to)) return false;

    size_t len_string = strlen(str);

    if (slice_to_copy > len_string) slice_to_copy = len_string;

    char *buffer;
    buffer = calloc(new_len_string, sizeof(char));

    memmove(str, str + slice_from, new_len_string);
    strncpy(buffer, str, new_len_string);
    strcpy(str, buffer);

    free(buffer);

    return false;
}


unsigned int indexOfLeftString(const char *str, const char *substr) {

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (substr_len > str_len) return -1;

    char *found_substr = strstr(str, substr);

    if (found_substr != NULL) {
        return str_len - strlen(found_substr);
    }
    return -1;
}

// not working
unsigned int indexOfRightString(const char *str, const char *substr) {

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (substr_len > str_len) return -1;

    char *found_substr = strstr(str, substr);

    if (found_substr != NULL) return str_len - strlen(found_substr);

    return -1;
}


unsigned int getCountSubstrOfString(char *str, char *substr) {

    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    unsigned int count = 0;

    if (substr_len > str_len) return -1;

    char *found_substr;
    found_substr = strstr(str, substr);
    while (found_substr != NULL) {
        found_substr = strstr(found_substr + substr_len, substr);
        ++count;
    }
    return count;
}


/*
 * Uncompleted
 * Strip string from left, right or both.
 */
bool stripString(char *str, char *substr, char action) {

    if (action == 'b' || action == 'l' || action == 'r') {

    }

    return 0;
}


/*
 * Uncompleted
 */
static char *old_string;
char* strsplit(char *string, const char *delimiter) {

    char *token;

    if (string == NULL) {
        string = old_string;
    }

    string += strspn(string, delimiter);

    token = string;

    string = strpbrk(string, delimiter);
    puts(token);
    return token;
}


#endif // __STRING_H__
