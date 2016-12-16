/* Copyright 2016 setivolkylany */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <sys/utsname.h>
#include "./array.h"


// https://supportcenter.checkpoint.com/supportcenter/portal?eventSubmit_doGoviewsolutiondetails=&solutionid=sk65143
float get_total_cpu_usage() {
    FILE *file;
    file = fopen("/proc/stat", "r");

    if (file == NULL) {
        perror("No such file or directory\n");
        exit(1);
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
}


struct utsname name;
char* get_platform() {
    int result = uname(&name);
    if (result == 0) {
        return name.sysname;
    }
    return "";
}

#endif // SYSTEM_H
