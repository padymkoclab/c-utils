
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static char *old_string;

char* strsplit(char *string, const char *delimiter) {

    char *token;

    if (string == NULL) {
        string = old_string;
    }

    string += strspn(string, delimiter);

    token = string;

    string = strpbrk(string, delimiter);
    puts(token);
    return token;
}


void reverseString(char *string) {
    const size_t string_len = strlen(string);
    char *copy_;
    copy_ = calloc(string_len, sizeof(char));
    strcpy(copy_, string);

    for (int i = 0; i < string_len; ++i) {
        string[i] = copy_[string_len - i - 1];
    }
}


void reverseIntArray(int *array, const size_t length) {
    int *copy_;
    copy_ = calloc(length, sizeof(int));
    copy_ = array;

    for (int i = 0; i < length; ++i) {
        array[i] = copy_[length - i - 1];
    }
}


void shuffleIntArray(int *array, const size_t length) {

}


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

    int arr[] = {1,2,3,4,5};

    for (int i = 0; i < 5; ++i) {
        printf("%d", arr[i]);
    }

    reverseIntArray(arr, 5);
    puts("");

    for (int i = 0; i < 5; ++i) {
        printf("%d", arr[i]);
    };
    puts("");

    return 0;
}
