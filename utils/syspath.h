
#ifndef __SYSPATH_H__
#define __SYSPATH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "./utils/string.h"

extern int errno;


typedef struct _SysPath {
    char *path;
    size_t length;
    unsigned int is_absolute: 1;
    char *parent;
    char *extension;
    char *name;
    char *fullname;
} SysPath;


int validate(char *path) {
    errno = 0;
    if (strcmp(path, "") == 0) {
        errno = -1;
    }
    return errno;
}


static bool _is_absolute(char *path) {
    if (path[0] == '/') {
        return true;
    }
    return false;
}


void printPathInfo(SysPath *syspath){
    printf("Path: %s\n", syspath->path);
    printf("Length: %li\n", syspath->length);
    printf("Is absolute: %d\n", syspath->is_absolute);
    printf("Parent: %s\n", syspath->parent);
    printf("Extension: %s\n", syspath->extension);
    printf("Name: %s\n", syspath->name);
    printf("Fullname: %s\n", syspath->fullname);
}


void exists();
void rmTree();
void isDir();
void isFile();
void isLink();
void isMount();
void size();
void stat();
void mkdir();
void writeFile();
void readFile();
void move();
void copy();
void ancestor();
void child();
void expand();
void expandUser();
void expandVars();
void split();
void replative();
void listdir();
void delete();


SysPath NewSysPath(char *path) {

    if (validate(path) != 0) {
        fprintf(stderr, "Wrong path %s\n", path);
        exit(EXIT_FAILURE);
    }

    SysPath obj;

    // split path by slash on parts
    ListString *parts_path = splitStringToList(path, "/");

    // set length of path
    size_t len = strlen(path);
    obj.length = len;

    // set path
    obj.path = (char*)malloc(len * sizeof(char));
    obj.path = path;

    // set is_absolute
    obj.is_absolute = _is_absolute(path);

    // set parent, if presents
    if (parts_path->length > 1) {
        obj.parent = malloc(strlen(parts_path->array[parts_path->length - 2]) * sizeof(char));
        obj.parent = parts_path->array[parts_path->length - 2];
    } else {
        obj.parent = malloc(sizeof(char));
        obj.parent = "";
    }

    // set fullname of latest string in array
    obj.fullname = malloc(strlen(parts_path->array[parts_path->length - 1]) * sizeof(char));
    obj.fullname = parts_path->array[parts_path->length - 1];

    ListString *parts_fullname = splitStringToList(obj.fullname, ".");

    // set extension, if presents
    if (parts_fullname->length > 1) {
        obj.extension = malloc(strlen(parts_fullname->array[parts_fullname->length - 1]) * sizeof(char));
        obj.extension = parts_fullname->array[parts_fullname->length - 1];
    } else {
        obj.extension = malloc(sizeof(char));
        obj.extension = "";
    }

    // set name
    obj.name = malloc(strlen(parts_fullname->array[0]) * sizeof(char));
    obj.name = parts_fullname->array[0];

    return obj;
}

#endif // __SYSPATH_H__
