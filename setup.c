
// #include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h> // http://man7.org/linux/man-pages/man3/errno.3.html

// #include <unistd.h>
// #include <sys/utsname.h>

// #include "./utils/path.h"
// #include "./utils/structures/linkedlists/linkedList.h"
// #include "./utils/structures/trees/binary_tree.h"
// #include "./utils/validators.h"
// #include "./utils/string.h"
// #include "./utils/structures/list.h"
#include "./utils/pprint.h"
// #include "./utils/humanize.h"
// #include "./utils/colors.h"
// #include "./utils/csv.h"
// #include "./utils/keywords.h"
// #include "./utils/argsparser.h"
// #include "./utils/system.h"
#include "./utils/array.h"
#include "./utils/func.h"
#include "./utils/random.h"


static int get_version();


int
main (const int argc, const char *argv[])
{

    // http://stackoverflow.com/questions/19462948/c-programming-min-and-max-of-array/

    // http://stackoverflow.com/questions/5750879/transferring-values-from-void-pointer
    // http://stackoverflow.com/questions/27536964/copying-value-of-void-pointer-c
    // http://stackoverflow.com/questions/19581161/c-change-the-value-a-void-pointer-represents
    // http://stackoverflow.com/questions/11044555/problems-changing-a-void-pointer-value-in-c

    int arr[10];
    range_int_array(arr, 0, 10, 1);
    // print_int_array(arr, 10);
    // shuffle_array(&arr, 10);

    int sum = 0;
    putd(sum);
    sum_array(&arr, 10, &sum);
    putd(sum);
    // print_int_array(arr, 10);

    // for (int i = 0; i < argc; ++i) {
    //     puts(argv[i]);
    // }

    float arr1[] = {1.12, -43, 54, 0};
    // putd(max_int_array(arr, 10));
    // putd(min_int_array(arr1, 10));

    // char version[10];
    // get_version(version);



    return 0;
}



/*
    Getting version project and keep it in a buffer
    Return 0, if no error, otherwise - non-zero value.

    char version[10];
    get_version(version);
 */
int
get_version(char buffer[])
{
    static const char filename[] = "./version.txt";
    FILE *file = NULL;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        return -1;
    }

    fgets(buffer, 100, file);
    fclose(file);

    return 0;
}
