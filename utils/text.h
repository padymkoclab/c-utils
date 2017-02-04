/**
 * Utils for working with a text
 */


/*
    char str[] = "regcomp() is supplied with preg, a pointer to a pattern buffer storage area; regex, a pointer to the null-terminated string and cflags, flags used to determine the type of compilation.";
    putd(getCountWords(str));
 */


typedef struct _CounterWords {

} CounterWords;



// Rewrite it FIXME!!!
static char *_copy_text_for_words;
char *
getWords(char *text) {

    char *word;

    if (text != NULL) {
        _copy_text_for_words = calloc(strlen(text), sizeof(char));
        strcpy(_copy_text_for_words, text);
        word = splitString(text, " ");
    }

    word = splitString(NULL, " ");

    if (word != NULL) {
        stripString(word, ",.:();!?", 'b');
    }

    return word;
}


unsigned int
getCountWords(char *str) {

    char *word = getWords(str);

    unsigned int count = 0;
    while (word != NULL) {
        word = getWords(NULL);
        ++count;
    }

    return count;
}


int
counterWords(CounterWords *counter_words, char *text) {
    // need fill dictionary
    return 0;
}
