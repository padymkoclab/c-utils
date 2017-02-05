/**
 * Parser command-line arguments
 */


// http://click.pocoo.org/5/options/
// http://devdocs.io/python~3.5/library/argparse

/*
    argument_parser_t* argument_parser;
    argument_parser = malloc(sizeof(argument_parser_t));

    init_argument_parser(
        argument_parser, argv[0],
        "The following code is a Python program that takes a list of integers"
    );

    argparse(argument_parser, argc, argv);

    free(argument_parser);
 */


#ifndef __ARGSPARSER_H__
#define __ARGSPARSER_H__


#include <stdio.h>
#include <string.h>


const char help_argument_description[] = "Show this message and exit.";
const size_t help_argument_description_len = strlen(help_argument_description);


// type for an argument of a parser of arguments
typedef struct _argument
{
    char* description;
    char* fullname;
    const char single_char;
} argument_t;


// type for a parser of arguments
typedef struct _argument_parser
{
    char* name;
    char* description;
    argument_t *arguments;
} argument_parser_t;


static int
add_argument(argument_parser_t *argument_parser, argument_t *argument) {
    argument_parser->arguments[0] = argument;
    return 0;
}


static int
_set_option_argument(argument_t *argument, char *fullname, char single_char) {

    argument->fullname = calloc(strlen(fullname), sizeof(char));
    strcpy(argument->fullname, fullname);

    // set value for constant
    *(char *)&argument->single_char = single_char;

    return 0;

}


/*
    Initialization instance of a argument parser
 */
static int
init_argument_parser(argument_parser_t *argument_parser, const char name[], const char description[])
{
    // set name of a programm
    argument_parser->name = calloc(strlen(name), sizeof(char));
    strcpy(argument_parser->name, name);

    // set a description of the programm
    argument_parser->description = calloc(strlen(description), sizeof(char));
    strcpy(argument_parser->description, description);

    // set arguments for a option "help"
    argument_t argument;
    argument.description = calloc(help_argument_description_len, sizeof(char));
    strcpy(argument.description, help_argument_description);

    _set_option_argument(&argument, "help", 'h');

    // add an option for call a help
    add_argument(argument_parser, &argument);

    return 0;
}


/*
    Print a help text to this programm
*/
static void
print_help_text_usage(argument_parser_t *argument_parser)
{
    printf("Usage: %s\n\n", argument_parser->name);
    printf("\t%s\n\n", argument_parser->description);
    printf("Options:\n");
}


static int
argparse(argument_parser_t *argument_parser, const int argc, const char *argv[])
{
    for (int i = 0; i < argc; ++i) {
        if ((strcmp(argv[i], "--h") == 0) || (strcmp(argv[i], "--help") == 0)) {
                print_help_text_usage(argument_parser);
                return 0;
        } else if ((strcmp(argv[i], "-v") == 0) || (strcmp(argv[i], "--v") == 0) || (strcmp(argv[i], "--version") == 0)) {
                puts("Need version!");
                return 0;
        }
    }
    return -1;
}


#endif // __ARGSPARSER_H__
