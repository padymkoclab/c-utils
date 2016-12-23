/* Copyright */


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>

#ifndef __STRING_H__
#define __STRING_H__

#ifndef DIGITS
#define DIGITS "0123456789"
#endif

#ifndef ASCII_LOWERCASE
#define ASCII_LOWERCASE "abcdefghijklmnopqrstuvwxyz\0"
#endif


#ifndef ASCII_UPPERCASE
#define ASCII_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
#endif


#ifndef ASCII_LETTERS
#define ASCII_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#endif


int
getCharactersByCodesRange(char *buffer, const unsigned int start_code, const unsigned int end_code) {

    if (end_code > 128) return -1;

    if (start_code < 1 || end_code < start_code) return -2;

    int i = 0;
    for (int code = start_code; code < end_code; ++code) {
        buffer[i] = code;
        ++i;
    }
    return 0;
}


static char *_copy_text;
char *
splitString(char *text, char *delimiter) {

    if (delimiter == '\0') return NULL;

    size_t len_delimiter = strlen(delimiter);
    char *token;
    size_t length_token;

    if (text != NULL) {

        _copy_text = calloc(strlen(text), sizeof(char));
        strcpy(_copy_text, text);

        _copy_text = strpbrk(_copy_text, delimiter);

        if (_copy_text == NULL) return NULL;

        length_token = strlen(text) - strlen(_copy_text);

        token = calloc(length_token, sizeof(char));

        strncpy(token, text, length_token);

        _copy_text += len_delimiter;

        return token;
    }

    size_t _copy_text_length = strlen(_copy_text);
    char *temp;
    temp = calloc(_copy_text_length, sizeof(char));
    temp = strpbrk(_copy_text, delimiter);

    if (temp != NULL) {
        size_t temp_len = strlen(temp);

        length_token = _copy_text_length - temp_len;

        // token = calloc(length_token, sizeof(char));

        strncpy(token, _copy_text, length_token);

        _copy_text = _copy_text + length_token + len_delimiter;
    } else {
        strcpy(token, _copy_text);
        _copy_text = NULL;
    }

    return token;
};


int
toUpperCase(char *str) {
    int i = 0;
    do {
        str[i] = toupper(str[i]);
        ++i;
    } while (str[i] != '\0');
    return 0;
}


int
toLowerCase(char *str) {
    int i = 0;
    do {
        str[i] = tolower(str[i]);
        ++i;
    } while (str[i] != '\0');
    return 0;
}


int
toTitleCase(char *str) {
    int i = 0;
    bool
    is_new_word = true;

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
    return 0;
}


int
toCapitalizeCase(char *str) {
    int i = 0;
    while (str[i]) {
        if (i > 0) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
        ++i;
    }
    return 0;
}


int
toSwapCase(char *str) {
    int i = 0;
    do {
        if (isupper(str[i]) != 0) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i]) != 0) {
            str[i] = toupper(str[i]);
        }
        ++i;
    } while (str[i] != '\0');
    return 0;
}


int
toCamelCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (i % 2 == 0) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
        ++i;
    }
    return 0;
}


// Need rewrite for change object in-place
/*
    Parse a text and return pointer to a ListStringsWithLength words and count it
 */
// ListStringsWithLength *
// getWords(char *text) {

//     // a variable for count words
//     int count = 0;

//     // keep length of the text
//     size_t text_len = strlen(text);

//     // a flag indicating the a beginning of a word
//     bool
//     new_word = false;

//     // an index of a start found a word
//     int index_start_word = 0;

//     // 2D-array for found word
//     // it will be same memory size as the original text
//     char **words = malloc(text_len * sizeof(char));

//     for (int i = 0; i <= text_len; ++i) {

//         // if found ascii letter or digits and new no traced early
//         // keep index of beginning a new word
//         // and change the flag
//         if (isalnum(text[i]) != 0) {
//             if (new_word == false) {
//                 new_word = true;
//                 index_start_word = i;
//             }

//         // if it is not ascii letter or digits and a word traced early
//         // it means the word ended
//         } else {
//             if (new_word == true) {

//                 // allocate a memory for a new word in the array of words
//                 words[count] = malloc(i - index_start_word * sizeof(char) + 1);

//                 // copy the found word from the text by indexes
//                 strncpy(words[count], text + index_start_word, i - index_start_word);

//                 // change the flag
//                 new_word = false;

//                 // increase the counter of words
//                 count++;
//             }
//         };
//     }

//     // bind the found words and it count to a structure and return it
//     ListStringsWithLength *list_with_length = malloc(sizeof(ListStringsWithLength));

//     list_with_length->length = count;
//     list_with_length->list = words;

//     return list_with_length;
// }


// unsigned int
// getCountWords(char *str) {
//     ListStringsWithLength *list_with_length = getWords(str);
//     return list_with_length->length;
// }


int
startSwithString(char *str, char *prefix) {
    size_t prefix_len = strlen(prefix);
    if (strlen(str) >= prefix_len) {
        return 0 == strncmp(str, prefix, prefix_len);
    }
    return false;
}


int
endSwithString(char *str, char *ending) {
    size_t ending_len = strlen(ending);
    size_t str_len = strlen(str);
    if (str_len >= ending_len) {
        return 0 == strncmp(str + (str_len - ending_len), ending, ending_len);
    }
    return false;
}


int
containsString(char *str, char *substr) {
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
int
isNumericString(char *str) {
    int i = 0;
    do {
        if (isdigit(str[i]) == 0) {
            return false;
        };
        i++;
    } while (str[i] != '\0');
    return 0;
}


int
reverseString(char *str) {

    const size_t str_len = strlen(str);
    const float half_len = str_len / 2;

    for (int i = 0; i < half_len; ++i) {
        char temp = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = temp;
    }
    return 0;
}


int
sliceString(char *str, const unsigned int slice_from, const unsigned int slice_to) {

    unsigned int slice_to_copy = slice_to;

    size_t new_len_string = slice_to_copy - slice_from;

    if (slice_from < 0 || slice_to < 0 || (slice_from > slice_to)) return -1;

    size_t len_string = strlen(str);

    if (slice_to_copy > len_string) slice_to_copy = len_string;

    char *buffer;
    buffer = malloc(new_len_string * sizeof(char) + 1);

    memmove(str, str + slice_from, new_len_string);

    strncpy(buffer, str, new_len_string);
    strcpy(str, buffer);

    free(buffer);

    return 0;
}


unsigned int
indexOfString(const char *str, const char *substr, char direction) {

    if (direction == 'l' || direction == 'r') {

        size_t str_len = strlen(str);
        size_t substr_len = strlen(substr);

        if (substr_len > str_len) return -1;

        char *found_substr = strstr(str, substr);

        if (direction == 'l') {
            if (found_substr != NULL) {
                return str_len - strlen(found_substr);
            }
            return -1;
        } else {
            unsigned int latest_index = -1;
            char *found_substr = strstr(str, substr);
            while (found_substr != NULL) {
                latest_index = str_len - strlen(found_substr);
                found_substr = strstr(found_substr + substr_len, substr);
            }
            return latest_index;
        }
    }
    return -2;
}


int
getCountSubstrOfString(char *str, char *substr) {

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
 * Strip string from left, right or both.
 */
int
stripString(char *str, char *substr, char action) {

    const char allowed_action[4] = "blr";
    const size_t str_len = strlen(str);
    const char temp[2] = {action, '\0'};

    if (indexOfString(allowed_action, temp, 'l') < 0) {
        return -1;
    }

    // if (strcmp(substr, "") == 0) {
    //     substr = "\n\t ";
    // }

    unsigned int shift_from_left = 0;
    unsigned int shift_from_right = 0;

    char single_char[2];
    single_char[1] = '\0';

    for (int i = 0; i < str_len; ++i) {
        single_char[0] = str[i];
        if (indexOfString(substr, single_char, 'l') == -1) break;
        shift_from_left += 1;
    }

    for (int i = str_len - 1; i >= 0; --i) {
        single_char[0] = str[i];
        if (indexOfString(substr, single_char, 'l') == -1) break;
        shift_from_right += 1;
    }

    sliceString(str, shift_from_left, str_len - shift_from_right);

    return 0;
}

#endif // __STRING_H__
