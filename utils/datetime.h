/*

 */


#include <stdio.h>
#include <time.h>

#ifndef __DATETIME_H__
#define __DATETIME_H__


/*
    puts(asctime(getLocalTime()));
 */
struct tm* getLocalTime() {

    struct tm *local_time;
    time_t time_ = time(0);

    time(&time_);

    local_time = localtime(&time_);

    return local_time;
}

#endif // __DATETIME_H__
