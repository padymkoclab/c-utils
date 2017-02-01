/**
 * Generation fake data for the C programing language
 */

#ifndef __COLORS_H__
#define __COLORS_H__


typedef struct _ColorRGB {
    unsigned short int red;
    unsigned short int green;
    unsigned short int blue;
    void (*toString)(struct _ColorRGB);
} colorRGB_t;


/*
    Convert color value from hex format to RGB
 */
static int
_ColorHexToRGB(const char value[], colorRGB_t *colorRGB) {
    return 0;
}


/*
    Convert a color`s value from RGB format to hex
 */
static int
_ColorRGBToHex(const colorRGB_t *colorRGB, char value[7]) {
    return 0;
}


/*
    Return a color`s name (if exists) from RGB
 */
static char *
_getNameColorFromRGB(const colorRGB_t *colorRGB) {
    return NULL;
}


/*
    Return a color`s name (if exists) from hex
 */
static char *
_getNameColorFromHex(const char value[]) {
    return NULL;
}


#endif // __COLORS_H__
