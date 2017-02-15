/**
 * Generation a fake data and other things with related to randomness
 *
 * Before using this header, make sure that is ready:
 *
 *     srand(time(NULL));
 *
 */

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>


#include "./str.h"
#include "./func.h"
#include "./testing/unittest.h"


#define RANDOM_ERROR "RandomError"
#define RANDOM_ERROR_MIN_MORE_MAX "Min value is more max value, returned 0"


int
random_integer(const int min, const int max)
{
    if (max == min)
        return min;
    return rand() % (max - min + 1) + min;
}



float
random_float(const float min, const float max)
{
    if (max == min)
        return min;
    return (max - min) * ((float)rand() / RAND_MAX) + min;
}


bool
random_boolean()
{
    return random_integer(0, 1);
}


void
random_int_array(int array[], const unsigned int length, const int min, const int max)
{
    for (int i = 0; i < length; ++i)
        array[i] = random_integer(min, max);
}


void
random_float_array(float array[], const unsigned int length, const float min, const float max)
{
    for (int i = 0; i < length; ++i)
        array[i] = random_float(min, max);
}


char
random_choice_from_str(char str[])
{
    size_t len = strlen(str);

    if (len == 0)
        return '\0';

    int index = random_integer(0, len - 1);
    return str[index];
}


#define random_choice_from_array(array, length, value) (*value = array[random_integer(0, length)])


char *
random_word(unsigned int min_length, unsigned int max_length)
{
    if (min_length < 1 || max_length < 1 || min_length > max_length)
        return NULL;

    char *word;
    int word_length;

    word_length = random_integer(min_length, max_length);
    word = malloc(sizeof(char) * word_length);

    for (int i = 0; i < word_length; ++i)
        word[i] = random_choice_from_str(ASCII_LOWERCASE);

    return word;
}


// http://stackoverflow.com/questions/6127503/shuffle-array-in-c/6127808#6127808
// https://gist.github.com/kgabis/1204145
int
random_shuffle_array(void *array, const size_t length)
{
    void *temp;

    if (length > 1) {
        int rand_index;
        for (int i = 0; i < length; ++i) {
            rand_index = random_integer(0, length - 1);

            temp = (&array)[i];
            (&array)[i] = (&array)[rand_index];
            (&array)[rand_index] = &(temp);
        }
    }

    return 0;
}


// random_sample_array(array, length, count)


char
random_charfromstring(char *str)
{
    int index = (rand() % strlen(str));
    return str[index];
}


// random_filepath
// random_dirpath
// random_date
// random_time
// random_datetime
// random_color
// random_lorem
// random_name
// random_phonenumber
// random_sentence
// random_text
// random_username
// random_password
// random_email
// random_url
// random_domain
// random_countrycode
// random_countryname
// random_weekday
// random_month
// random_year
// random_day
// random_timezone
// random_currencycod
// random_currencynam
// random_longitude
// random_latitude
// random_slug
// random_image
// random_city
// random_imageurl
// random_first_name
// random_second_name
// random_fullname
// random_ipv4
// random_ipv6
// random_useragent
// random_profesion
// random_uuid
// random_mimetype
// random_fileext
// random_filetype
// random_language
// random_json
// random_yaml
// random_xml
// random_address
// random_creadit_card

/**
 * Tests
 */


void
test_random_integer()
{
    assertInRange(random_integer(1, 10), 1, 10);
    assertInRange(random_integer(-10000, 100000), -10000, 100000);
    assertEquals(random_integer(-100, -100), -100);
    assertInRange(random_integer(-1, 0), -1, 0);
}


void
test_random_float()
{
    assertInRange(random_float(1, 10), 1, 10);
    assertInRange(random_float(-100000, 100000), -100000, 100000);
    assertInRange(random_float(-1, 1), -1, 1);
    assertInRange(random_float(-0.5, -0.25), -0.5, -0.25);
    assertEquals(random_float(0.668, 0.668), 0.668);
    assertInRange(random_float(-0.0007, -0.0006), -0.0007, -0.0006);
}


void
test_random_boolean()
{
    bool value;

    value = random_boolean();
    assertTrue((value == false || value == true));
    assertInRange(random_boolean(), 0, 1);
}


void
test_random_int_array()
{
    int array1[5];
    random_int_array(array1, 5, 1, 100);
    for (int i = 0; i < 5; ++i)
        assertInRange(array1[i], 1, 100);

    int array2[1];
    random_int_array(array2, 1, -1000, 1000);
    assertInRange(array2[0], -1000, 1000);

    int array3[100];
    random_int_array(array3, 100, -100000, 100000);
    for (int i = 0; i < 100; ++i)
        assertInRange(array3[i], -100000, 100000);

    int array4[10];
    random_int_array(array4, 10, -1, 1);
    for (int i = 0; i < 10; ++i)
        assertInRange(array4[i], -1, 1);

    int array5[10];
    random_int_array(array5, 10, 100, 100);
    for (int i = 0; i < 5; ++i)
        assertEquals(array5[i], 100);
}



void
test_random_float_array()
{
    float array1[10];
    random_float_array(array1, 10, -1.75, 1.15);
    for (int i = 0; i < 10; ++i)
        assertInRange(array1[i], -1.75, 1.15);

    float array2[17];
    random_float_array(array2, 17, -1121.4141, 3412.121);
    for (int i = 0; i < 17; ++i)
        assertInRange(array2[i], -1121.4141, 3412.121);

    float array3[100];
    random_float_array(array3, 100, -100000, 100000);
    for (int i = 0; i < 100; ++i)
        assertInRange(array3[i], -100000, 100000);

    float array4[1];
    random_float_array(array4, 1, -0.1, 0.1);
    assertInRange(array4[0], -0.1, 0.1);

    float array5[5];
    random_float_array(array5, 5, -78974.7, -78974.7);
    for (int i = 0; i < 5; ++i)
        // printf("%f\n", array5[i]);
        assertEquals(array5[i], -78974.787);
}


void
test_random_choice_from_str()
{
    char chr;

    chr = random_choice_from_str("abcd");
    assertTrue((chr == 'a' || chr == 'b' || chr == 'c' || chr == 'd'));

    chr = random_choice_from_str("j s o n.h ");
    assertTrue((chr == 'j' || chr == 's' || chr == 'o' || chr == 'n' || chr == '.' || chr == 'h' || chr == ' '));

    assertEquals(random_choice_from_str("zzzzz"), 'z');
    assertEquals(random_choice_from_str(" "), ' ');
    assertEquals(random_choice_from_str(""), '\0');
    assertEquals(random_choice_from_str("1"), '1');

    chr = random_choice_from_str("\t\b\n\a\v");
    assertTrue((chr == '\t' || chr == '\b' || chr == '\n' || chr == '\a' || chr == '\v'));
}


void
test_random_choice_from_array()
{

    float arr[5], value;
    random_float_array(arr, 5, -1.5, 5.25);
    random_choice_from_array(arr, 5, &value);
    // printf("%f\n", value);
}


void
test_random_word()
{
    char *word;
    word = calloc(20, sizeof(char));

    assertNull(random_word(0, 10));
    assertNull(random_word(-1, 5));
    assertNull(random_word(-10, -3));
    assertNull(random_word(5, 0));
    assertNull(random_word(0, 0));

    word = random_word(1, 20);
    assertInRange(strlen(word), 1, 20);

    word = random_word(2, 20);
    assertInRange(strlen(word), 2, 20);

    word = random_word(3, 20);
    assertInRange(strlen(word), 3, 20);

    word = random_word(4, 20);
    assertInRange(strlen(word), 4, 20);

    word = random_word(5, 20);
    assertInRange(strlen(word), 5, 20);

    word = random_word(10, 20);
    assertInRange(strlen(word), 10, 20);

    word = random_word(19, 20);
    assertInRange(strlen(word), 19, 20);

    word = random_word(20, 20);
    assertEquals(strlen(word), 20);

}


void
test_random()
{
    srand(time(NULL));

    test_random_integer();
    // test_random_float();
    test_random_boolean();
    test_random_int_array();
    // test_random_float_array();
    test_random_choice_from_str();
    test_random_choice_from_array();
    test_random_word();

}


#endif // __RANDOM_H__
