/**
 * Generation fake data for the C programing language
 */


/*

    initFaker();
    int arr[5];
    Faker.fillIntArray(arr, 5);
    printIntArray(arr, 5, " ");
    putd(Faker.choiceInt(arr, 5));

 */

#ifndef __FAKER_H__
#define __FAKER_H__

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*
    Return a random integer in range
 */
static int
_FakeInt(const int min, const int max) {
    if (max == min) return min;
    else if (min < max) return rand() % (max - min) + min;
    return 0;
}


/*
    Return a random integer item of an array
 */
static int
_FakeChoiceInt(const int *array, const unsigned int size) {
    if (size == 0) return 0;
    return array[_FakeInt(0, size)];
}


/*
    Fill up an array random integer values
 */
static int
_FakeFillIntArray(int *array, unsigned int size) {
    while (size > 0) {
        size--;
        array[size] = _FakeInt(-1000, 1000);
    }
    return 0;
}


/*
    Return
 */
static int
_FakeFilepath() {

    return 0;
}


/*
    Return
 */
static int
_FakeDirpath() {

    return 0;
}


/*
    Return boolean: true or false
 */
static bool
_FakeBoolean() {
    return (_FakeInt(0, 2) == 0) ? false : true;
}


/*
    Return
 */
static int
_FakeDate() {

    return 0;
}


/*
    Return
 */
static int
_FakeTime() {

    return 0;
}


/*
    Return
 */
static int
_FakeDatetime() {

    return 0;
}


/*
    Return
 */
static int
_FakeColor() {

    return 0;
}


/*
    Return
 */
static int
_FakeLorem() {

    return 0;
}


/*
    Return
 */
static int
_FakeName() {

    return 0;
}


/*
    Return
 */
static int
_FakePhoneNumber()
 {
    return 0;
}


/*
    Return
 */
static int
_FakeFloat() {

    return 0;
}


/*
    Return
 */
static int
_FakeDouble() {

    return 0;
}


/*
    Return
 */
static int
_FakeChar() {

    return 0;
}


/*
    Return
 */
static int
_FakeWord() {

    return 0;
}


/*
    Return
 */
static int
_FakeSentence() {

    return 0;
}


/*
    Return
 */
static int
_FakeText() {

    return 0;
}


/*
    Return
 */
static int
_FakeUsername() {

    return 0;
}


/*
    Return
 */
static int
_FakePassword() {

    return 0;
}


/*
    Return
 */
static int
_FakeEmail() {

    return 0;
}


/*
    Return
 */
static int
_FakeUrl() {

    return 0;
}


/*
    Return
 */
static int
_FakeDomain() {

    return 0;
}


/*
    Return
 */
static int
_FakeCountryCode()
 {
    return 0;
}


/*
    Return
 */
static int
_FakeCountryName()
 {
    return 0;
}


/*
    Return
 */
static int
_FakeWeekday() {

    return 0;
}


/*
    Return
 */
static int
_FakeMonth() {

    return 0;
}


/*
    Return
 */
static int
_FakeYear() {

    return 0;
}


/*
    Return
 */
static int
_FakeDay() {

    return 0;
}


/*
    Return
 */
static int
_FakeTimezone() {

    return 0;
}


/*
    Return
 */
static int
_FakeCurrencyCode(
    ) {
    return 0;
}


/*
    Return
 */
static int
_FakeCurrencyName(
    ) {
    return 0;
}


/*
    Return
 */
static int
_FakeLongitude() {

    return 0;
}


/*
    Return
 */
static int
_FakeLatitude() {

    return 0;
}


/*
    Return
 */
static int
_FakeSlug() {

    return 0;
}


/*
    Return
 */
static int
_FakeImage() {

    return 0;
}


/*
    Return
 */
static int
_FakeCity() {

    return 0;
}


/*
    Return
 */
static int
_FakeImageURL() {

    return 0;
}


/*
    Return
 */
static int
_FakeFirst_name()
{
    return 0;
}


/*
    Return
 */
static int
_FakeSecond_name()
 {
    return 0;
}


/*
    Return
 */
static int
_FakeFullName() {

    return 0;
}


/*
    Return
 */
static int
_FakeIpv4() {

    return 0;
}


/*
    Return
 */
static int
_FakeIpv6() {

    return 0;
}


/*
    Return
 */
static int
_FakeUserAgent() {

    return 0;
}


/*
    Return
 */
static int
_FakeProfesion() {

    return 0;
}


/*
    Return
 */
static int
_FakeUUID() {

    return 0;
}


/*
    Return
 */
static int
_FakeMimetype() {

    return 0;
}


/*
    Return
 */
static int
_FakeFileExt() {

    return 0;
}


/*
    Return
 */
static int
_FakeFileType() {

    return 0;
}


/*
    Return
 */
static int
_FakeLanguage() {

    return 0;
}


/*
    Return
 */
static int
_FakeJSON() {

    return 0;
}


/*
    Return
 */
static int
_FakeYaml() {

    return 0;
}


/*
    Return
 */
static int
_FakeXml() {

    return 0;
}


/*
    Return
 */
static int
_FakeAddress() {

    return 0;
}


/*
    Return
 */
static int
_FakeCreadit_card(
    ) {
    return 0;
}


struct {
    int (*intNumber)(const int min, const int max);
    int (*choiceInt)(const int *array, const unsigned int size);
    int (*fillIntArray)(int *array, unsigned int size);
    bool (*boolean)();
} Faker;


/*
    Initialization a faker object.
    Binding needed function to the object.
 */
static int
initFaker() {

    time_t time_;

    srand((unsigned int)time(&time_));

    Faker.intNumber = &_FakeInt;
    Faker.choiceInt = &_FakeChoiceInt;
    Faker.fillIntArray = &_FakeFillIntArray;
    Faker.boolean = &_FakeBoolean;

    return 0;
}


#endif // __FAKER_H__
