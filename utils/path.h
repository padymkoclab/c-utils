/**
 * Utils for working with paths in a system
 */

/*
    SysPath *path = NewSysPath("./utils/");
    if (path->exists(path) == false) {
        perror("Path does not exists");
    }

    path->copy(path, "utils2");

    char **arr;
    arr = calloc(200, sizeof(char));

    int count = path->listdir(path, arr);

    if (count != -1) {
        int i = 0;
        while (i < count) {
            puts(arr[i]);
            i++;
        }
    }

    path->remove(path);
 */

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
    unsigned int isAbsolute: 1;
    char *parent;
    char *extension;
    char *name;
    char *fullname;

    int (*listdir) (struct _SysPath *obj, char **array);
    int (*size) (struct _SysPath *obj);
    int (*mkdir) (struct _SysPath *obj);
    int (*writeFile) (struct _SysPath *obj, char *content, char method);
    int (*readFile) (struct _SysPath *obj, char *content);
    int (*move) (struct _SysPath *obj, char location);
    int (*copy) (struct _SysPath *obj, char *location);
    int (*remove) (struct _SysPath *obj);

    void (*print) (struct _SysPath *obj);

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
isAbsolute(char *path) {
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


static void
printPath(SysPath *obj) {
    printf("Path: %s\n", obj->path);
    printf("Length: %li\n", obj->length);
    printf("Is absolute: %d\n", obj->isAbsolute);
    printf("Parent: %s\n", obj->parent);
    printf("Extension: %s\n", obj->extension);
    printf("Name: %s\n", obj->name);
    printf("Fullname: %s\n", obj->fullname);
    printf("Exists: %d\n", obj->exists(obj));
    printf("isDir: %d\n", obj->isDir(obj));
    printf("isFile: %d\n", obj->isFile(obj));
    printf("isSymlink: %d\n", obj->isSymlink(obj));
    printf("isBlock: %d\n", obj->isBlock(obj));
    printf("isFIFO: %d\n", obj->isFIFO(obj));
    printf("isSocket: %d\n", obj->isSocket(obj));
}


static bool
exists(SysPath *obj) {
    struct stat objStat;
    return stat(obj->path, &objStat) == 0 ? true: false;
};


static bool
isDir(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISDIR(objStat.st_mode);
};


static bool
isFile(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISREG(objStat.st_mode);
};


static bool
isSymlink(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISLNK(objStat.st_mode);
};


static bool
isBlock(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISBLK(objStat.st_mode);
};


static bool
isFIFO(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);
    return S_ISFIFO(objStat.st_mode);
};


static bool
isSocket(SysPath *obj) {
    struct stat objStat;
    stat(obj->path, &objStat);

    printf("[%s %s] %s %d: %s\n", __TIME__, __DATE__, __FILE__, __LINE__, "S_ISSOCK is not undefined");
    return NULL;
    // return S_ISSOCK(objStat.st_mode);
};


static char *
getExtension(SysPath *obj) {

    char *token = strchr(obj->fullname, '.');

    if (token == NULL) return NULL;

    char *extension = calloc(strlen(token), sizeof(char));
    strcpy(extension, token);

    if (extension != NULL){
        char *shift = NULL;
        if (strcmp(extension, ".") == 0) {
            extension = NULL;
        }
        while (extension != NULL) {
            shift = strchr(extension + 1, '.');
            if (shift == NULL) {
                if (extension[0] == '.') memmove(extension, extension + 1, strlen(extension));
                break;
            } else {
                strcpy(extension, shift + 1);
            }
        }
    }

    return extension;
}


static int
size(SysPath *obj) {
    struct stat st;
    if (stat(obj->path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}


static int
mkdir_(SysPath *obj) {

    return 0;
}


static int
writeFile(SysPath *obj, char *content, char method) {

    if (method == 'w' || method == 'a') {

        FILE *file;

        char method_[2];
        method_[0] = method;
        method_[1] = '\0';

        file = fopen(obj->path, method_);

        for (int i = 0; i < strlen(content); ++i) {
            fputc(content[i], file);
        }

        fclose(file);

        return 0;
    }

    return -1;
}


static int
readFile(SysPath *obj, char *content) {

    if (obj->isFile(obj) == false) return -1;

    FILE *file;

    file = fopen(obj->path, "r");
    char chr;

    int i;
    for (i = 0; (chr = fgetc(file)) != EOF; ++i) {
        content[i] = chr;
    }

    fclose(file);

    return 0;
}


static int
move(SysPath *obj, char location) {

    return 0;
}


static int
copy(SysPath *obj, char *location) {

    if (obj->isFile(obj) == true) {
        FILE *file_source, *file_copy;

        file_source = fopen(obj->path, "r");
        file_copy = fopen(location, "w");

        char chr;
        while ((chr = fgetc(file_source)) != EOF) {
            fputc(chr, file_copy);
        }

        fclose(file_source);
        fclose(file_copy);

        return 0;
    } else if (obj->isDir(obj) == true) {
        return 0;
    }

    return -1;
}


static int
remove_(SysPath *obj) {
    return remove(obj->path);
}


static int
listdir(SysPath *obj, char **array) {

    if (obj->isDir(obj) == false) return -1;

    DIR *dir;
    dir = opendir(obj->path);

    if (dir == NULL) return -2;

    unsigned int count_entries = 0;

    struct dirent *entry;
    while((entry = readdir(dir))) {

        if (strcmp(entry->d_name, ".")) {
            if (strcmp(entry->d_name, "..")) {
                array[count_entries] = malloc(strlen(entry->d_name) * sizeof(char) + 1);
                strcpy(array[count_entries], entry->d_name);
                count_entries++;
            }
        }
    }

    closedir(dir);

    return count_entries;
}


void parents();
void walk();
void child();
void expand();
void expandUser();
void expandVars();
void split();
void relativeTo();
void resolve();
void destroySysPath();


static void
bindMethodsToNewSysPath(SysPath *obj) {

    obj->size = &size;
    obj->print = &printPath;
    obj->mkdir = &mkdir_;
    obj->writeFile = &writeFile;
    obj->readFile = &readFile;
    obj->copy = &copy;
    obj->move = &move;
    obj->listdir = &listdir;
    obj->remove = &remove_;

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

    // set isAbsolute
    obj->isAbsolute = isAbsolute(path);

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

    // set extension and name
    char *extension = getExtension(obj);

    if (extension == NULL) {
        obj->extension = NULL;
    } else {

        obj->extension = calloc(strlen(extension), sizeof(char));
        strcpy(obj->extension, extension);

        size_t name_len = strlen(obj->fullname) - strlen(obj->extension);
        obj->name = calloc(name_len, sizeof(char));
        strncpy(obj->name, obj->fullname, name_len - 1);
    }

    bindMethodsToNewSysPath(obj);

    return obj;
}

#endif // __SYSPATH_H__
