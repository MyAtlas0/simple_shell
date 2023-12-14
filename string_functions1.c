#include "myhell.h"

/**
 * *_strcpy - prototype function for string
 *
 * @src: variable that copies strings including the null to dest
 *
 * @dest: buffer pointer to recieve strings from src
 *
 * Return: returns value to pointer dest
 */

char *_strcpy(char *dest, char *src)
{
	int n;

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[n] = src[n];
	}
	dest[n] = '\0';
	return (dest);
}





/**
 * *_strstr - prototype function search first occurrence of *n substring in *h
 *
 * loop condition - iterates string until NULL then compares *h and *n
 *
 * @haystack: pointer of the main string to search
 *
 * @needle: pointer of the substring to locate in haystack
 *
 * Return: returns pointer of substring of NULL if not found
 */

char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}





/**
 * *_memcpy - prototype function to copy memory area
 *
 * loop condition - compares variable n and m before increatment
 *
 * @dest: pointer variable to destination of copied memory
 *
 * @src: pointer variable of source memory
 *
 * @n: variable for bytes to copy
 *
 * Return: returns pointer to destination memory
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
	{
		dest[m] = src[m];
	}
	return (dest);
}
