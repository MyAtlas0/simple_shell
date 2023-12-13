#include "myhell.h"


/**
 * _strlen - Function to calculate the length of a string.
 *
 * @s: Pointer to the string.
 *
 * Return: The length of the string.
 */

size_t _strlen(const char *s)
{
	size_t count = 0;

	if (s == NULL)
	{
		return (0); /*Handle NULL pointer case*/
	}

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}





/**
 * _strcmp - Compare two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal.
 *		A negative value if s1 is less than s2.
 *		A positive value if s1 is greater than s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}




/**
 * _strncmp - Compare up to 'n' characters of two strings.
 *
 * @s1: Pointer to the first string to be compared.
 *
 * @s2: Pointer to the second string to be compared.
 *
 * @n: Number of characters to compare.
 *
 * Return:
 *   0 if the strings are equal for the first 'n' characters,
 *   a value greater than 0 if 's1' is greater than 's2' after 'n' characters,
 *   a value less than 0 if 's1' is less than 's2' after 'n' characters.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}

	while (n-- > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
			/*Return the difference if characters are not equal*/
		}
		s1++;
		s2++;
	}
	/*Both strings are equal up to 'n' characters*/
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}





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

	_strncpy(result, first, n); /*Copy 'n' characters from 'first' to 'result'*/
	result[n] = '\0'; /*Null-terminate the string*/
	return (result);
}






/**
 * _strncpy - Copies at most n bytes of a string
 *            from the source to the destination.
 *
 * @source: Source string to be copied.
 *
 * @destination: Destination string to be copied to.
 *
 * @n: Maximum number of characters to be copied.
 *
 * Return: A pointer to the destination string.
 */

char *_strncpy(char *destination, const char *source, size_t n)
{
	size_t i = 0;
	const char *error_message = "Error: Source string is NULL\n";

	if (source == NULL)
	{
		/*Print error message to stderr and return NULL*/
		write(STDERR_FILENO, error_message, _strlen(error_message));
		return (NULL);
	}

	/*Copy at most n characters from source to destination*/
	while (i < n && source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';

	return (destination);
}
