/**
 * Utils for working with a text
 */


/*
    char str[] = "regcomp() is supplied with preg, a pointer to a pattern buffer storage area; regex, a pointer to the null-terminated string and cflags, flags used to determine the type of compilation.";
    putd(getCountWords(str));
 */

// Idea: word cloud


#ifndef __TEXT_H__
#define __TEXT_H__


typedef struct _CounterWords {

} CounterWords;



// Need rewrite
char **
text_get_words(char text[], unsigned int *length)
{ /*
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
*/
    return NULL;
}


unsigned int
text_get_count_words(char text[])
{
    unsigned int length;
    text_get_words(text, &length);
    return length;
}


// Need mapping (dictionary)
char **
counter_words(CounterWords *counter_words, char text[])
{
    return NULL;
}


/*
Wraps words at specified line length.

Argument: number of characters at which to wrap the text

For example:

{{ value|wordwrap:5 }}
If value is Joel is a slug, the output would be:

Joel
is a
slug
 */
char *
text_wrap(char text[], const unsigned int width)
{
    return NULL;
}


/**
 * Tests
 */


void
test_text_wrap()
{
    text_wrap();
}


void
test_text()
{
    test_text_wrap();
}



#endif // __TEXT_H__
