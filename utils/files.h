/**
 *
 */


#ifndef __FILES_H__
#define __FILES_H__

#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif //_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "./prettyPrint.h"

#ifndef ESCAPED_CHARS
    #define ESCAPED_CHARS "\a\b\f\n\r\t\v\\\?\'\"\0"
#endif


int escapeString(char *str) {

    const size_t str_len = strlen(str);

    char *buffer;
    buffer = malloc(2 * str_len * sizeof(char) + 1);

    int i = 0;

    char escapedChr[3];

    while (i < str_len) {
        if (strchr(ESCAPED_CHARS, str[i]) != 0) {
            switch (str[i]) {
                case '\a':
                    strcpy(escapedChr, "\\a");
                    break;
                case '\b':
                    strcpy(escapedChr, "\\b");
                    break;
                case '\f':
                    strcpy(escapedChr, "\\f");
                    break;
                case '\n':
                    strcpy(escapedChr, "\\n");
                    break;
                case '\t':
                    strcpy(escapedChr, "\\t");
                    break;
                case '\r':
                    strcpy(escapedChr, "\\r");
                    break;
                case '\v':
                    strcpy(escapedChr, "\\v");
                    break;
                case '\"':
                    strcpy(escapedChr, "\"");
                    break;
                case '\'':
                    strcpy(escapedChr, "\'");
                    break;
                case '\\':
                    strcpy(escapedChr, "\\");
                    break;
                default:
                    strcpy(escapedChr, "");
                    break;
            }
            strcat(buffer, escapedChr);
        } else {
            strncat(buffer, &str[i], 1);
        }
        ++i;
    }

    str = realloc(str, sizeof(char) * strlen(buffer));
    strcpy(str, buffer);

    free(buffer);

    return 0;
}


int unEscapeString(char *str) {

    const size_t str_len = strlen(str);

    char *buffer;
    buffer = malloc(str_len * sizeof(char) + 1);

    int i = 0;

    char escapedChr[3];

    while (i < str_len) {
        if (strchr(ESCAPED_CHARS, str[i]) != 0) {
            switch (str[i]) {
                case '\a':
                    strcpy(escapedChr, "\\a");
                    break;
                case '\b':
                    strcpy(escapedChr, "\\b");
                    break;
                case '\f':
                    strcpy(escapedChr, "\\f");
                    break;
                case '\n':
                    strcpy(escapedChr, "\\n");
                    break;
                case '\t':
                    strcpy(escapedChr, "\\t");
                    break;
                case '\r':
                    strcpy(escapedChr, "\\r");
                    break;
                case '\v':
                    strcpy(escapedChr, "\\v");
                    break;
                case '\"':
                    strcpy(escapedChr, "\"");
                    break;
                case '\'':
                    strcpy(escapedChr, "\'");
                    break;
                case '\\':
                    strcpy(escapedChr, "\\");
                    break;
                default:
                    strcpy(escapedChr, "");
                    break;
            }
            strcat(buffer, escapedChr);
        } else {
            strncat(buffer, &str[i], 1);
        }
        ++i;
    }

    str = realloc(str, sizeof(char) * strlen(buffer));
    strcpy(str, buffer);

    free(buffer);

    return 0;
}


int readLines(const char *filepath) {

    FILE *file;
    file = fopen(filepath, "r");

    if (!file) {
        perror("FileOpenError");
        return -1;
    }

    char *line;
    size_t length = 0;
    ssize_t readline;

    while ((readline = getline(&line, &length, file) != -1)){
        // printf("%s", line);
    }

    char *str;
    str = malloc(sizeof(char) * 80);
    strcpy(str, "Line end and end tab");

    // strcpy(str, "Line end \n and \t Tab");
    // puts(str);
    // escapeString(str);
    // puts(str);
    // unEscapeString(str);

    puts(str);
    replaceSubstr(str, "end", "start");
    puts(str);

    free(str);
    free(line);

    return 0;
}


#endif // __FILES_H__
