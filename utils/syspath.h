
#ifndef __SYSPATH_H__
#define __SYSPATH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>

#include "prettyPrint.h"


extern int errno;


typedef struct _SysPath {
    char *path;
    size_t length;
    unsigned int is_absolute: 1;
    char *parent;
    char *extension;
    char *name;
    char *fullname;
    int (*listdir) (struct _SysPath *obj, char **array);
    bool (*exists) (struct _SysPath *obj);
    bool (*isFile) (struct _SysPath *obj);
    bool (*isDir) (struct _SysPath *obj);
    bool (*isSymlink) (struct _SysPath *obj);
    bool (*isBlock) (struct _SysPath *obj);
    bool (*isSocket) (struct _SysPath *obj);
    bool (*isFIFO) (struct _SysPath *obj);
} SysPath;


static int
validatePath(char *path) {
    errno = 0;
    if (strcmp(path, "") == 0) {
        errno = -1;
    }
    return errno;
}


static bool
_is_absolute(char *path) {
    if (path[0] == '/') {
        return true;
    }
    return false;
}


static char *_old_path_for_split;
static char *
splitPathToParts(char *path) {

    char *part;
    char *rest_part;

    unsigned int length_slice;

    if (path == NULL) {

        if (_old_path_for_split == NULL) {
            return path;
        }

        size_t path_len = strlen(_old_path_for_split);

        if (path_len == 0) {
            return NULL;
        }

        rest_part = malloc(path_len * sizeof(char));
        rest_part = strstr(_old_path_for_split, "/");

        if (rest_part == NULL) {

            if (path_len > 0) {
                part = malloc(path_len * sizeof(char));
                strcpy(part, _old_path_for_split);
                _old_path_for_split = NULL;
            }

            free(_old_path_for_split);
            free(rest_part);

            return part;
        }

        size_t rest_part_len = strlen(rest_part);
        part = calloc(rest_part_len, sizeof(char));

        length_slice = path_len - rest_part_len;

        if (length_slice == 0) length_slice++;

        strncpy(part, _old_path_for_split, length_slice);

        strcpy(_old_path_for_split, rest_part + 1);

        return part;
    }

    _old_path_for_split = calloc(strlen(path), sizeof(char));
    strcpy(_old_path_for_split, path);

    size_t path_len = strlen(_old_path_for_split);

    rest_part = malloc(path_len * sizeof(char));
    rest_part = strstr(_old_path_for_split, "/");

    if (rest_part == NULL) {
        free(_old_path_for_split);
        free(rest_part);
        return path;
    }

    size_t rest_part_len = strlen(rest_part);

    part = calloc(rest_part_len, sizeof(char));

    length_slice = path_len - rest_part_len;

    if (length_slice == 0) length_slice++;

    strncpy(part, _old_path_for_split, length_slice);

    strcpy(_old_path_for_split, rest_part + 1);

    // free(rest_part);

    return part;
}


void printPathInfo(SysPath *obj){
    printf("Path: %s\n", obj->path);
    printf("Length: %li\n", obj->length);
    printf("Is absolute: %d\n", obj->is_absolute);
    printf("Parent: %s\n", obj->parent);
    printf("Extension: %s\n", obj->extension);
    printf("Name: %s\n", obj->name);
    printf("Fullname: %s\n", obj->fullname);
    printf("Exists: %d\n", obj->exists(obj));
    printf("Exists: %d\n", obj->isDir(obj));
    printf("Exists: %d\n", obj->isFile(obj));
    printf("Exists: %d\n", obj->isSymlink(obj));
    printf("Exists: %d\n", obj->isBlock(obj));
    printf("Exists: %d\n", obj->isFIFO(obj));
    printf("Exists: %d\n", obj->isSocket(obj));
}


bool
exists(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return objStat.st_mode == 0 ? false: true;
};


bool
isDir(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISDIR(objStat.st_mode);
};


bool
isFile(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISREG(objStat.st_mode);
};


bool
isSymlink(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISLNK(objStat.st_mode);
};


bool
isBlock(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISBLK(objStat.st_mode);
};


bool
isFIFO(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISFIFO(objStat.st_mode);
};


bool
isSocket(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);

    printf("[%s %s] %s %d: %s\n", __TIME__, __DATE__, __FILE__, __LINE__, "S_ISSOCK is not undefined");
    return NULL;
    // return S_ISSOCK(objStat.st_mode);
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

int
listdir(SysPath *obj, char **array) {

    if (obj->isDir(obj) == false) return -1;

    DIR *dir;
    dir = opendir(obj->path);

    if (dir == NULL) return -2;

    array = malloc(20 * sizeof(char));
    unsigned int count_entries = 0;

    struct dirent *entry;
    while((entry = readdir(dir))) {

        if (strcmp(entry->d_name, ".")) {
            if (strcmp(entry->d_name, "..")) {
                // putd(count_entries);
                array[count_entries] = malloc(strlen(entry->d_name) * sizeof(char) + 1);
                // strcpy(array[count_entries], entry->d_name);
                count_entries++;
            }
        }
    }

    closedir(dir);

    return count_entries;
}


char *
walk(SysPath *obj) {
    return "";
}


int
destroy(SysPath *obj) {
    return 0;
};


static void
bindMethodsToNewSysPath(SysPath *obj) {
    obj->listdir = &listdir;
    obj->exists = &exists;
    obj->isDir = &isDir;
    obj->isFile = &isFile;
    obj->isSymlink = &isSymlink;
    obj->isBlock = &isBlock;
    obj->isSocket = &isSocket;
    obj->isFIFO = &isFIFO;
}


SysPath *
NewSysPath(char *path) {

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

    int count;

    char **parts_path = malloc(30 * sizeof(char));

    char *part_path  = splitPathToParts(path);

    for (count = 0; part_path != NULL; ++count) {
        parts_path[count] = calloc(strlen(part_path), sizeof(char));
        strcpy(parts_path[count], part_path);
        part_path = splitPathToParts(NULL);
    }

    if (count > 1) {

        // set penult part of paths as parent
        obj->parent = calloc(strlen(parts_path[count - 2]), sizeof(char));
        strcpy(obj->parent, parts_path[count - 2]);

    } else {
        obj->parent = NULL;
    }

    // set fullname of latest string in array
    obj->fullname = malloc(strlen(parts_path[count - 1]) * sizeof(char));
    strcpy(obj->fullname, parts_path[count - 1]);

    // if (startSwithString(obj->fullname, ".")) {

    //     ListStringsWithLength *parts_fullname = splitStringToListString(obj->fullname, ".");

    //     // set extension, if presents
    //     if (parts_fullname->length > 1) {
    //         obj->extension = malloc(strlen(parts_fullname->list[parts_fullname->length - 1]) * sizeof(char));
    //         obj->extension = parts_fullname->list[parts_fullname->length - 1];
    //     } else {

    //         obj->extension = malloc(sizeof(char));
    //         obj->extension = "";
    //     }

    //     // set name
    //     obj->name = malloc(strlen(parts_fullname->list[0]) * sizeof(char) + 1);
    //     strcpy(obj->name, ".");
    //     strcat(obj->name, parts_fullname->list[0]);

    // } else {

    //     ListStringsWithLength *parts_fullname = splitStringToListString(obj->fullname, ".");

    //     // set extension, if presents
    //     if (parts_fullname->length > 1) {
    //         obj->extension = malloc(strlen(parts_fullname->list[parts_fullname->length - 1]) * sizeof(char));
    //         obj->extension = parts_fullname->list[parts_fullname->length - 1];
    //     } else {

    //         obj->extension = malloc(sizeof(char));
    //         obj->extension = "";
    //     }

    //     // set name
    //     obj->name = calloc(strlen(parts_fullname->list[0]), sizeof(char));
    //     obj->name = parts_fullname->list[0];
    // }

    bindMethodsToNewSysPath(obj);

    return obj;
}

#endif // __SYSPATH_H__
