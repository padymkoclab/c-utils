
#ifndef __ASSERT_H__
#define __ASSERT_H__


#define assertEquals(value1, value2) \
{ \
    if (value1 == value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "!=", value1, value2) \
}

#define assertNotEquals(value1, value2) \
{ \
    if (value1 != value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "==", value1, value2) \
}

#define assertLess(value1, value2) \
{ \
    if (value1 < value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, ">=", value1, value2) \
}

#define assertLessEquals(value1, value2) \
{ \
    if (value1 <= value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, ">", value1, value2) \
}

#define assertGreater(value1, value2) \
{ \
    if (value1 > value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, "<=", value1, value2) \
}

#define assertGreaterEquals(value1, value2) \
{ \
    if (value1 >= value2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, "<", value1, value2) \
}

#define assertTrue(value) \
{ \
    if (value == true) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "is not", value, true) \
}

#define assertFalse(value) \
{ \
    if (value == false) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "is not", value, false) \
}


#define assertInRange(value, min, max) \
{\
    if (min <= value && value <= max) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "is not in range from", value, min to max) \
}

#define assertNull(value) \
{ \
    if (value == NULL) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "is not", value1, false) \
}

#define assertNotNull(value) \
{ \
    if (value != NULL) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL( __func__, __FILE__, __LINE__, "is", value1, false) \
}

#define assertStringEquals(str1, str2) \
{ \
    if (strcmp(str1, str2) == 0) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        printf("%s (%s %d): \"%s\" != \"%s\"\n", __func__, __FILE__, __LINE__, str1, str2); \
}

#define assertStringNotEquals(str1, str2) \
{ \
    if (strcmp(str1, str2) != 0) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        printf("%s (%s %d): \"%s\" == \"%s\"\n", __func__, __FILE__, __LINE__, str1, str2); \
}

#define assertStringContaints(str, substr) \
{ \
    if (strstr(str, substr) != NULL) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, "constains not", str, substr) \
}

#define assertStringNotContaints(str, substr) \
{ \
    if (strstr(str, substr) == NULL) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_FAIL(__func__, __FILE__, __LINE__, "constains", str, substr) \
}


// Does not work
#define assertArrayEquals(array1, array2, length) \
{ \
    if (array1 == array2) \
        PRINT_TEST_OK(__func__, __FILE__, __LINE__) \
    else \
        PRINT_TEST_ARRAY_FAIL(__func__, __FILE__, __LINE__, "!=", array1, array2, length) \
}

#define assertArrayNotEquals
#define assertInArray
#define assertNotInArray


#endif // __ASSERT_H__
