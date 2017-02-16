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
random_choice_char(char str[])
{
    size_t len = strlen(str);

    if (len == 0)
        return '\0';

    int index = random_integer(0, len - 1);
    return str[index];
}

char *
random_choice_string(char *strings[], const unsigned int length)
{
    return strings[random_integer(0, length - 1)];
}


#define random_choice_from_array(array, length, value) (*value = array[random_integer(0, length)])


char *
random_string(unsigned int min_length, unsigned int max_length)
{
    if (min_length < 1 || max_length < 1 || min_length > max_length)
        return NULL;

    char *word;
    int word_length;

    word_length = random_integer(min_length, max_length);
    word = malloc(sizeof(char) * word_length);

    for (int i = 0; i < word_length; ++i)
        word[i] = random_choice_char(ASCII_LOWERCASE);

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


// Support only for unix-like systems
// https://www.google.com.ua/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=unix+valid+filename
// http://unix.stackexchange.com/questions/230291/what-characters-are-valid-to-use-in-filenames
// http://stackoverflow.com/questions/457994/what-characters-should-be-restricted-from-a-unix-file-name
// http://web.cse.ohio-state.edu/sce/reference/unix/filenames.html


char *
random_dirpath()
{
    char *path;
    unsigned int value, count_components_of_path;

    path = malloc(200 * sizeof(char));
    value = random_integer(1, 4);

    // is absolute path
    if (value == 1)
        strcat(path, "/");

    // path from current
    else if (value == 2)
        strcat(path, "./");

    // path from parents
    else if (value == 3)
        strcat(path, "../");

    // path from home directory
    else
        strcat(path, "~/");

    // count parts in this path
    count_components_of_path = random_integer(0, 10);

    for (int i = 0; i < count_components_of_path; ++i) {

        // is a hidden folder
        if (random_boolean() == true)
            strcat(path, ".");

        strcat(path, random_string(1, 17));
        strcat(path, "/");
    }

    // randomly add ending "/" to the path if no
    if (random_boolean() == true && path[strlen(path) - 1] != '/')
        strcat(path, "/");

    return path;
}


char *file_extensions[30] = {
    "h", "c", "py", "js", "cpp", "xml", "json",
    "yaml", "hpp", "csv", "css", "jpeg", "txt",
    "rst", "md", "html", "png", "doc", "zip",
    "exe", "pdf", "fb2", "gif", "tar.gz", "deb",
    "java", "mp4", "mp3", "avi", "sh"
};
char *
random_file_extension()
{
    return random_choice_string(file_extensions, 30);
}


char *
random_filepath()
{
    char *path, *extension;
    bool is_hidden, with_extension;

    path = calloc(200, sizeof(char));

    // path to the file
    strcat(path, random_dirpath());

    // is the file is hidden
    is_hidden = random_boolean();
    if (is_hidden == true)
        strcat(path, ".");

    // a filename
    strcat(path, random_string(1, 15));

    // add an extension to the file, if it is not hidden
    if (is_hidden == false) {
        with_extension = random_integer(-1, 10);
        if (with_extension > 0) {
            extension = random_file_extension();
            strcat(path, extension);
        }
    }

    return path;
}


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
    assertEquals(random_float(0.668, 0.668), 0.668f);
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
    random_float_array(array5, 5, -784545.77812145, -784545.77812145);
    for (int i = 0; i < 5; ++i) {
        assertEquals(array5[i], -784545.77812145f);
    }
}


void
test_random_choice_char()
{
    char chr;

    chr = random_choice_char("abcd");
    assertTrue((chr == 'a' || chr == 'b' || chr == 'c' || chr == 'd'));

    chr = random_choice_char("j s o n.h ");
    assertTrue((chr == 'j' || chr == 's' || chr == 'o' || chr == 'n' || chr == '.' || chr == 'h' || chr == ' '));

    assertEquals(random_choice_char("zzzzz"), 'z');
    assertEquals(random_choice_char(" "), ' ');
    assertEquals(random_choice_char(""), '\0');
    assertEquals(random_choice_char("1"), '1');

    chr = random_choice_char("\t\b\n\a\v");
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
test_random_string()
{
    char *word;
    word = calloc(20, sizeof(char));

    assertNull(random_string(0, 10));
    assertNull(random_string(-1, 5));
    assertNull(random_string(-10, -3));
    assertNull(random_string(5, 0));
    assertNull(random_string(0, 0));

    word = random_string(1, 20);
    assertInRange(strlen(word), 1, 20);

    word = random_string(2, 20);
    assertInRange(strlen(word), 2, 20);

    word = random_string(3, 20);
    assertInRange(strlen(word), 3, 20);

    word = random_string(4, 20);
    assertInRange(strlen(word), 4, 20);

    word = random_string(5, 20);
    assertInRange(strlen(word), 5, 20);

    word = random_string(10, 20);
    assertInRange(strlen(word), 10, 20);

    word = random_string(19, 20);
    assertInRange(strlen(word), 19, 20);

    word = random_string(20, 20);
    assertEquals(strlen(word), 20);
}


void
test_random_choice_string()
{
    char *str;

    char *strings1[3] = {
        "math.h", "Simple", "text"
    };
    for (int i = 0; i < 3; ++i) {
        str = random_choice_string(strings1, 3);
        assertInStrings(str, strings1, 3);
    }

    char *strings2[3] = {
        "abc", "abc", "abc"
    };
    for (int i = 0; i < 3; ++i)
        assertStringEquals(random_choice_string(strings2, 3), "abc");

    char *strings3[5] = {
        "\b\tasd\t", "sime", "\tca\'t\t", "c++ is not c", "knowledges is power"
    };
    for (int i = 0; i < 3; ++i) {
        str = random_choice_string(strings3, 5);
        assertInStrings(str, strings3, 5);
    }

    char *strings4[1] = {""};
    for (int i = 0; i < 3; ++i)
        assertStringEquals(random_choice_string(strings4, 1), "");
}


void
test_random_file_extension()
{
    char *ext;

    ext = random_file_extension();
    assertInStrings(ext, file_extensions, 30);

    ext = random_file_extension();
    assertInStrings(ext, file_extensions, 30);

    ext = random_file_extension();
    assertInStrings(ext, file_extensions, 30);

    ext = random_file_extension();
    assertInStrings(ext, file_extensions, 30);
}


void
test_random_dirpath()
{
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
    puts(random_dirpath());
}


void
test_random_filepath()
{
    puts(random_filepath());
}


void
test_random()
{
    srand(time(NULL));

    test_random_integer();
    test_random_float();
    test_random_boolean();
    test_random_int_array();
    test_random_float_array();
    test_random_choice_char();
    test_random_choice_string();
    test_random_choice_from_array();
    test_random_string();
    test_random_file_extension();
    test_random_dirpath();
    test_random_filepath();
}


#endif // __RANDOM_H__
