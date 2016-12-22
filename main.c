
#include <stdio.h>
// #include <string.h>

#include "./utils/string.h"


int main (void)
{
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


    char str[] = "Following is the declaratison for strncmp() function.";

    printf("%d\n", indexOfRightString(str, "str"));
    printf("%d\n", indexOfRightString(str, " str"));
    printf("%d\n", indexOfRightString(str, "str "));
    printf("%d\n", indexOfRightString(str, "()"));
    printf("%d\n", indexOfRightString(str, "ll"));
    printf("%d\n", indexOfRightString(str, "lo"));

    puts(str);
    reverseString(str);
    puts(str);

    return 0;
}
