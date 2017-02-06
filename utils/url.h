/**
 * Utils for working with a URL
 */


// decode url
// encode url


/*
Escapes a value for use in a URL.

For example:

{{ value|urlencode }}
If value is "https://www.example.org/foo?a=b&c=d", the output will be "https%3A//www.example.org/foo%3Fa%3Db%26c%3Dd".

An optional argument containing the characters which should not be escaped can be provided.

If not provided, the ‘/’ character is assumed safe. An empty string can be provided when all characters should be escaped. For example:

{{ value|urlencode:"" }}
If value is "https://www.example.org/", the output will be "https%3A%2F%2Fwww.example.org%2F".
 */
static int
urlencode(char url)
{
    return 0;
}
