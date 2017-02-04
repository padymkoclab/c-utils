/**
 * Utils for working with colors
 *
**/

/*
    char str[18];
    char hex[8];

    colorRGB_t *colorRGB_;
    colorRGB_ = (colorRGB_t *)malloc(sizeof(colorRGB_));

    convertColorHexToRGB("fff", colorRGB_);
    getRGBasString(colorRGB_, str);
    printf("Hex 'fff' to RGB %s\n", str);
    convertColorRGBToHex(colorRGB_, hex);
    printf("RGB %s to hex '%s'\n", str, hex);

    convertColorHexToRGB("000000", colorRGB_);
    getRGBasString(colorRGB_, str);
    printf("Hex '000000' to RGB %s\n", str);
    convertColorRGBToHex(colorRGB_, hex);
    printf("RGB %s to hex '%s'\n", str, hex);

    convertColorHexToRGB("#000000", colorRGB_);
    getRGBasString(colorRGB_, str);
    printf("Hex '#000000' to RGB %s\n", str);
    convertColorRGBToHex(colorRGB_, hex);
    printf("RGB %s to hex '%s'\n", str, hex);

    convertColorHexToRGB("#FFF", colorRGB_);
    getRGBasString(colorRGB_, str);
    printf("Hex '#FFF' to RGB %s\n", str);
    convertColorRGBToHex(colorRGB_, hex);
    printf("RGB %s to hex '%s'\n", str, hex);

    free(colorRGB_);
 */


// https://github.com/codebrainz/color-names


#ifndef __COLORS_H__
#define __COLORS_H__


// a type for a struct of RGB color
typedef struct _ColorRGB {
    unsigned short int red;
    unsigned short int green;
    unsigned short int blue;
} colorRGB_t;


/*
    Convert a color`s value from the hex format to the RGB.
    Return -1 if a passed value in the hex format is not correct, otherwise - return 0;
 */
static int
convertColorHexToRGB(const char originValue[], colorRGB_t *colorRGB) {

    // a full value of color in hex format must constains 6 charapters
    char completedValue[6];
    size_t lenOriginValue;
    size_t lenCompletedValue;

    // an intermediary variable for keeping value in the hex format
    char hexSingleValue[3];

    // a temp pointer to char, need only to the strtol()
    char *ptr;

    // a variable for keeping a converted number in the hex to the decimal format
    long int number;

    // validation input
    lenOriginValue = strlen(originValue);
    if (lenOriginValue > 7 || lenOriginValue < 3) return -1;

    // copy value without sign '#', if found as first in the string
    (originValue[0] == '#') ? strcpy(completedValue, originValue + 1) : strcpy(completedValue, originValue);

    lenCompletedValue = strlen(completedValue);

    // if the value has only 3 charapters, dublicate an each after itself
    // but if not full version of the hex name of a color (6 charapters), return -1
    if (lenCompletedValue == 3) {
        completedValue[5] = completedValue[2];
        completedValue[4] = completedValue[2];
        completedValue[3] = completedValue[1];
        completedValue[2] = completedValue[1];
        completedValue[1] = completedValue[0];
    } else if (lenCompletedValue != 6) return -1;

    // convert string, by parts, to decimal values and keep it in a struct

    sprintf(hexSingleValue, "%c%c", completedValue[0], completedValue[1]);
    number = strtol(hexSingleValue, &ptr, 16);
    colorRGB->red = number;

    sprintf(hexSingleValue, "%c%c", completedValue[2], completedValue[3]);
    number = strtol(hexSingleValue, &ptr, 16);
    colorRGB->green = number;

    sprintf(hexSingleValue, "%c%c", completedValue[4], completedValue[5]);
    number = strtol(hexSingleValue, &ptr, 16);
    colorRGB->blue = number;

    return 0;
}


/*
    Convert a color`s value from the RGB format to the hex
 */
static int
convertColorRGBToHex(const colorRGB_t *colorRGB, char value[8]) {
    sprintf(value, "#%02X%02X%02X", colorRGB->red, colorRGB->green, colorRGB->blue);
    return 0;
}


/*
    Forming a string representation data in an instance of the structure colorRGB_t
 */
static int
getRGBasString(const colorRGB_t *colorRGB, char str[18]) {
    sprintf(str, "rgb(%d, %d, %d)", colorRGB->red, colorRGB->green, colorRGB->blue);
    return 0;
}


/*
    Convert a color`s name (if exists) to RGB
 */
static char *
convertNameColorToRGB(const char value[], const colorRGB_t *colorRGB) {
    return 0;
}


/*
    Convert a color`s name (if exists) to Hex
 */
static int
convertNameColorToHex(const char colorname[], const char value[7]) {
    return 0;
}


/*
    Return a color`s name (if exists) from RGB
 */
static char *
getNameColorFromRGB(const colorRGB_t *colorRGB) {
    return NULL;
}


/*
    Return a color`s name (if exists) from hex
 */
static char *
getNameColorFromHex(const char value[]) {
    return NULL;
}

#endif // __COLORS_H__
