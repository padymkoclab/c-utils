/**
 * Utils for a system
 *
 * https://pythonhosted.org/psutil/
 */


#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdio.h>
#include <errno.h>

#include "array.h"
#include "platform.h"

#if IS_POSIX_SYSTEM == 1
    #include <sys/utsname.h>
#endif


extern int errno;

struct statusMemory {
    long unsigned int cache;
    long unsigned int free;
    long unsigned int used;
    long unsigned int total;
};


/*
    Return a current CPU usage of the system
 */
static float
get_total_cpu_usage()
{

    if (IS_POSIX_SYSTEM == 1) {

        FILE *file;
        file = fopen("/proc/stat", "r");

        if (file == NULL) {
            perror("No such file or directory\n");
            return -1;
        }

        int values[7];
        char cpu_label[3];
        fscanf(
            file,
            "%s %d %d %d %d %d %d %d",
            cpu_label, &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6]
        );

        int full_cpu = sumIntArray(values, 7);

        float cpu_usage = values[3] * 100 / full_cpu;

        fclose(file);

        return cpu_usage;

    } else {
        return -2;
    }
}


/*
    Fills struct memory usage for whole system is passed NULL
    otherwise for process id.
 */
int
get_memory_status(const int process_id)
{
    if (process_id < 0) {
        // errno
        return -1;
    }
    return 0;
}


int
get_memory_info()
{
    // return cache memory size
    // return RAM memory size
    // return total memory size
}


int
get_hardware_list()
{

}


// Show information about the file system on which each FILE resides, or all file systems by default
int
filesystem_info()
{

}


// Summarize disk usage of each FILE, recursively for directories.
int
disk_usage()
{

}

int
screen_resolution()
{

}


#endif // __SYSTEM_H__
