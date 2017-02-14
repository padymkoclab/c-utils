/**
 * Utils for working with a single-array chars - string.
 */


#ifndef __STRING_H__
#define __STRING_H__


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>


#include "func.h"
#include "testing/unittest.h"


#define STR_ERROR_VALUE_ERROR "ValueError"


#define ESCAPED_CHARS "\a\b\f\n\r\t\v\\\?\'\"\0"
#define DIGITS "0123456789"
#define ASCII_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define ASCII_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ASCII_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define RUSSIAN_LOWERCASE "абвгдеёжзийклмнопрстуфхцчшщыьэюя"
#define RUSSIAN_UPPERCASE "АБВГДЕЁЖЗИЙКЛМНОПРТУФХЦЧШЩЫЭЮЯ"
#define RUSSIAN_LETTERS "АБВГДЕЁЖЗИЙКЛМНОПРТУФХЦЧШЩЫЭЮЯабвгдеёжзийклмнопрстуфхцчшщыьэюя"


// DOES NOT WORK
int
str_get_characters_by_codes_range(char *buffer, const unsigned int start_code, const unsigned int end_code)
{
    if (end_code > 128)
        return -1;

    if (start_code < 1 || end_code < start_code)
        return -2;

    int i = 0;
    for (int code = start_code; code < end_code; ++code) {
        buffer[i] = code;
        ++i;
    }
    return 0;
}


char *
str_to_upper_case(char str[])
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    do {
        result[i] = toupper(str[i]);
        ++i;
    } while (str[i] != '\0');

    result[i] = '\0';

    return result;
}


char *
str_to_lower_case(char str[])
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    do {
        result[i] = tolower(str[i]);
        ++i;
    } while (str[i] != '\0');

    result[i] = '\0';

    return result;
}


char *
str_to_title_case(char str[])
{
    int i = 0;
    bool is_new_word = true;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i]) {
        if (is_new_word == true) {
            result[i] = toupper(str[i]);
            is_new_word = false;
        } else {
            if (str[i] == ' ') {
                is_new_word = true;
                ++i;
                continue;
            } else {
                result[i] = tolower(str[i]);
            }
        }
        ++i;
    }

    return result;
}


char *
str_to_capitalize_case(char str[])
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i]) {
        if (i > 0) {
            result[i] = tolower(str[i]);
        } else {
            result[i] = toupper(str[i]);
        }
        ++i;
    }

    return result;
}


char *
str_to_swap_case(char str[])
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    do {
        if (isupper(str[i]) != 0) {
            result[i] = tolower(str[i]);
        } else if (islower(str[i]) != 0) {
            result[i] = toupper(str[i]);
        }
        ++i;
    } while (str[i] != '\0');

    return result;
}


char *
str_to_camel_case(char str[])
{
    int i = 0;
    char *result;
    result = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i] != '\0') {
        if (i % 2 == 0) {
            result[i] = tolower(str[i]);
        } else {
            result[i] = toupper(str[i]);
        }
        ++i;
    }

    return result;
}


bool
str_startswith(char str[], char prefix[])
{
    size_t prefix_len = strlen(prefix);

    if (strlen(str) >= prefix_len) {
        return 0 == strncmp(str, prefix, prefix_len);
    }
    return false;
}


bool
str_endswith(char str[], char ending[])
{
    size_t ending_len = strlen(ending);
    size_t str_len = strlen(str);
    if (str_len >= ending_len) {
        return 0 == strncmp(str + (str_len - ending_len), ending, ending_len);
    }
    return false;
}


bool
str_is_alpha(char str[])
{
    return false;
}


bool
str_is_alnum(char str[])
{
    return false;
}


bool
str_is_digit(char str[])
{
    return false;
}


bool
str_is_lower_case(char str[])
{
    return false;
}


bool
str_is_upper_case(char str[])
{
    return false;
}


bool
str_is_title_case(char str[])
{
    return false;
}


bool
str_is_camel_case(char str[])
{
    return false;
}


bool
str_is_capitalize_case(char str[])
{
    return false;
}



bool
str_is_numeric(char str[])
{
    return false;
}


// Uncompleted
char *
str_center(char str[], unsigned int new_length, char placeholder)
{
    size_t str_length = strlen(str);

    if (new_length <= str_length)
        return str;

    char *buffer, *left_part, *right_part;
    unsigned int total_rest_length, left_length, right_length;

    buffer = malloc(sizeof(char) * new_length);

    total_rest_length = new_length - str_length;

    if (total_rest_length % 2 == 0) {
        left_length = right_length = total_rest_length / 2;
    } else {
        left_length = right_length = total_rest_length / 2;
    }

    float v = 11;
    printf("%f\n", 1 / 2);

    // sprintf(buffer, "%s%s%s", left_part, str, right_part);
    // free(left_part);
    // free(right_part);

    return "buffer";
}


bool
str_reverse(char string[])
{
    size_t str_len = strlen(string);
    for (int i = 0; i < str_len / 2; ++i) {
        SWAP(char, string[i], string[str_len - i - 1]);
    }
    return 0;
}


int
slice_string(char *str, const unsigned int slice_from, const unsigned int slice_to)
{

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


char *_copy_text_for_split;
char *
split_string(char *text, char *delimiter)
{

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
index_of_string(const char *str, const char *substr, char direction)
{

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


unsigned int
count_substr_of_string(char *str, char *substr)
{

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
strip_string(char *str, char *substr, char action)
{

    const char allowed_action[4] = "blr";
    const size_t str_len = strlen(str);
    const char temp[2] = {action, '\0'};

    if (index_of_string(allowed_action, temp, 'l') < 0) {
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
        if (index_of_string(substr, single_char, 'l') == -1) break;
        shift_from_left += 1;
    }

    for (int i = str_len - 1; i >= 0; --i) {
        single_char[0] = str[i];
        if (index_of_string(substr, single_char, 'l') == -1) break;
        shift_from_right += 1;
    }

    slice_string(str, shift_from_left, str_len - shift_from_right);

    return 0;
}


int
replace_substr_of_string(char *str, char *substr_from, char *substr_to)
{

    size_t str_len = strlen(str);
    size_t substr_from_len = strlen(substr_from);
    size_t substr_to_len = strlen(substr_to);

    if (substr_from_len > str_len) return 0;

    unsigned int countSubstr = count_substr_of_string(str, substr_from);

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


int
escape_string(char *str)
{

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


/*
    Not implemented
*/
int
unescape_string(char *str)
{

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


int
truncate_chars_string()
{
    return 0;
}

int
truncate_words_string()
{
    return 0;
}


int
partition_string()
{
    return 0;
}


char *
str_repeat(char str[], unsigned int times)
{
    if (times < 1) {
        fprintf(stderr, "%s: %s\n", STR_ERROR_VALUE_ERROR, "Times must be more 0");
        return NULL;
    }

    char *result;
    size_t str_len = strlen(str);
    result = malloc(sizeof(char) * str_len + 1);

    while (times--) {
        strcat(result, str);
    }
    return result;
}


/**
 * Tests
 */


void
test_str_to_upper_case()
{
    assertStringEquals(str_to_upper_case("With my tongue"), "WITH MY TONGUE");
    assertStringEquals(str_to_upper_case("TONGUE"), "TONGUE");
    assertStringEquals(str_to_upper_case(""), "");
    assertStringEquals(str_to_upper_case("A123a"), "A123A");
}


void
test_str_to_lower_case()
{
    assertStringEquals(str_to_lower_case(" They will be expanded. "), " they will be expanded. ");
    assertStringEquals(str_to_lower_case("AJKNDJWDNW"), "ajkndjwdnw");
    assertStringEquals(str_to_lower_case(""), "");
    assertStringEquals(str_to_lower_case("A123a"), "a123a");
}


void
test_str_to_title_case()
{
    assertStringEquals(str_to_title_case(" They will be expanded. "), " They Will Be Expanded. ");
    assertStringEquals(str_to_title_case("AJKNDJWDNW"), "Ajkndjwdnw");
    assertStringEquals(str_to_title_case(" test XTES"), " Test Xtes");
    assertStringEquals(str_to_title_case(""), "");
    assertStringEquals(str_to_title_case("A123a"), "A123a");
}


void
test_start_end_swith()
{

}


void
test_str()
{
    test_str_to_upper_case();
    test_str_to_lower_case();
    test_str_to_title_case();

    puts(str_center("AC", 50, '*'));
}


#endif // __STRING_H__
