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



/**
 * Extracts a selection of string and return a new string or NULL.
 * It supports both negative and positive indexes.
 */
char *
str_slice(char str[], int slice_from, int slice_to)
{
    // if a string is empty, returns nothing
    if (str[0] == '\0')
        return NULL;

    char *buffer;
    size_t str_len, buffer_len;

    // for negative indexes "slice_from" must be less "slice_to"
    if (slice_to < 0 && slice_from < slice_to) {
        str_len = strlen(str);

        // if "slice_to" goes beyond permissible limits
        if (abs(slice_to) > str_len - 1)
            return NULL;

        // if "slice_from" goes beyond permissible limits
        if (abs(slice_from) > str_len)
            slice_from = (-1) * str_len;

        buffer_len = slice_to - slice_from;
        str += (str_len + slice_from);

    // for positive indexes "slice_from" must be more "slice_to"
    } else if (slice_from >= 0 && slice_to > slice_from) {
        str_len = strlen(str);

        // if "slice_from" goes beyond permissible limits
        if (slice_from > str_len - 1)
            return NULL;

        buffer_len = slice_to - slice_from;
        str += slice_from;

    // otherwise, returns NULL
    } else
        return NULL;

    buffer = calloc(buffer_len, sizeof(char));
    strncpy(buffer, str, buffer_len);
    return buffer;
}


// http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
// http://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array
// http://stackoverflow.com/questions/4513316/split-string-in-c-every-white-space
char **
str_split(char *string, char *delimiter, unsigned int *length)
{
    char **result;

    *length = 1;
    result = malloc(sizeof(char) * (*length));

    // if the string is empty - return an array with a single empty string
    if (*string == '\0') {
        result[0] = malloc(sizeof(char) * (*length));
        strcpy(result[0], "");
        return result;
    }

    // char *str;
    char *rest_str;
    unsigned int string_len;
    size_t delimiter_len = strlen(delimiter);

    // for the empty delimiter length must be 1
    if (delimiter_len == 0)
        ++delimiter_len;


    printf("\"%s\": \"%s\"\n--------------------------------\n", string, delimiter);

    while (*string != '\0') {
        result = realloc(result, sizeof(char) * (*length));

        rest_str = strstr(string, delimiter);
        printf("%s --> %s\n", string, rest_str);

        if (rest_str == '\0') {
            printf("---\"%s\"-----", string);
            break;
        }

        string_len = strlen(string) - strlen(rest_str);
        string = malloc(sizeof(char) * string_len);
        strncpy(string, string, string_len);
        // printf("\"%s\" | ", string);
        string = rest_str + delimiter_len;
        ++(*length);
    }
    puts("");

    return result;
};


int
str_index(const char *str, const char *substr)
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




// http://stackoverflow.com/questions/7775138/strip-whitespace-from-a-string-in-place
// http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
char *
str_trim(char str[])
{
    char *buffer;

    char *str_end = str + strlen(str) - 1;

    while (isspace(*str)) ++str;

    while (isspace(*str_end)) --str_end;

    size_t len = strlen(str) - strlen(str_end) + 1;

    buffer =calloc(len, sizeof(char));
    strncpy(buffer, str, len);

    return buffer;
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


char *
str_escape(char str[])
{
    char chr[3];
    char *buffer = malloc(sizeof(char));
    unsigned int len = 0, blk_size;

    while (*str != '\0') {
        blk_size = 2;
        switch (*str) {
            case '\n':
                strcpy(chr, "\\n");
                break;
            case '\t':
                strcpy(chr, "\\t");
                break;
            case '\v':
                strcpy(chr, "\\v");
                break;
            case '\f':
                strcpy(chr, "\\f");
                break;
            case '\a':
                strcpy(chr, "\\a");
                break;
            case '\b':
                strcpy(chr, "\\b");
                break;
            case '\r':
                strcpy(chr, "\\r");
                break;
            default:
                sprintf(chr, "%c", *str);
                blk_size = 1;
                break;
        }
        len += blk_size;
        buffer = realloc(buffer, len * sizeof(char));
        strcat(buffer, chr);
        ++str;
    }
    return buffer;
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


int
str_prepend(char string[], char prefix[])
{
    size_t prefix_len = strlen(prefix);
    size_t string_len = strlen(string);

    memmove(string + prefix_len, string, string_len);

    for (int i = 0; i < prefix_len; ++i)
        string[i] = prefix[i];

    return 0;
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


// Try regex
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
test_str_split()
{
    // char **strings;
    unsigned int length;

    // char str1[] = "/.fas/.dire/.fixk/.saios//";
    // str_split(str1, "/", &length);
    // str_split(str1, ".", &length);
    // str_split(str1, "/.", &length);
    // str_split(str1, "/.f", &length);
    // str_split(str1, "i", &length);
    // str_split(str1, "**", &length);

    // char str2[] = "/aaa/bb/c/";
    // str_split(str2, "/", &length);

    // char str3[] = "home";
    // strings = str_split(str3, " ", &length);
    // puts(strings[0]);
    // assertStringEquals(strings[0], "home");

    // char str4[] = "";
    // str_split(str4, "", &length);
    // putd(length);

    char str5[] = " a simon!";
    str_split(str5, "", &length);
    putd(length);

    // char str6[] = " a single line ";
    // str_split(str6, " ", &length);

    // char str7[] = "!! the !!";
    // str_split(str7, "!", &length);

    // char str8[] = "1243424234";
    // str_split(str8, "a", &length);

    // char str9[] = "123456789";
    // str_split(str9, "9", &length);

    // char str10[] = "";
    // str_split(str10, " ", &length);
    // putd(length);
}

void
test_str_slice()
{
    char str[] = "abcdefghijkl";

    assertNull(str_slice(str, -3, -10));
    assertNull(str_slice(str, -1, -2));
    assertNull(str_slice(str, -1, 0));
    assertNull(str_slice(str, 1, 0));
    assertNull(str_slice(str, 5, 4));
    assertNull(str_slice(str, 0, 0));
    assertNull(str_slice(str, 10, 10));
    assertNull(str_slice(str, -2, -2));
    assertNull(str_slice(str, -20, -12));
    assertNull(str_slice(str, -20, -13));
    assertNull(str_slice(str, 12, 13));
    assertNull(str_slice(str, 12, 20));
    assertNull(str_slice("", 1, 2));
    assertNull(str_slice("", -2, -1));

    assertStringEquals(str_slice(str, -3, -1), "jk");
    assertStringEquals(str_slice(str, -8, -3), "efghi");
    assertStringEquals(str_slice(str, -10, -9), "c");
    assertStringEquals(str_slice(str, -2, -1), "k");
    assertStringEquals(str_slice(str, -15, -1), "abcdefghijk");
    assertStringEquals(str_slice(str, -12, -2), "abcdefghij");
    assertStringEquals(str_slice(str, -15, -8), "abcd");
    assertStringEquals(str_slice(str, -15, -11), "a");

    assertStringEquals(str_slice(str, 1, 3), "bc");
    assertStringEquals(str_slice(str, 11, 100), "l");
    assertStringEquals(str_slice(str, 2, 4), "cd");
    assertStringEquals(str_slice(str, 3, 6), "def");
    assertStringEquals(str_slice(str, 0, 1), "a");
    assertStringEquals(str_slice(str, 4, 6), "ef");
    assertStringEquals(str_slice(str, 1, 2), "b");
    assertStringEquals(str_slice(str, 0, 3), "abc");
    assertStringEquals(str_slice(str, 0, 11), "abcdefghijk");
    assertStringEquals(str_slice(str, 2, 10), "cdefghij");
    assertStringEquals(str_slice(str, 0, 50), "abcdefghijkl");
}


void
test_str_prepend()
{
    char *buffer;
    buffer = malloc(sizeof(buffer) * 200);

    str_prepend(buffer, "");
    assertStringEquals(buffer, "");
    str_prepend(buffer, "1");
    assertStringEquals(buffer, "1");
    str_prepend(buffer, "text ");
    assertStringEquals(buffer, "text 1");
    str_prepend(buffer, "\tI prepended some text before\n");
    assertStringEquals(buffer, "\tI prepended some text before\ntext 1");
}



void
test_str_escape()
{
    assertStringEquals(str_escape("\tAnbms\n"), "\\tAnbms\\n");
    assertStringEquals(str_escape("\tA\v\fZ\a"), "\\tA\\v\\fZ\\a");
    assertStringEquals(str_escape("txt \t\n\r\f\a\v 1 \t\n\r\f\a\v tt"), "txt \\t\\n\\r\\f\\a\\v 1 \\t\\n\\r\\f\\a\\v tt");
    assertStringEquals(str_escape("dhsjdsdjhs hjd hjds "), "dhsjdsdjhs hjd hjds ");
    assertStringEquals(str_escape(""), "");
    assertStringEquals(str_escape("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n\r\f\a\v"), "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \\t\\n\\r\\f\\a\\v");
    assertStringEquals(str_escape("\x0b\x0c\t\n\r\f\a\v"), "\\v\\f\\t\\n\\r\\f\\a\\v");
    assertStringEquals(str_escape("\x01\x02\x03\x04\x05\x06\x07\x08\t\n\x0b\x0c\r\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x00"), "\x01\x02\x03\x04\x05\x06\\a\\b\\t\\n\\v\\f\\r\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x00");
}


void
test_str_trim()
{

    char *data[16] = {
        "  simple text  ",
        "  simple text",
        "simple text",
        " text ",
        " ",
        "",
        "\n\t\v",
        "",
        " simple text",
        "Remember good   ",
        "    By center   ",
        " \t\n\r\b\a\v By center \t\n\r\b\a\v ",
        "    ",
        "\t\n\r\b\a\v",
        " \t\n\r\b\a\v simple text ",
        "Remember good  \t\n\r\b\a\v ",
    };

    for (int i = 0; i < 10; ++i) {
        printf("\"%s\" --> \"%s\"\n", data[i], str_trim(data[i]));
    }
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
    // test_str_is_title_case();

    // test_str_split();

    test_str_slice();
    test_str_prepend();

    // test_str_trim();
    test_str_escape();
}


#endif // __STRING_H__
