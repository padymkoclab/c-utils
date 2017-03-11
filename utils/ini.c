/**
 * A parser for INI files
 *
 * https://en.wikipedia.org/wiki/INI_file
 * https://docs.python.org/3.5/library/configparser.html
 */


char *
str_trim(char str[])
{
    char *buffer;
    int len;

    while (isspace(*str)) ++str;

    char *end = str + strlen(str) - 1;

    while (isspace(*end)) {
        --end;
    }

    len = strlen(str) - strlen(end);
    buffer = malloc(len * sizeof(char));

    strncpy(buffer, str, len + 1);

    return buffer;
}


char *
ini_str_split_by_equal(char line[], char *value)
{
    char *name;
    char *rest_line = strchr(line, '=');

    if (!value)
        return NULL;

    size_t len = strlen(line) - strlen(rest_line);
    name = calloc(len, sizeof(char));
    strncpy(name, line, len);
    name = str_trim(name);

    ++rest_line;
    rest_line = str_trim(rest_line);
    strcpy(value, rest_line);

    return name;
}


bool
ini_is_section(char str[])
{
    if (str[0] == '[' && str[strlen(str) - 1] == ']')
        return true;
    return false;
}


bool
ini_is_comment(char str[])
{
    return (str[0] == ';') ? true : false;
}


int
ini_leave_section_name(char str[])
{
    memmove(str, str + 1, strlen(str) - 2);
    str[strlen(str) - 2] = '\0';
    return 0;
}


char *
ini_parse_stream(char path[], char domain[], char localedir[])
{
    FILE *stream = fopen(path, "r");

    if (!stream) {
        perror("File opening failed");
        exit(1);
    }

    char *line, *current_section, *name, value[300];
    size_t len = 0;
    ssize_t count_read_chars;

    while ((count_read_chars = getline(&line, &len, stream)) != -1) {
        line = str_trim(line);
        if (strcmp(line, "") == 0)
            continue;
        else if (ini_is_comment(line) == true)
            continue;
        else if (ini_is_section(line) == true) {
            ini_leave_section_name(line);
            current_section = calloc(strlen(line), sizeof(char));
            strcpy(current_section, line);
        }
        else if (current_section != NULL) {
            if (strcmp(current_section, "main") == 0) {

                name = ini_str_split_by_equal(line, value);

                if (strcmp(name, "domain") == 0) {
                    strcpy(domain, value);
                }
                else if (strcmp(name, "localedir") == 0) {
                    strcpy(localedir, value);
                }
            }

        }
    };

    fclose(stream);

    return "";
}
