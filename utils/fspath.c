/**
 * Utils for working with paths in a system
 */


#ifndef __FSPATH_H__
#define __FSPATH_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

// #include <dirent.h>
// #include <sys/stat.h>

#include "pprint.h"


extern int errno;


bool
fs_path_is_valid(const char *path)
{
    return false;
}


bool
fs_path_is_absolute(const char path[])
{
    return false;
}


char **
fs_path_split(const char path[])
{
    return NULL;
}


void
fs_path_print(const char path[])
{

}


bool
fs_path_exists(const char path[])
{
    return false;
};


bool
fs_path_is_dir(const char path[])
{
    return false;
};


bool
fs_path_is_file(const char path[])
{
    return false;
};


bool
fs_path_is_symlink(const char path[])
{
    return false;
};


bool
fs_path_is_block(const char path[])
{
    return false;
};


bool
fs_path_is_fifo(const char path[])
{
    return false;
};


bool
fs_path_is_socket(const char path[])
{
    return false;
};


char *
fs_path_get_extension(const char path[])
{
    return NULL;
}


int
fs_path_get_size(const char path[])
{
    return -1;
}


bool
fs_path_mkdir(const char path[])
{

    return false;
}


bool
fs_path_write_file(const char path[], char *content, char method)
{

    return false;
}


bool
fs_path_read_file(const char path[], char *content)
{

    return false;
}


bool
fs_path_move(const char path[], const char new_location[])
{

    return false;
}


bool
fs_path_copy(const char path[], char *location)\
{

    return false;
}


bool
fs_path_rename(const char path[], const char new_location[])
{
    return false;
}


bool
fs_path_listdir(const char path[], char **array)
{

    return false;
}


bool
fs_path_parents(const char path[])
{
    return false;
}


bool
fs_path_walk(const char path[])
{
    return false;
}


bool
fs_path_child(const char path[])
{
    return false;
}


bool
fs_path_expand(const char path[])
{
    return false;
}


bool
fs_path_expandUser(const char path[])
{
    return false;
}


bool
fs_path_expandVars(const char path[])
{
    return false;
}


bool
fs_path_relativeTo(const char path[])
{
    return false;
}


bool
fs_path_resolve(const char path[])
{
    return false;
}


/**
 * Tests
 */


void
test_fs_path_is_valid(const char path[])
{

}



void
test_fspath()
{
    const char *paths[11] = {
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

    for (int i = 0; i < 11; ++i) {
        printf("%s is valid: %d\n", paths[i], fs_path_is_valid(paths[i]));

    }
}


#endif // __FSPATH_H__
