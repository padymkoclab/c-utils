
#ifndef __TESTS_H__
#define __TESTS_H__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#define TEST_OK(func_name, filepath, line_number)\
    printf("\033[1;37;42mOK\033[00m: %s (%s, %d) \n", func_name, filepath, line_number)
#define TEST_FAILED(func_name, filepath, line_number, condition, val1, val2)\
    fprintf(stderr, "\033[1;37;41mFAILED\033[00m: %s (%s, %d) %s %s %s\n", func_name, filepath, line_number, #val1, #condition, #val2)

#define assertEqual(val1, val2) val1 == val2\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", val1, val2)
#define assertNotEqual(val1, val2) val1 != val2 ? TEST_OK(__func__, __FILE__, __LINE__):\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "==", val1, val2)
#define assertTrue(value) value == true\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", value, true)
#define assertFalse(value) value == false\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED( __func__, __FILE__, __LINE__, "!=", value, false)
#define assertStringEqual(str1, str2) strcmp(str1, str2) == 0\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED(__func__, __FILE__, __LINE__, "!=", str1, str2)
#define assertStringNotEqual(str1, str2) strcmp(str1, str2) == 0\
    ? TEST_OK(__func__, __FILE__, __LINE__): TEST_FAILED(__func__, __FILE__, __LINE__, "==", str1, str2)
#define assertIn()
#define assertNotIn()
#define assertLess()
#define assertLessEqual()
#define assertGreater()
#define assertGreaterEqual()

#endif // __TESTS_H__
