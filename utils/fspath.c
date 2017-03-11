/**
 * Utils for working with paths in a system
 *
 * http://www.computerhope.com/unix/test.htm
 *
 */


#ifndef __FSPATH_H__
#define __FSPATH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#include "pprint.h"
#include "testing/unittest.h"



// http://stackoverflow.com/questions/13792116/recursively-remove-directories
// http://stackoverflow.com/questions/2256945/removing-a-non-empty-directory-programmatically-in-c-or-c
// http://stackoverflow.com/questions/5467725/how-to-delete-a-directory-and-its-contents-in-posix-c
// http://stackoverflow.com/questions/2256945/removing-a-non-empty-directory-programmatically-in-c-or-c
// http://stackoverflow.com/questions/7977501/recursively-remove-a-directory-using-c
void
fspath_rmtree(const char path[])
{
    size_t path_len;
    char *full_path;
    DIR *dir;
    struct stat stat_path, stat_entry;
    struct dirent *entry;

    // stat for the path
    stat(path, &stat_path);

    // if path does not exists or is not dir - exit with status -1
    if (S_ISDIR(stat_path.st_mode) == 0) {
        fprintf(stderr, "%s: %s\n", "Is not directory", path);
        exit(-1);
    }

    // if not possible to read the directory for this user
    if ((dir = opendir(path)) == NULL) {
        fprintf(stderr, "%s: %s\n", "Can`t open directory", path);
        exit(-1);
    }

    // the length of the path
    path_len = strlen(path);

    // iteration through entries in the directory
    while ((entry = readdir(dir)) != NULL) {

        // skip entries "." and ".."
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;

        // determinate a full path of an entry
        full_path = calloc(path_len + strlen(entry->d_name) + 1, sizeof(char));
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        // stat for the entry
        stat(full_path, &stat_entry);

        // recursively remove a nested directory
        if (S_ISDIR(stat_entry.st_mode) != 0) {
            rmtree(full_path);
            continue;
        }

        // remove a file object
        unlink(full_path);
    }

    // remove the devastated directory and close the object of it
    rmdir(path);
    closedir(dir);
}


int
copy_file(char path1[], char path2[])
{
    char chr;
    FILE *stream_for_write, *stream_for_read;

    if ((stream_for_write = fopen(path1, "w")) == NULL) {
        fprintf(
            stderr, "%s: %s\n",
            gettext("Impossible to create a file"), path1
        );
        return -1;
    }

    if ((stream_for_read = fopen(path2, "r")) == NULL) {
        fprintf(
            stderr, "%s: %s\n",
            gettext("Impossible to read a file"), path2
        );
        return -1;
    }

    while ((chr = fgetc(stream_for_read)) != EOF) {
        fputc(chr, stream_for_write);
    }

    fclose(stream_for_write);
    fclose(stream_for_read);

    return 0;
}


bool
fspath_is_absolute(const char path[])
{
    return false;
}


char **
fspath_split(const char path[])
{
    return NULL;
}


void
fspath_print(const char path[])
{

}


// https://www.cyberciti.biz/faq/linux-show-directory-structure-command-line/
void
fspath_print_tree(const char path[])
{

}


bool
fspath_exists(const char path[])
{
    return false;
};


bool
fspath_is_dir(const char path[])
{
    return false;
};


bool
fspath_is_file(const char path[])
{
    return false;
};


bool
fspath_is_symlink(const char path[])
{
    return false;
};


bool
fspath_is_block(const char path[])
{
    return false;
};


bool
fspath_is_fifo(const char path[])
{
    return false;
};


bool
fspath_is_socket(const char path[])
{
    return false;
};


char *
fspath_get_extension(const char path[])
{
    return NULL;
}


int
fspath_get_size(const char path[])
{
    return -1;
}


bool
fspath_mkdir(const char path[])
{

    return false;
}


bool
fspath_write_file(const char path[], char *content, char method)
{

    return false;
}


bool
fspath_read_file(const char path[], char *content)
{

    return false;
}


bool
fspath_move(const char path[], const char new_location[])
{

    return false;
}


bool
fspath_copy(const char path[], char *location)\
{

    return false;
}


bool
fspath_rename(const char path[], const char new_location[])
{
    return false;
}


bool
fspath_listdir(const char path[], char **array)
{

    return false;
}


bool
fspath_parents(const char path[])
{
    return false;
}


bool
fspath_walk(const char path[])
{
    return false;
}


bool
fspath_child(const char path[])
{
    return false;
}


bool
fspath_expand(const char path[])
{
    return false;
}


bool
fspath_expandUser(const char path[])
{
    return false;
}


bool
fspath_expandVars(const char path[])
{
    return false;
}


bool
fspath_relativeTo(const char path[])
{
    return false;
}


bool
fspath_resolve(const char path[])
{
    return false;
}


// https://en.wikipedia.org/wiki/GNU_Find_Utilities
// https://en.wikipedia.org/wiki/Find
bool
fspath_find(const char pattern[])
{
    return false;
}


/**
 * Tests
 */


const char *paths[20] = {
    "/media/setivolkylany/WorkDisk/Programming/Projects/c-utils",
    "/media/setivolkylany/",
    "/media/setivolkylany/WorkDisk/Private/A",
    "/",
    "////",
    "math.h",
    "./math.h",
    "~/Downloads/",
    "~/.bashrc",
    "../main.c",
    "../../../Sources/C-C++/The C programming language 1988.pdf",
};

void
test_fspath_is_absolute()
{
    assertTrue(fspath_is_absolute(paths[0]));
    assertTrue(fspath_is_absolute(paths[1]));
    assertTrue(fspath_is_absolute(paths[2]));
    assertTrue(fspath_is_absolute(paths[3]));
    assertTrue(fspath_is_absolute(paths[4]));
    assertTrue(fspath_is_absolute(paths[5]));
    assertTrue(fspath_is_absolute(paths[6]));
    assertTrue(fspath_is_absolute(paths[7]));
    assertTrue(fspath_is_absolute(paths[8]));
    assertTrue(fspath_is_absolute(paths[9]));
    assertTrue(fspath_is_absolute(paths[10]));
    assertTrue(fspath_is_absolute(paths[11]));
    assertTrue(fspath_is_absolute(paths[12]));
    assertTrue(fspath_is_absolute(paths[13]));
    assertTrue(fspath_is_absolute(paths[14]));
    assertTrue(fspath_is_absolute(paths[15]));
    assertTrue(fspath_is_absolute(paths[16]));
    assertTrue(fspath_is_absolute(paths[17]));
    assertTrue(fspath_is_absolute(paths[18]));
    assertTrue(fspath_is_absolute(paths[19]));
}


void
test_fspath()
{
    test_fspath_is_absolute();
}


#endif // __FSPATH_H__
