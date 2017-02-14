/**
 *
 * https://github.com/antirez/redis/blob/27e29f4fe61d822eb23d948bcb72db76c4c887e5/deps/jemalloc/test/include/test/test.h
 *
 */


#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#ifdef TESTING_DISPLAY_WITH_COLOR
    #undef TESTING_DISPLAY_WITH_COLOR
    #define TESTING_DISPLAY_WITH_COLOR 1
#else
    #define TESTING_DISPLAY_WITH_COLOR 0
#endif


#ifdef TESTING_DISPLAY_ALL
    #undef TESTING_DISPLAY_ALL
    #define TESTING_DISPLAY_ALL 1
#else
    #define TESTING_DISPLAY_ALL 0
#endif


#define TESTING_PATTERN_FAIL_BASIC "FAIL: %s (%s, %d)"


#define TESTING_PATTERN_SUCCESS "OK: %s (%s, %d)\n"
#define TESTING_PATTERN_SUCCESS_COLOR "\033[1;37;42mOK\033[00m: %s (%s, %d)\n"
#define TESTING_PATTERN_FAIL "FAIL: %s (%s, %d) %s %s %s\n"
#define TESTING_PATTERN_FAIL_COLOR "\033[1;37;41mFAIL\033[00m: %s (%s, %d) %s %s %s\n"


#define PRINT_TEST_OK(func_name, filepath, line_number) \
{ \
    if (TESTING_DISPLAY_ALL == 1) \
        printf( \
            (TESTING_DISPLAY_WITH_COLOR == 1) ? TESTING_PATTERN_SUCCESS_COLOR : TESTING_PATTERN_SUCCESS, \
            func_name, filepath, line_number \
        ); \
}

#define PRINT_TEST_FAIL(func_name, filepath, line_number, condition, value1, value2) \
{ \
    fprintf( \
        stderr, \
        (TESTING_DISPLAY_WITH_COLOR == 1) ? TESTING_PATTERN_FAIL_COLOR: TESTING_PATTERN_FAIL, \
        func_name, filepath, line_number, #value1, condition, #value2 \
    ); \
}


// Does not work
#define PRINT_TEST_ARRAY_FAIL(func_name, filepath, line_number, condition, array1, array2, length) \
{ \
    fprintf( \
        stderr, \
        (TESTING_DISPLAY_WITH_COLOR == 1) ? TESTING_PATTERN_FAIL_BASIC: TESTING_PATTERN_FAIL_BASIC, \
        func_name, filepath, line_number \
    ); \
    for (int i = 0; i < length; ++i) { \
        printf("%s", array1[i]);\
    } \
    puts(""); \
}


#include "assert.c"


#endif // __UNITTEST_H__
