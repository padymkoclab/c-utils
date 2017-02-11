/**
 * Testruner for run tests
 * This is an simple example of using py.test as a testrunner for C unit tests.
 * Collects the C unit test files, executes them, captures the output and displays it.
 *
 * https://github.com/ennorehling/cutest
 * https://github.com/mity/cutest
 */


#include <stdlib.h>
#include <stdio.h>

#include "../argparser.h"


int main(int argc, char *argv[]) {

    // for ()
    printf("%d\n", argc);
    // puts(argv[0]);
    return EXIT_SUCCESS;
}
