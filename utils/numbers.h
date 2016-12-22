
#ifndef __NUMBERS_H__
#define __NUMBERS_H__


/*
    Return length integer if without considering sign
 */
size_t getLengthIntNumber(const int number) {
    size_t length = 1;
    int copy_number = (number < 0) ? -number : number;
    while ((copy_number = copy_number / 10) > 0) {
        ++length;
    }
    printf("len %d = %li\n", number, length);
    return length;
}


/*
    NotImplemented
    http://stackoverflow.com/questions/5459437/given-a-double-need-to-find-how-many-digits-in-total
 */
size_t getLengthFloatNumber(const float number) {
    size_t length = 1;
    int copy_number = (number < 0) ? -number : number;

    char *buffer;
    buffer = calloc(20, sizeof(char));
    sprintf(buffer, "%f", number);

    while ((copy_number = copy_number / 10) > 0) {
        ++length;
    }
    printf("len %s = %li\n", buffer, length);

    return length;
}


#endif //__NUMBERS_H__
