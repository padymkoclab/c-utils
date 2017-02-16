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
#include "testing/unittest.h"


extern int errno;


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
