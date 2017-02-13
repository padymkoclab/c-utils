
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


#define TESTING_PATTERN_SUCCESS "OK: %s (%s, %d)\n"
#define TESTING_PATTERN_SUCCESS_COLOR "OK: \033[1;37;42mOK\033[00m: %s (%s, %d)\n"
#define TESTING_PATTERN_FAIL "FAIL: %s (%s, %d) %s %s %s\n"
#define TESTING_PATTERN_FAIL_COLOR "FAIL: \033[1;37;41mFAILED\033[00m: %s (%s, %d) %s %s %s\n"

#define TEST_OK(func_name, filepath, line_number) \
{ \
    if (TESTING_DISPLAY_ALL == 1) \
        printf( \
            (TESTING_DISPLAY_WITH_COLOR == 1) ? TESTING_PATTERN_SUCCESS_COLOR : TESTING_PATTERN_SUCCESS, \
            func_name, filepath, line_number \
        ); \
}

#define TEST_FAILED(func_name, filepath, line_number, condition, val1, val2) \
{ \
    fprintf( \
        stderr, \
        (TESTING_DISPLAY_WITH_COLOR == 1) ? TESTING_PATTERN_FAIL_COLOR: TESTING_PATTERN_FAIL, \
        func_name, filepath, line_number, #val1, #condition, #val2 \
    ); \
}

#define assertEqual(val1, val2) val1 == val2\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", val1, val2)

#define assertNotEqual(val1, val2) val1 != val2 ? TEST_OK(__func__, __FILE__, __LINE__):\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "==", val1, val2)

#define assertTrue(value) value == true\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", value, true)

#define assertFalse(value) value == false\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", value, false)

#define assertStringEqual(str1, str2) \
{ \
    if (strcmp(str1, str2) == 0) \
        TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        TEST_FAILED(__func__, __FILE__, __LINE__, "!=", str1, str2) \
}

#define assertStringNotEqual(str1, str2) strcmp(str1, str2) == 0\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED(__func__, __FILE__, __LINE__, "==", str1, str2)

#define assertIn()
#define assertNotIn()
#define assertLess()
#define assertLessEqual()
#define assertGreater()
#define assertGreaterEqual()

#endif // __UNITTEST_H__
