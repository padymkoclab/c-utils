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

#ifndef ESCAPED_CHARS
    #define ESCAPED_CHARS "\a\b\f\n\r\t\v\\\?\'\"\0"
#endif


typedef struct _CounterWords {

} CounterWords;


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

/**
 * char str[] = "Following is the declaratison for strncmp() functin";

    char *token;
    token = splitString(str, " ");

    while (token != NULL) {
        puts(token);
        token = splitString(NULL, " ");
    }
 */
static char *_copy_text_for_split;
char *
splitString(char *text, char *delimiter) {

    if (strcmp(delimiter, "") == 0) return NULL;

    size_t len_delimiter = strlen(delimiter);
    char *token;
    size_t length_token;

    if (text != NULL) {

        _copy_text_for_split = calloc(strlen(text), sizeof(char));
        strcpy(_copy_text_for_split, text);

        _copy_text_for_split = strpbrk(_copy_text_for_split, delimiter);

        if (_copy_text_for_split == NULL) return text;

        length_token = strlen(text) - strlen(_copy_text_for_split);

        token = calloc(length_token, sizeof(char));

        strncpy(token, text, length_token);

        _copy_text_for_split += len_delimiter;

        return token;

    }

    if (_copy_text_for_split == NULL) return NULL;

    size_t _copy_text_length = strlen(_copy_text_for_split);
    char *temp;
    temp = calloc(_copy_text_length, sizeof(char));
    temp = strpbrk(_copy_text_for_split, delimiter);

    if (temp != NULL) {

        size_t temp_len = strlen(temp);

        length_token = _copy_text_length - temp_len;

        token = calloc(length_token, sizeof(char));

        strncpy(token, _copy_text_for_split, length_token);

        _copy_text_for_split = _copy_text_for_split + length_token + len_delimiter;

    } else {

        token = calloc(strlen(_copy_text_for_split), sizeof(char));
        strcpy(token, _copy_text_for_split);
        _copy_text_for_split = NULL;

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


int replaceSubstr(char *str, char *substr_from, char *substr_to) {

    size_t str_len = strlen(str);
    size_t substr_from_len = strlen(substr_from);
    size_t substr_to_len = strlen(substr_to);

    if (substr_from_len > str_len) return 0;

    unsigned int countSubstr = getCountSubstrOfString(str, substr_from);

    if (countSubstr == 0) return 0;

    size_t new_len_str = str_len - (countSubstr * substr_from_len) + (countSubstr * substr_to_len);

    char *buffer;
    buffer = calloc(new_len_str, sizeof(char));

    int i = 0;
    int start_index_shift;
    char *shift;
    shift = calloc(new_len_str, sizeof(char));

    while((shift = strstr(str, substr_from)) != NULL) {
        start_index_shift = strlen(str) - strlen(shift);
        strncat(buffer, str, start_index_shift);
        strcat(buffer, substr_to);
        str = str + start_index_shift + substr_from_len;
        ++i;
    };

    strcat(buffer, str);
    str = str - str_len + strlen(str);

    // str = realloc(str, strlen(buffer) * sizeof(buffer) + 10000);
    strcpy(str, buffer);

    free(shift);
    free(buffer);

    return 0;
}


int escapeString(char *str) {

    const size_t str_len = strlen(str);

    char *buffer;
    buffer = malloc(2 * str_len * sizeof(char) + 1);

    int i = 0;

    char escapedChr[3];

    while (i < str_len) {
        if (strchr(ESCAPED_CHARS, str[i]) != 0) {
            switch (str[i]) {
                case '\a':
                    strcpy(escapedChr, "\\a");
                    break;
                case '\b':
                    strcpy(escapedChr, "\\b");
                    break;
                case '\f':
                    strcpy(escapedChr, "\\f");
                    break;
                case '\n':
                    strcpy(escapedChr, "\\n");
                    break;
                case '\t':
                    strcpy(escapedChr, "\\t");
                    break;
                case '\r':
                    strcpy(escapedChr, "\\r");
                    break;
                case '\v':
                    strcpy(escapedChr, "\\v");
                    break;
                case '\"':
                    strcpy(escapedChr, "\"");
                    break;
                case '\'':
                    strcpy(escapedChr, "\'");
                    break;
                case '\\':
                    strcpy(escapedChr, "\\");
                    break;
                default:
                    strcpy(escapedChr, "");
                    break;
            }
            strcat(buffer, escapedChr);
        } else {
            strncat(buffer, &str[i], 1);
        }
        ++i;
    }

    str = realloc(str, sizeof(char) * strlen(buffer));
    strcpy(str, buffer);

    free(buffer);

    return 0;
}


/**
 * Not implemented
 */
int unEscapeString(char *str) {

    return -1;

    const size_t str_len = strlen(str);

    char *buffer;
    buffer = malloc(str_len * sizeof(char) + 1000);

    int i = 0;

    char escapedChr[3];

    while (i < str_len) {
        if (strchr(ESCAPED_CHARS, str[i]) != 0) {
            switch (str[i]) {
                case '\a':
                    strcpy(escapedChr, "\\a");
                    break;
                case '\b':
                    strcpy(escapedChr, "\\b");
                    break;
                case '\f':
                    strcpy(escapedChr, "\\f");
                    break;
                case '\n':
                    strcpy(escapedChr, "\\n");
                    break;
                case '\t':
                    strcpy(escapedChr, "\\t");
                    break;
                case '\r':
                    strcpy(escapedChr, "\\r");
                    break;
                case '\v':
                    strcpy(escapedChr, "\\v");
                    break;
                case '\"':
                    strcpy(escapedChr, "\"");
                    break;
                case '\'':
                    strcpy(escapedChr, "\'");
                    break;
                case '\\':
                    strcpy(escapedChr, "\\");
                    break;
                default:
                    strcpy(escapedChr, "");
                    break;
            }
            strcat(buffer, escapedChr);
        } else {
            strncat(buffer, &str[i], 1);
        }
        ++i;
    }

    str = realloc(str, sizeof(char) * strlen(buffer));
    strcpy(str, buffer);

    free(buffer);

    return 0;
}


static char *_copy_text_for_words;
char *
getWords(char *text) {

    char *word;

    if (text != NULL) {
        _copy_text_for_words = calloc(strlen(text), sizeof(char));
        strcpy(_copy_text_for_words, text);
        word = splitString(text, " ");
    }

    word = splitString(NULL, " ");

    if (word != NULL) {
        stripString(word, ",.:();!?", 'b');
    }

    return word;
}


unsigned int
getCountWords(char *str) {

    char *word = getWords(str);

    unsigned int count = 0;
    while (word != NULL) {
        word = getWords(NULL);
        ++count;
    }

    return count;
}


int
counterWords(CounterWords *counter_words, char *text) {
    // need fill dictionary
    return 0;
}


#endif // __STRING_H__
