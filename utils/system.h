/**
 * Utils for a system
 */


#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdio.h>

#include "array.h"
#include "platform.h"

#if IS_POSIX_SYSTEM == 1
    #include <sys/utsname.h>
#endif


/*
    Return a current CPU usage of the system
 */
static float
get_total_cpu_usage() {

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


// hard memory: free, used
// cache memory
// RAM
// hardware


#endif // __SYSTEM_H__
