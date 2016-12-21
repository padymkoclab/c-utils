
#ifndef __SYSPATH_H__
#define __SYSPATH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "./utils/string.h"

extern int errno;


extern int errno;


typedef struct _SysPath {
    char *path;
    size_t length;
    unsigned int is_absolute: 1;
    char *parent;
    char *extension;
    char *name;
    char *fullname;
    ListStringsWithLength* (*listdir) (struct _SysPath *obj);
    bool (*exists) (struct _SysPath *obj);
    bool (*isFile) (struct _SysPath *obj);
    bool (*isDir) (struct _SysPath *obj);
    bool (*isSymlink) (struct _SysPath *obj);
    bool (*isMount) (struct _SysPath *obj);
    bool (*isSocket) (struct _SysPath *obj);
    bool (*isFIFO) (struct _SysPath *obj);
} SysPath;


static int validatePath(char *path) {
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


void printPathInfo(SysPath *obj){
    printf("Path: %s\n", obj->path);
    // printf("Length: %li\n", obj->length);
    // printf("Is absolute: %d\n", obj->is_absolute);
    // printf("Parent: %s\n", obj->parent);
    // printf("Extension: %s\n", obj->extension);
    // printf("Name: %s\n", obj->name);
    // printf("Fullname: %s\n", obj->fullname);
    printf("Exists: %d\n", obj->exists(obj));
    printf("Exists: %d\n", obj->isDir(obj));
    printf("Exists: %d\n", obj->isFile(obj));
    printf("Exists: %d\n", obj->isSymlink(obj));
    printf("Exists: %d\n", obj->isMount(obj));
    printf("Exists: %d\n", obj->isFIFO(obj));
    printf("Exists: %d\n", obj->isSocket(obj));
}


struct stat getStat(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return objStat;
};


void printStatStruct(char *path, struct stat path_stat) {
    // printf("\tStat for path:\t\t\t\t\t\t%s\n", path);
    // printf("\tUser ID of owner:\t\t\t\t\t%u\n", path_stat.st_uid);
    // printf("\tGroup ID of owner:\t\t\t\t\t%u\n", path_stat.st_gid);
    // printf("\tTotal size:\t\t\t\t\t\t\t%ld bytes\n", path_stat.st_size);
    // printf("\tFile type and mode:\t\t\t\t\t%o\n", path_stat.st_mode);
    // printf("\tID of device containing file:\t\t%ld\n", path_stat.st_dev);
    // printf("\tInode number:\t\t\t\t\t\t%ld\n", path_stat.st_ino);
    // printf("\tNumber of hard links:\t\t\t\t%ld\n", path_stat.st_nlink);
    // printf("\tDevice ID (if special file):\t\t%ld\n", path_stat.st_rdev);
    // printf("\tBlocksize for filesystem I/O:\t\t%ld\n", path_stat.st_blksize);
    // printf("\tNumber of 512B blocks allocated:\t%ld\n", path_stat.st_blocks);
    // printf("\tTime of last access:\t\t\t\t%s", ctime(&path_stat.st_atime));
    // printf("\tTime of last modified:\t\t\t\t%s", ctime(&path_stat.st_mtime));
    // printf("\tTime of last status change:\t\t\t%s", ctime(&path_stat.st_ctime));
}


bool exists(SysPath *obj) {
    struct stat objStat = getStat(obj);
    printStatStruct(obj->path, objStat);
    return 0;
};


bool isDir(SysPath *obj) {
    return false;
};


bool isFile(SysPath *obj) {
    return false;
};


bool isSymlink(SysPath *obj) {
    return false;
};


bool isMount(SysPath *obj) {
    return false;
};


bool isFIFO(SysPath *obj) {
    return false;
};


bool isSocket(SysPath *obj) {
    return false;
};


void rmTree();
void size();
void mkdirThis();
void writeFile();
void readFile();
void move();
void copy();
void parents();
void child();
void expand();
void expandUser();
void expandVars();
void split();
void relativeTo();

// ListStringsWithLength* listdir (SysPath *syspath) {

//     ListStringsWithLength *list_strings_with_length;

//     list_strings_with_length->length = 1;

//     return list_strings_with_length;
// };

void delete();


static void bindMethodsToNewSysPath(SysPath *obj) {
    // obj->listdir = listdir;
    obj->exists = &exists;
    obj->isDir = &isDir;
    obj->isFile = &isFile;
    obj->isSymlink = &isSymlink;
    obj->isMount = &isMount;
    obj->isSocket = &isSocket;
    obj->isFIFO = &isFIFO;
}


SysPath* NewSysPath(char *path) {

    if (validatePath(path) != 0) {
        fprintf(stderr, "Wrong path %s\n", path);
        exit(EXIT_FAILURE);
    }

    SysPath *obj = malloc(sizeof(SysPath));

    // set length of path
    size_t len = strlen(path);
    obj->length = len;

    // set path
    obj->path = (char*)malloc(len * sizeof(char));
    obj->path = path;

    // set is_absolute
    obj->is_absolute = _is_absolute(path);

    // split path by slash on parts
    ListStringsWithLength *parts_path = splitStringToListString(path, "/");

    // set parent, if presents
    if (parts_path->length > 1) {
        obj->parent = malloc(strlen(parts_path->list[parts_path->length - 2]) * sizeof(char));
        obj->parent = parts_path->list[parts_path->length - 2];
    } else {
        obj->parent = malloc(sizeof(char));
        obj->parent = "";
    }

    // set fullname of latest string in array
    obj->fullname = malloc(strlen(parts_path->list[parts_path->length - 1]) * sizeof(char));
    obj->fullname = parts_path->list[parts_path->length - 1];

    if (startSwithString(obj->fullname, ".")) {

        ListStringsWithLength *parts_fullname = splitStringToListString(obj->fullname, ".");

        // set extension, if presents
        if (parts_fullname->length > 1) {
            obj->extension = malloc(strlen(parts_fullname->list[parts_fullname->length - 1]) * sizeof(char));
            obj->extension = parts_fullname->list[parts_fullname->length - 1];
        } else {

            obj->extension = malloc(sizeof(char));
            obj->extension = "";
        }

        // set name
        obj->name = malloc(strlen(parts_fullname->list[0]) * sizeof(char) + 1);
        strcpy(obj->name, ".");
        strcat(obj->name, parts_fullname->list[0]);

    } else {

        ListStringsWithLength *parts_fullname = splitStringToListString(obj->fullname, ".");

        // set extension, if presents
        if (parts_fullname->length > 1) {
            obj->extension = malloc(strlen(parts_fullname->list[parts_fullname->length - 1]) * sizeof(char));
            obj->extension = parts_fullname->list[parts_fullname->length - 1];
        } else {

            obj->extension = malloc(sizeof(char));
            obj->extension = "";
        }

        // set name
        obj->name = calloc(strlen(parts_fullname->list[0]), sizeof(char));
        obj->name = parts_fullname->list[0];
    }

    bindMethodsToNewSysPath(obj);

    return obj;
}

#endif // __SYSPATH_H__
