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
#include "pprint.h"
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



enum str_direction_t {
    LEFT,
    RIGHT,
};


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
    char *buffer;
    buffer = malloc(sizeof(char) * strlen(str) + 1);

    do {
        buffer[i] = toupper(str[i]);
        ++i;
    } while (str[i] != '\0');
    buffer[i] = '\0';

    return buffer;
}


char *
str_to_lower_case(char str[])
{
    int i = 0;
    char *buffer;
    buffer = malloc(sizeof(char) * strlen(str) + 1);

    do {
        buffer[i] = tolower(str[i]);
        ++i;
    } while (str[i] != '\0');
    buffer[i] = '\0';

    return buffer;
}


char *
str_to_title_case(char str[])
{
    unsigned int i;
    size_t str_len = strlen(str);

    char *buffer;
    buffer = malloc(sizeof(char) * str_len + 1);

    for (i = 0; i < str_len; ++i) {
        if (i == 0 || buffer[i - 1] == ' ')
            buffer[i] = toupper(str[i]);
        else
            buffer[i] = tolower(str[i]);

    }
    buffer[i + 1] = '\0';

    return buffer;
}


char *
str_to_capitalize_case(char str[])
{
    unsigned int i = 0;
    char *buffer;
    buffer = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i] != '\0') {
        if (i > 0)
            buffer[i] = tolower(str[i]);
        else
            buffer[i] = toupper(str[i]);
        ++i;
    }
    buffer[i + 1] = '\0';

    return buffer;
}


char *
str_to_swap_case(char str[])
{
    unsigned int i = 0;
    char *buffer;
    buffer = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i] != '\0') {
        if (isupper(str[i]) != 0)
            buffer[i] = tolower(str[i]);
        else if (islower(str[i]) != 0)
            buffer[i] = toupper(str[i]);
        else
            buffer[i] = str[i];
        ++i;
    }
    buffer[i + 1] = '\0';

    return buffer;
}


char *
str_to_camel_case(char str[])
{
    int i = 0;
    char *buffer;
    buffer = malloc(sizeof(char) * strlen(str) + 1);

    while (str[i] != '\0') {
        if (i % 2 == 0)
            buffer[i] = tolower(str[i]);
        else
            buffer[i] = toupper(str[i]);
        ++i;
    }
    buffer[i + 1] = '\0';

    return buffer;
}


bool
str_startswith(char str[], char prefix[])
{
    size_t prefix_len = strlen(prefix);

    if (strlen(str) >= prefix_len)
        return 0 == strncmp(str, prefix, prefix_len);
    return false;
}


bool
str_endswith(char str[], char ending[])
{
    size_t ending_len = strlen(ending);
    size_t str_len = strlen(str);

    if (str_len >= ending_len)
        return 0 == strncmp(str + (str_len - ending_len), ending, ending_len);
    return false;
}


/**
 * Returns a sting "str" centered in string of a length width "new_length".
 * Padding is done using the specified fill character "placeholder".
 */
char *
str_center(char str[], unsigned int new_length, char placeholder)
{
    size_t str_length = strlen(str);

    // if a new length is less or equal length of the original string, returns the original string
    if (new_length <= str_length)
        return str;

    char *buffer;
    unsigned int i, total_rest_length;

    buffer = malloc(sizeof(char) * new_length);

    // length of a wrapper of the original string
    total_rest_length = new_length - str_length;

    // write a prefix to buffer
    i = 0;
    while (i < (total_rest_length / 2)) {
        buffer[i] = placeholder;
        ++i;
    }
    buffer[i + 1] = '\0';

    // write the original string
    strcat(buffer, str);

    // write a postfix to the buffer
    i += str_length;
    while (i < new_length) {
        buffer[i] = placeholder;
        ++i;
    }
    buffer[i + 1] = '\0';

    return buffer;
}


bool
str_is_alpha(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;

    while (str[i] != '\0') {
        if (isalpha(str[i]) == 0) {
            return false;
        }
        ++i;
    }
    return true;
}


bool
str_is_alnum(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;

    while (str[i] != '\0') {
        if (isalnum(str[i]) == 0) {
            return false;
        }
        ++i;
    }
    return true;
}


bool
str_is_digit(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;

    while (str[i] != '\0') {
        if (isdigit(str[i]) == 0) {
            return false;
        }
        ++i;
    }
    return true;
}


bool
str_is_lower_case(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;

    bool has_at_least_single_char_in_lower_case = false;

    while (str[i] != '\0') {
        if (isupper(str[i]) != 0)
            return false;
        else if (islower(str[i]) != 0)
            has_at_least_single_char_in_lower_case = true;
        ++i;
    }

    return has_at_least_single_char_in_lower_case;
}


bool
str_is_upper_case(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;

    bool has_at_least_single_char_in_upper_case = false;

    while (str[i] != '\0') {
        if (islower(str[i]) != 0)
            return false;
        else if (isupper(str[i]) != 0)
            has_at_least_single_char_in_upper_case = true;
        ++i;
    }

    return has_at_least_single_char_in_upper_case;
}


// Uncompleted
bool
str_is_title_case(char str[])
{
    unsigned int i = 0;

    if (str[i] == '\0')
        return false;
/*
    bool new_word = false;

    while (str[i] != '\0') {
        if (isupper(str[i]) != 0) {
            new_word = true;
            return false;
        } else if (islower(str[i]) != 0) {

        }
        ++i;
    }
*/
    return false;
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
str_slice(char *str, const unsigned int slice_from, const unsigned int slice_to)
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


char **
str_split(char *text, char *delimiter, unsigned int *length)
{

    if (strcmp(delimiter, "") == 0)
        return NULL;

    char **result;
    result = malloc(sizeof(char) * 10);

    return result;
};


int
str_index(const char *str, const char *substr, enum str_direction_t direction)
{
    /*
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
    */
    return -2;
}


unsigned int
str_count(char *str, char *substr)
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
str_strip(char *str, char *substr, char action)
{
/*
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
*/
    return 0;
}


int
str_replace(char *str, char *substr_from, char *substr_to, unsigned int count)
{
/*
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
*/
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
str_truncate_chars()
{
    return 0;
}

int
str_truncate_words()
{
    return 0;
}


int
str_partition()
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

    while (times--)
        strcat(result, str);

    return result;
}


char *
str_concatenate(int count, ...)
{
    return NULL;
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
    assertStringEquals(str_to_title_case("ar das assdr !sas _text b"), "Ar Das Assdr !sas _text B");
}


void
test_str_to_capitalize_case()
{
    assertStringEquals(str_to_capitalize_case("some text is good"), "Some text is good");
    assertStringEquals(str_to_capitalize_case(" adc is rtoar"), " adc is rtoar");
    assertStringEquals(str_to_capitalize_case("vera"), "Vera");
    assertStringEquals(str_to_capitalize_case("_itil"), "_itil");
    assertStringEquals(str_to_capitalize_case("1code"), "1code");
    assertStringEquals(str_to_capitalize_case(""), "");
}


void
test_str_to_swap_case()
{
    assertStringEquals(str_to_swap_case("Math is simple and FUN "), "mATH IS SIMPLE AND fun ");
    assertStringEquals(str_to_swap_case("Built-in Types"), "bUILT-IN tYPES");
    assertStringEquals(str_to_swap_case(""), "");
    assertStringEquals(str_to_swap_case(" OR THE SLIGHTLY FUNCTION)"), " or the slightly function)");
    assertStringEquals(str_to_swap_case("Truth Value Testing"), "tRUTH vALUE tESTING");
    assertStringEquals(str_to_swap_case("collection classes are mutable."), "COLLECTION CLASSES ARE MUTABLE.");
}


void
test_str_to_camel_case()
{
    assertStringEquals(str_to_camel_case("zero of any numeric type"), "zErO Of aNy nUmErIc tYpE")
    assertStringEquals(str_to_camel_case(""), "")
    assertStringEquals(str_to_camel_case("A"), "a")
    assertStringEquals(str_to_camel_case("Xx"), "xX")
    assertStringEquals(str_to_camel_case("123"), "123")
    assertStringEquals(str_to_camel_case("built-in functions that"), "bUiLt-iN FuNcTiOnS ThAt")
    assertStringEquals(str_to_camel_case(" built-in functions that  "), " BuIlT-In fUnCtIoNs tHaT  ")
    assertStringEquals(str_to_camel_case("  built-in functions that  "), "  bUiLt-iN FuNcTiOnS ThAt  ")
}


void
test_str_startswith()
{
    assertFalse(str_startswith("", " "));
    assertTrue(str_startswith(" ", " "));
    assertTrue(str_startswith("simple.txt", "s"));
    assertTrue(str_startswith("simple.txt", "si"));
    assertTrue(str_startswith("simple.txt", "sim"));
    assertTrue(str_startswith("simple.txt", "simp"));
    assertTrue(str_startswith("simple.txt", "simpl"));
    assertTrue(str_startswith("simple.txt", "simple"));
    assertTrue(str_startswith("simple.txt", "simple."));
    assertTrue(str_startswith("simple.txt", "simple.t"));
    assertTrue(str_startswith("simple.txt", "simple.tx"));
    assertTrue(str_startswith("simple.txt", "simple.txt"));
    assertFalse(str_startswith("simple.txt", "simple.txt "));
    assertFalse(str_startswith("simple.txt", "imp"));
}


void
test_str_endswith()
{
    assertTrue(str_endswith("simple.txt", "txt"));
    assertFalse(str_endswith("simple.txt", "text"));
    assertTrue(str_endswith("", ""));
    assertTrue(str_endswith(" ", " "));
    assertFalse(str_endswith(" !", " "));
    assertTrue(str_endswith(" !", " !"));
    assertTrue(str_endswith("A", "A"));
    assertFalse(str_endswith("image.jpeg", "jpg"));
    assertTrue(str_endswith("image.jpeg", ""));
    assertTrue(str_endswith("image.jpeg", "g"));
    assertTrue(str_endswith("image.jpeg", "eg"));
    assertTrue(str_endswith("image.jpeg", "peg"));
    assertTrue(str_endswith("image.jpeg", "jpeg"));
    assertTrue(str_endswith("image.jpeg", ".jpeg"));
    assertTrue(str_endswith("image.jpeg", "e.jpeg"));
    assertTrue(str_endswith("image.jpeg", "ge.jpeg"));
    assertTrue(str_endswith("image.jpeg", "age.jpeg"));
    assertTrue(str_endswith("image.jpeg", "mage.jpeg"));
    assertTrue(str_endswith("image.jpeg", "image.jpeg"));

}


void
test_str_center()
{
    assertStringEquals(str_center("abc", 0, '*'), "abc");
    assertStringEquals(str_center("abc", 1, '*'), "abc");
    assertStringEquals(str_center("abc", 2, '*'), "abc");
    assertStringEquals(str_center("abc", 3, '*'), "abc");
    assertStringEquals(str_center("abc", 4, '*'), "abc*");
    assertStringEquals(str_center("abc", 5, '*'), "*abc*");
    assertStringEquals(str_center("abc", 6, '*'), "*abc**");
    assertStringEquals(str_center("abc", 7, '*'), "**abc**");
    assertStringEquals(str_center("", 7, '-'), "-------");
    assertStringEquals(str_center("1", 10, '!'), "!!!!1!!!!!");
    assertStringEquals(str_center("simple text", 10, '&'), "simple text");
    assertStringEquals(str_center("simple text", 15, '&'), "&&simple text&&");
    assertStringEquals(str_center("A", 0, '-'), "A");
    assertStringEquals(str_center("A", 1, '-'), "A");
    assertStringEquals(str_center("A", 10, '-'), "----A-----");
    assertStringEquals(str_center("text", 10, '*'), "***text***");
    assertStringEquals(str_center("The C programming language", 26, '!'), "The C programming language");
    assertStringEquals(str_center("The C programming language", 27, '!'), "The C programming language!");
    assertStringEquals(str_center("The C programming language", 28, '!'), "!The C programming language!");
    assertStringEquals(str_center("The C programming language", 29, '!'), "!The C programming language!!");
    assertStringEquals(str_center("The C programming language", 30, '!'), "!!The C programming language!!");
    assertStringEquals(str_center("The C programming language", 31, '!'), "!!The C programming language!!!");
}


void
test_str_is_alpha()
{
    assertFalse(str_is_alpha("1"));
    assertFalse(str_is_alpha("1a"));
    assertFalse(str_is_alpha("1 "));
    assertFalse(str_is_alpha("a "));
    assertFalse(str_is_alpha("1231 3123 23 1312"));
    assertFalse(str_is_alpha("123131231312"));
    assertFalse(str_is_alpha("sasa as asas "));
    assertTrue(str_is_alpha("sasaasasas"));
    assertFalse(str_is_alpha("sasa_asasas"));
    assertTrue(str_is_alpha("sad"));
    assertTrue(str_is_alpha("S"));
    assertTrue(str_is_alpha("s"));
    assertTrue(str_is_alpha("text"));
    assertTrue(str_is_alpha("TEXT"));
    assertFalse(str_is_alpha("TEXT "));
    assertFalse(str_is_alpha("S!"));
    assertFalse(str_is_alpha("!S"));
    assertFalse(str_is_alpha("sss?"));
    assertFalse(str_is_alpha(""));
    assertFalse(str_is_alpha("a-a"));
    assertFalse(str_is_alpha("a2a"));

}


void
test_str_is_alnum()
{
    assertTrue(str_is_alnum("1"));
    assertTrue(str_is_alnum("1a"));
    assertFalse(str_is_alnum("1 "));
    assertFalse(str_is_alnum("a "));
    assertFalse(str_is_alnum("1231 3123 23 1312"));
    assertTrue(str_is_alnum("123131231312"));
    assertFalse(str_is_alnum("sasa as asas "));
    assertTrue(str_is_alnum("sasaasasas"));
    assertFalse(str_is_alnum("sasa_asasas"));
    assertTrue(str_is_alnum("sad"));
    assertTrue(str_is_alnum("S"));
    assertTrue(str_is_alnum("s"));
    assertTrue(str_is_alnum("text"));
    assertTrue(str_is_alnum("TEXT"));
    assertFalse(str_is_alnum("TEXT "));
    assertFalse(str_is_alnum("S!"));
    assertFalse(str_is_alnum("!S"));
    assertFalse(str_is_alnum("sss?"));
    assertFalse(str_is_alnum(""));
    assertFalse(str_is_alnum("a-a"));
    assertTrue(str_is_alnum("a2a"));

}


void
test_str_is_digit()
{
    assertFalse(str_is_digit("1a"));
    assertFalse(str_is_digit("1 "));
    assertFalse(str_is_digit("a "));
    assertFalse(str_is_digit("1231 3123 23 1312"));
    assertTrue(str_is_digit("123131231312"));
    assertFalse(str_is_digit("sasa as asas "));
    assertFalse(str_is_digit("sasaasasas"));
    assertFalse(str_is_digit("sasa_asasas"));
    assertFalse(str_is_digit("sad"));
    assertFalse(str_is_digit("S"));
    assertFalse(str_is_digit("s"));
    assertFalse(str_is_digit("text"));
    assertFalse(str_is_digit("TEXT"));
    assertFalse(str_is_digit("TEXT "));
    assertFalse(str_is_digit("S!"));
    assertFalse(str_is_digit("!S"));
    assertFalse(str_is_digit("sss?"));
    assertFalse(str_is_digit(""));
    assertFalse(str_is_digit("a-a"));
    assertFalse(str_is_digit("a2a"));
    assertTrue(str_is_digit("0"));
    assertTrue(str_is_digit("1"));
    assertTrue(str_is_digit("2"));
    assertTrue(str_is_digit("3"));
    assertTrue(str_is_digit("4"));
    assertTrue(str_is_digit("5"));
    assertTrue(str_is_digit("6"));
    assertTrue(str_is_digit("7"));
    assertTrue(str_is_digit("8"));
    assertTrue(str_is_digit("9"));
    assertTrue(str_is_digit("10"));
    assertFalse(str_is_digit("-1"));
    assertFalse(str_is_digit("-10"));
    assertFalse(str_is_digit("-"));
    assertFalse(str_is_digit("2321.1232"));
    assertFalse(str_is_digit(".00000001"));
    assertFalse(str_is_digit("-1.1"));
    assertFalse(str_is_digit("1.1"));
    assertFalse(str_is_digit("0.1"));
    assertFalse(str_is_digit("-0.1"));
    assertFalse(str_is_digit("0.0"));
    assertFalse(str_is_digit("0."));
    assertTrue(str_is_digit("10000000000000"));
    assertFalse(str_is_digit("-10000000000000"));
}


void
test_str_is_lower_case()
{
    assertTrue(str_is_lower_case("asd sd sad sdas!@&@#@1231"));
    assertTrue(str_is_lower_case("text"));
    assertFalse(str_is_lower_case("texT"));
    assertTrue(str_is_lower_case("text "));
    assertFalse(str_is_lower_case(" A text.1$@^&()!Z"));
    assertFalse(str_is_lower_case(" .1$@^&()!"));
    assertFalse(str_is_lower_case("asd sd sAd sdas!@&@#@1231"));
    assertFalse(str_is_lower_case("@&@#@1231"));
    assertFalse(str_is_lower_case(""));
    assertFalse(str_is_lower_case(" "));
    assertFalse(str_is_lower_case("     "));
    assertFalse(str_is_lower_case("$"));
    assertFalse(str_is_lower_case("@12312"));
    assertFalse(str_is_lower_case(".12312"));
    assertFalse(str_is_lower_case("\" 32434"));
    assertFalse(str_is_lower_case("A"));
    assertTrue(str_is_lower_case("a"));
}


void
test_str_is_upper_case()
{
    assertFalse(str_is_upper_case("asd sd sad sdas!@&@#@1231"));
    assertTrue(str_is_upper_case("ASD SD SAD SDAS!@&@#@1231"));
    assertFalse(str_is_upper_case("text"));
    assertFalse(str_is_upper_case("texT"));
    assertTrue(str_is_upper_case("TEXT "));
    assertFalse(str_is_upper_case(" A text.1$@^&()!Z"));
    assertFalse(str_is_upper_case(" .1$@^&()!"));
    assertFalse(str_is_upper_case("asd sd sAd sdas!@&@#@1231"));
    assertFalse(str_is_upper_case("@&@#@1231"));
    assertFalse(str_is_upper_case(""));
    assertFalse(str_is_upper_case(" "));
    assertFalse(str_is_upper_case("     "));
    assertFalse(str_is_upper_case("$"));
    assertFalse(str_is_upper_case("@12312"));
    assertFalse(str_is_upper_case(".12312"));
    assertFalse(str_is_upper_case("\" 32434"));
    assertTrue(str_is_upper_case("A"));
    assertFalse(str_is_upper_case("a"));
}


void
test_str_is_title_case()
{
    assertTrue(str_is_title_case("A"));
    assertFalse(str_is_title_case("a"));
    assertFalse(str_is_title_case(""));
    assertTrue(str_is_title_case(" A"));
    assertFalse(str_is_title_case(" a"));
    assertFalse(str_is_title_case("aA"));
    assertTrue(str_is_title_case("A A"));
    assertFalse(str_is_title_case("\n"));
    assertTrue(str_is_title_case("A Titlecased Line"));
    assertTrue(str_is_title_case("A\nTitlecased Line"));
    assertTrue(str_is_title_case("A Titlecased, Line"));
    assertFalse(str_is_title_case("Not a capitalized String"));
    assertFalse(str_is_title_case("Not\ta Titlecase String"));
    assertFalse(str_is_title_case("Not--a Titlecase String"));
    assertFalse(str_is_title_case("NOT"));
    assertFalse(str_is_title_case("abc"));
}


void
test_str()
{
    test_str_to_upper_case();
    test_str_to_lower_case();
    test_str_to_title_case();
    test_str_to_capitalize_case();
    test_str_to_swap_case();
    test_str_to_camel_case();
    test_str_startswith();
    test_str_endswith();
    test_str_center();
    test_str_is_alpha();
    test_str_is_alnum();
    test_str_is_digit();
    test_str_is_lower_case();
    test_str_is_upper_case();
    test_str_is_title_case();
}


#endif // __STRING_H__
