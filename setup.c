
// #include <string.h>
// #include <stdio.h>
#include <stdlib.h>
// #include <time.h>
// #include <errno.h> // http://man7.org/linux/man-pages/man3/errno.3.html

// #include <unistd.h>
// #include <sys/utsname.h>

// #include "./utils/path.h"
// #include "./utils/structures/linkedlists/linkedList.h"
// #include "./utils/structures/trees/binary_search_tree.h"
// #include "./utils/structures/trees/tree.h"
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
// #include "./utils/array.h"
// #include "./utils/func.h"
// #include "./utils/random.h"

// http://stackoverflow.com/questions/4538425/getting-localised-string/4750892#4750892
// http://fedoraproject.org/wiki/How_to_do_I18N_through_gettext
// https://en.wikipedia.org/wiki/Gettext


static int get_version();


int
main(const int argc, const char *argv[])
{
    // http://man7.org/linux/man-pages/man3/setlocale.3.html
    // https://www.tutorialspoint.com/c_standard_library/locale_h.htm
    // https://www.linux.com/news/controlling-your-locale-environment-variables
    // https://www.gnu.org/software/libc/manual/html_node/Setting-the-Locale.html

    // printf("LC_ALL\t%d\n", LC_ALL); //             All of the locale
    // printf("LC_ADDRESS\t%d\n", LC_ADDRESS); //         Formatting of addresses and geography-related items (*)
    // printf("LC_COLLATE\t%d\n", LC_COLLATE); //         String collation
    // printf("LC_CTYPE\t%d\n", LC_CTYPE); //           Character classification
    // printf("LC_IDENTIFICATION\t%d\n", LC_IDENTIFICATION); //  Metadata describing the locale (*)
    // printf("LC_MEASUREMENT\t%d\n", LC_MEASUREMENT); //     Settings related to measurements (metric versus US customary) (*)
    // printf("LC_MESSAGES\t%d\n", LC_MESSAGES); //        Localizable natural-language messages
    // printf("LC_MONETARY\t%d\n", LC_MONETARY); //        Formatting of monetary values
    // printf("LC_NAME\t%d\n", LC_NAME); //            Formatting of salutations for persons (*)
    // printf("LC_NUMERIC\t%d\n", LC_NUMERIC); //         Formatting of nonmonetary numeric values
    // printf("LC_PAPER\t%d\n", LC_PAPER); //           Settings related to the standard paper size (*)
    // printf("LC_TELEPHONE\t%d\n", LC_TELEPHONE); //       Formats to be used with telephone services (*)
    // printf("LC_TIME\t%d\n", LC_TIME); //            Formatting of date and time values

    // struct lconv loc;

    // printf("%s\n", loc.decimal_point);
    // printf("%s\n", loc.thousands_sep);
    // printf("%d\n", loc.int_curr_symbol);

    // setlocale(LC_ALL, "");
    // wprintf(L"%ls\n", L"\x01060\x100");

    // int i = 1100;
    // while (i < 1110) {
    //     printf("%c ", i);
    //     ++i;
    // }
    // puts("");


    // for (int i = 0; i < argc; ++i) puts(argv[i]);

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
