
#ifndef __PRETTY_PRINT__
#define __PRETTY_PRINT__

#include <stdio.h>


void printIntArray(int array[], size_t length, char *ending_charapter) {
    for (int i = 0; i < length; ++i) {
        printf("%d%s", array[i], ending_charapter);
    }
    puts("");
}


#endif // __PRETTY_PRINT__
