
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/utsname.h>

// #include "./utils/path.h"
// #include "./utils/structures/linkedlists/linkedList.h"
// #include "./utils/structures/trees/binary_tree.h"
// #include "./utils/validators.h"
// #include "./utils/string.h"
// #include "./utils/structures/list.h"
#include "./utils/pprint.h"
// #include "./utils/humanize.h"
// #include "./utils/faker.h"
// #include "./utils/colors.h"
// #include "./utils/csv.h"
// #include "./utils/keywords.h"
// #include "./utils/argsparser.h"
#include "./utils/system.h"


static int get_version();


int
main (const int argc, const char *argv[])
{

    for (int i = 0; i < argc; ++i) {
        puts(argv[i]);
    }


    char version[10];
    get_version(version);
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
