/**
 * Useful functions and procedures
 */


#ifndef __FUNC_H__
#define __FUNC_H__


// swap values with respect a type it
#define SWAP(type, a, b) \
{ \
    type temp = a; \
    a = b; \
    b = temp; \
}

// convert to string
#define STR(something) #something

// max between two numbers
#define MAX(a, b) ((a > b) ? a : b)

// min between two numbers
#define MIN(a, b) ((a < b) ? a : b)

// convert two objects to string and concatenation it
#define CONCATENATE(a, b) a ## b

// https://gist.github.com/glejeune/4131931
// http://stackoverflow.com/questions/1772119/the-most-useful-user-made-c-macros-in-gcc-also-c99
// http://stackoverflow.com/questions/400951/does-c-have-a-foreach-loop-construct
// http://stackoverflow.com/questions/34007634/macro-foreach-loop-in-c
// http://stackoverflow.com/questions/5043466/how-evil-is-this-foreach-c-macro
#define FOREACH


#endif // __FUNC_H__
