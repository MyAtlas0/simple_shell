#include "myhell.h"

/**
 * _strndup - Duplicate a specified number of characters from a string.
 *
 * @first: Pointer to the string to be duplicated.
 * @n: Number of characters to duplicate.
 *
 * Return: Pointer to the newly allocated string with 'n' characters,
 * or NULL on failure.
 */

char *_strndup(const char *first, size_t n)
{
        char *result;

        /*Allocate memory for 'n' characters plus null-terminator*/
        result = malloc(n + 1);
        if (result == NULL)
        {
                perror("Memory allocation failed (_strndup)");
                exit(1);
        }

        strncpy(result, first, n); /*Copy 'n' characters from 'first' to 'result'*/
        result[n] = '\0'; /*Null-terminate the string*/
        return (result);
}



