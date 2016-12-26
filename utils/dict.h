/**
 * Implementation ditionary (key-value storage)
 */


// https://gist.github.com/kgabis/3141664
// http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
// http://codereview.stackexchange.com/questions/63427/simple-key-value-store-in-c

#include <stdio.h>
#include <stdbool.h>


#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__


typedef struct _KeyValue {
    char *key;
    int value;
} KeyValue;


typedef struct _Dict {

    KeyValue *items;

    char **keys;
    int *values;
    size_t length;

    int (*get) (struct _Dict *dict, char *key);
    int (*set) (struct _Dict *dict, char *key, int value);
    int (*del) (struct _Dict *dict, char *key);
    int (*in) (struct _Dict *dict, char *key);
    int (*print) (struct _Dict *dict);
    int (*add) (struct _Dict *dict, KeyValue *keyvalue);
    int (*remove) (struct _Dict *dict, KeyValue *keyvalue);
    int (*clear) (struct _Dict *dict, KeyValue *keyvalue);

} Dict;


static int
add(Dict *dict, KeyValue *keyvalue) {
    return 0;
}


Dict *
NewDict() {
    Dict *dict;
    dict = malloc(sizeof(Dict));
    dict->add = add;
    return dict;
}


#endif // __DICTIONARY_H__
