/**
 * A reader and a writter for CSV files
 * Read and write data to a file.
 */

#ifndef __CSV_H__
#define __CSV_H__


#include "./path.h"


/*
    Validate a path as an exists file in the CSV format.
    Return value:
        0 - if all good;
        1 - a file does not exist;
        2 - a permmision deny;
        3 - it is not a file;
        4 - file is empty;
        5 - it is not a file in the CSV format.
*/


// CSVreadfile("assets/colors.csv");
// https://github.com/robertpostill/libcsv/blob/master/libcsv.c
// https://github.com/ben-strasser/fast-cpp-csv-parser

static unsigned int
validateFileCSV(char path[]) {
    return 0;
}

static int
readfileCSV(char path[]) {

    unsigned int validationResult;

    validationResult = validateFileCSV(path);

    if (validationResult != 0) return validationResult;

    // read file here

    return 0;
}


#endif // __CSV_H__
