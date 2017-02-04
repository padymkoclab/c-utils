/**
 * Implementation array contains different data type: int, float, char.
 */


/*
    List *list = NewList();

    list->listPrint(list);
    list->listAppendInt(list, 19234);
    list->listPrint(list);
    list->listAppendFloat(list, -23232.34221);
    list->listPrint(list);
    list->listAppendChar(list, 'Z');

    list->listAppendString(list, "some string");
    list->listAppendString(list, "some string2");

    list->listPrint(list);

    int status;

    status =list->listPop(list);
    if (status == -1) puts("List is empty");
    list->listPrint(list);

    status =list->listPop(list);
    if (status == -1) puts("List is empty");
    list->listPrint(list);

    status =list->listPop(list);
    if (status == -1) puts("List is empty");
    list->listPrint(list);

    list->listAppendChar(list, 'A');
    list->listAppendInt(list, 132);
    list->listPrint(list);

    list->listClear(list);
    list->listPrint(list);
 */

#ifndef __LIST__H
#define __LIST__H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    INTEGER,
    CHR,
    STRING,
    REAL,
} TypeItemList;


typedef struct _List{
    TypeItemList type;
    union {
        int integer;
        char chr;
        float real;
        char *string;
    };
    size_t length;

    int (*listAppendInt) (struct _List *list, int value);
    int (*listAppendFloat) (struct _List *list, float value);
    int (*listAppendChar) (struct _List *list, char value);
    int (*listAppendString) (struct _List *list, char *value);

    int (*listPop) (struct _List *list);
    int (*listClear) (struct _List *list);
    void (*listPrint) (struct _List *list);

} List;


static int listAppendInt(List *list, int value){
    list[list->length].type = INTEGER;
    list[list->length].integer = value;
    list->length += 1;
    return 0;
}


static int listAppendFloat(List *list, float value){
    list[list->length].type = REAL;
    list[list->length].real = value;
    list->length += 1;
    return 0;
}


static int listAppendChar(List *list, char value){
    list[list->length].type = CHR;
    list[list->length].chr = value;
    list->length += 1;
    return 0;
}


static int listAppendString(List *list, char *value){

    list[list->length].type = STRING;

    list[list->length].string = malloc(strlen(value) * sizeof(char) + 1);
    strcpy(list[list->length].string, value);

    list->length += 1;
    return 0;
}


static int listPop(List *list){

    if (list->length == 0) {
        return -1;
    }

    switch (list[list->length].type) {
        case INTEGER:
            memset(&list[list->length].integer, 0, sizeof(int));
            break;
        case REAL:
            memset(&list[list->length].real, 0, sizeof(float));
            break;
        case CHR:
            memset(&list[list->length].chr, 0, sizeof(char));
            break;
        case STRING:
            memset(list[list->length].string, 0, sizeof(char) * strlen(list[list->length].string));
            break;
    }

    list->length -= 1;

    return 0;
}


static int listClear(List *list) {

    for (int i = 0; i < list->length; ++i) {
        switch (list[i].type) {
            case INTEGER:
                memset(&list[i].integer, 0, sizeof(int));
                break;
            case REAL:
                memset(&list[i].real, 0, sizeof(float));
                break;
            case CHR:
                memset(&list[i].chr, 0, sizeof(char));
                break;
            case STRING:
                memset(list[i].string, 0, sizeof(char) * strlen(list[i].string));
                break;
        }
    }

    list->length = 0;

    return 0;
}

static void listPrint(List *list) {

    printf("[");
    for (int i = 0; i < list->length; i++) {
        switch (list[i].type) {
            case INTEGER:
                printf("%d", list[i].integer);
                break;
            case REAL:
                printf("%f", list[i].real);
                break;
            case CHR:
                printf("%c", list[i].chr);
                break;
            case STRING:
                printf("%s", list[i].string);
                break;
        }

        if (i >= 0 && i < list->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


static List *
NewList() {

    List *list;
    list = malloc(sizeof(List));

    list->length = 0;

    list->listAppendInt = listAppendInt;
    list->listAppendFloat = listAppendFloat;
    list->listAppendChar = listAppendChar;
    list->listAppendString = listAppendString;

    list->listPop = listPop;

    list->listClear = listClear;

    list->listPrint = listPrint;

    return list;
}



#endif // __LIST__H
