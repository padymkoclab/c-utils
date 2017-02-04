/**
 *
 */


/*
    printUser(getUser("root"));
    printUser(getUser("1000"));
    printUsers();
 */

#ifndef __PWD_H__
#define __PWD_H__

#include <stdio.h>
#include <pwd.h>

#include "./string.h"


struct passwd*
getUser(char *id_or_name) {
    struct passwd *obj;
    if (isNumericString(id_or_name)) {
        obj = getpwuid(atoi(id_or_name));
    } else {
        obj = getpwnam(id_or_name);
    }
    return obj;
}


void
printUser(struct passwd *obj) {
    printf("Login name:\t%s\n", obj->pw_name);
    printf("User ID:\t%d\n", obj->pw_uid);
    printf("Group ID:\t%d\n", obj->pw_gid);
    printf("Workdir:\t%s\n", obj->pw_dir);
    printf("Run shell:\t%s\n", obj->pw_shell);
    printf("Info:\t%s\n", obj->pw_gecos);
    printf("Password:\t%s\n", obj->pw_passwd);
}


void
printUsers(){

    const char filename[12] = "/etc/passwd";
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("FileOpenError");
        exit(EXIT_FAILURE);
    }

    unsigned int chr, line_length = 1;
    char *line = NULL;

    while ((chr = fgetc(fp)) != EOF) {
        if (chr == '\n') {
            ListStringsWithLength *list_strings_with_length = splitStringToListString(line, ":");

            if (list_strings_with_length->length == 6) {
                // printf("%s ", list_strings_with_length->list[0]);

            }
            strcpy(line, "");
            line_length = 1;
        }
        line = realloc(line, sizeof(char) * line_length);
        line[line_length - 1] = chr;
        line_length++;
        // putchar(chr);
    }

    free(line);
    puts("");

    fclose(fp);


    ListStringsWithLength *lst = splitStringToListString("messagebus:x:104:111::/var/run/dbus:/bin/false", ":");
    for (int i = 0; i < lst->length; ++i) {
        printf("'%s' ", lst->list[i]);
        /* code */
    }

}


#endif // __PWD_H__
