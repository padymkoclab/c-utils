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

#include "./string.h"
#include "./func.h"

#define ERROR_MIN_MORE_MAX_VALUE "Min value is more max value, returned 0"


/*
    Returns a random integer in between min (inclusive) and max (inclusive)
    Returns 0 if min > max and to write a error message.
 */
static int
random_integer(const int min, const int max) {
    if (max == min) return min;
    else if (min < max) return rand() % (max - min + 1) + min;

    // return 0 if min > max
    errno = EINVAL;
    perror(ERROR_MIN_MORE_MAX_VALUE);
    return 0;
}


/*
    Returns a random integer in between min (inclusive) and max (inclusive).
    Returns 0 if min > max and to write a error message.
 */
static float
random_float(const float min, const float max) {
    if (max == min) return min;
    else if (min < max) return (max - min) * ((float)rand() / RAND_MAX) + min;

    // return 0 if min > max
    errno = EINVAL;
    perror(ERROR_MIN_MORE_MAX_VALUE);
    return 0;
}


/*
    Return boolean: true (1) or false (0)
 */
static bool
random_boolean() {

    return (bool)random_integer(0, 1);
}


/*
    Fills an array with random integer values in a range
 */
static int
random_int_array(int array[], const size_t length, const int min, const int max){
    for (int i = 0; i < length; ++i) {
        array[i] = random_integer(min, max);
    }
    return 0;
}


// http://stackoverflow.com/questions/6127503/shuffle-array-in-c/6127808#6127808
// https://gist.github.com/kgabis/1204145
static int
shuffle_array(void *array, const size_t length) {

    void *temp;

    if (length > 1) {
        int rand_index;
        for (int i = 0; i < length; ++i) {
            rand_index = random_integer(0, length - 1);

            // temp = (&array)[i];
            // (&array)[i] = (&array)[rand_index];
            // (&array)[rand_index] = &(temp);
        }
    }

    return 0;
}


char random_charfromstring(char *str) {
    int index = (rand() % strlen(str));
    return str[index];
}


// Need update
static char*
RandWord(unsigned int min_length, unsigned int max_length, char register_case) {
/*
    if (min_length < 1 || max_length < 1 || min_length > max_length) {
        return false;
    }

    // const char choices_register[5] = "ulct";

    // if (indexOfString(choices_register, register_case) == -1) {
    //     return NULL;
    // };

    if (register_case == 'u' || register_case == 't' || register_case == 'l' || register_case == 'c') {

        char *word;
        int word_length;

        word_length = getRandInt(min_length, max_length);
        word = malloc(sizeof(char) * word_length);

        for (int i = 0; i < word_length; ++i) {
            word[i] = getRandCharFromString(ASCII_LOWERCASE);
        }

        if (register_case == 'u') {
            toUpperCase(word);
        } else if (register_case == 't') {
            toTitleCase(word);
        } else if (register_case == 'c') {
            toCamelCase(word);
        }

        return word;
    }
    return false;
*/
}


/*
    Return
 */
static int
random_filepath() {

    return 0;
}


/*
    Return
 */
static int
random_dirpath() {

    return 0;
}


/*
    Return
 */
static int
random_date() {

    return 0;
}


/*
    Return
 */
static int
random_Time() {

    return 0;
}


/*
    Return
 */
static int
random_Datetime() {

    return 0;
}


/*
    Return
 */
static int
random_Color() {

    return 0;
}


/*
    Return
 */
static int
random_Lorem() {

    return 0;
}


/*
    Return
 */
static int
random_Name() {

    return 0;
}


/*
    Return
 */
static int
random_PhoneNumber()
 {
    return 0;
}


/*
    Return
 */
static int
random_Float() {

    return 0;
}


/*
    Return
 */
static int
random_Double() {

    return 0;
}


/*
    Return
 */
static int
random_Char() {

    return 0;
}


/*
    Return
 */
static int
random_Word() {

    return 0;
}


/*
    Return
 */
static int
random_Sentence() {

    return 0;
}


/*
    Return
 */
static int
random_Text() {

    return 0;
}


/*
    Return
 */
static int
random_Username() {

    return 0;
}


/*
    Return
 */
static int
random_Password() {

    return 0;
}


/*
    Return
 */
static int
random_Email() {

    return 0;
}


/*
    Return
 */
static int
random_Url() {

    return 0;
}


/*
    Return
 */
static int
random_Domain() {

    return 0;
}


/*
    Return
 */
static int
random_CountryCode()
 {
    return 0;
}


/*
    Return
 */
static int
random_CountryName()
 {
    return 0;
}


/*
    Return
 */
static int
random_Weekday() {

    return 0;
}


/*
    Return
 */
static int
random_Month() {

    return 0;
}


/*
    Return
 */
static int
random_Year() {

    return 0;
}


/*
    Return
 */
static int
random_Day() {

    return 0;
}


/*
    Return
 */
static int
random_Timezone() {

    return 0;
}


/*
    Return
 */
static int
random_CurrencyCode(
    ) {
    return 0;
}


/*
    Return
 */
static int
random_CurrencyName(
    ) {
    return 0;
}


/*
    Return
 */
static int
random_Longitude() {

    return 0;
}


/*
    Return
 */
static int
random_Latitude() {

    return 0;
}


/*
    Return
 */
static int
random_Slug() {

    return 0;
}


/*
    Return
 */
static int
random_Image() {

    return 0;
}


/*
    Return
 */
static int
random_City() {

    return 0;
}


/*
    Return
 */
static int
random_ImageURL() {

    return 0;
}


/*
    Return
 */
static int
random_First_name()
{
    return 0;
}


/*
    Return
 */
static int
random_Second_name()
 {
    return 0;
}


/*
    Return
 */
static int
random_FullName() {

    return 0;
}


/*
    Return
 */
static int
random_Ipv4() {

    return 0;
}


/*
    Return
 */
static int
random_Ipv6() {

    return 0;
}


/*
    Return
 */
static int
random_UserAgent() {

    return 0;
}


/*
    Return
 */
static int
random_Profesion() {

    return 0;
}


/*
    Return
 */
static int
random_UUID() {

    return 0;
}


/*
    Return
 */
static int
random_Mimetype() {

    return 0;
}


/*
    Return
 */
static int
random_FileExt() {

    return 0;
}


/*
    Return
 */
static int
random_FileType() {

    return 0;
}


/*
    Return
 */
static int
random_Language() {

    return 0;
}


/*
    Return
 */
static int
random_JSON() {

    return 0;
}


/*
    Return
 */
static int
random_Yaml() {

    return 0;
}


/*
    Return
 */
static int
random_Xml() {

    return 0;
}


/*
    Return
 */
static int
random_Address() {

    return 0;
}


/*
    Return
 */
static int
random_Creadit_card(
    ) {
    return 0;
}


#endif // __RANDOM_H__
