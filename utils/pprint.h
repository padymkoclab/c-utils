
#ifndef __PRETTY_PRINT_H__
#define __PRETTY_PRINT_H__

#include <stdio.h>
#include <time.h>
#include <errno.h>

#include "platform.h"

#if IS_POSIX_SYSTEM == 1
    #include <sys/stat.h>
#endif


extern int errno;


// print items of an array by a format
#define PRINT_ARRAY(array, length, format) \
{ \
    putchar('['); \
    for (size_t i = 0; i < length; ++i) { \
        printf(format, array[i]); \
        if (i < length - 1) printf(", "); \
    } \
    puts("]"); \
}


/*
    Print an integer value and the new line chapter
 */
void
putd(const int value) {
    printf("%d\n", value);
}


/*
    Print a stat for a path, if it a POSIX-compliant file system
 */
void
printStatStruct(char *path, struct stat path_stat) {
    if (IS_POSIX_SYSTEM == 0) {
        errno = ENOTSUP;
        perror("Is not POSIX system");
        return;
    }
    printf("\tStat for path:\t\t\t\t\t\t%s\n", path);
    printf("\tUser ID of owner:\t\t\t\t\t%u\n", path_stat.st_uid);
    printf("\tGroup ID of owner:\t\t\t\t\t%u\n", path_stat.st_gid);
    printf("\tTotal size:\t\t\t\t\t\t\t%ld bytes\n", path_stat.st_size);
    printf("\tFile type and mode:\t\t\t\t\t%o\n", path_stat.st_mode);
    printf("\tID of device containing file:\t\t%ld\n", path_stat.st_dev);
    printf("\tInode number:\t\t\t\t\t\t%ld\n", path_stat.st_ino);
    printf("\tNumber of hard links:\t\t\t\t%ld\n", path_stat.st_nlink);
    printf("\tDevice ID (if special file):\t\t%ld\n", path_stat.st_rdev);
    printf("\tBlocksize for filesystem I/O:\t\t%ld\n", path_stat.st_blksize);
    printf("\tNumber of 512B blocks allocated:\t%ld\n", path_stat.st_blocks);
    printf("\tTime of last access:\t\t\t\t%s", ctime(&path_stat.st_atime));
    printf("\tTime of last modified:\t\t\t\t%s", ctime(&path_stat.st_mtime));
    printf("\tTime of last status change:\t\t\t%s", ctime(&path_stat.st_ctime));
}


#endif // __PRETTY_PRINT_H__
