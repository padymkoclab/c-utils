
#include <stdio.h>
#include <locale.h>

#include "./utils/string.h"


int main (void)
{
    setlocale(LC_ALL, "");

    // SysPath *path = NewSysPath(".");
    // printPathInfo(path);
    // printUser(getUser("root"));
    // printUser(getUser("1000"));
    // printUsers();

    // char *str = "messagebus:x:104:111::/var/run/dbus:/bin/false";
    // const char del[2] = ":";
    // strsplit(str, del);

    // char temp[50] = "message text";
    // printf("%d\n", "A" - "AAdsd");
    // printf("index = %s\n", strchr(temp, 'c'));


    char str[] = "Following is the declaratison for strncmp() functin";

    char *token = splitString(str, " ");

    int i = 0;
    while (token != NULL && i < 4) {
        puts(token);
        token = splitString(NULL, " ");
        ++i;
    }

    puts(str);
    // while (token) {
    //     puts(token);
    // }

    // char *token = strsplit(str, "i");

    // if (token == NULL) {
    //     puts("Empty");
    // } {
    //     puts(token);
    // }
    // while (token != NULL) {
    //     puts(token);
    //     token = strsplit(NULL, "i");
    // }
    // puts(str);

    return 0;
}
