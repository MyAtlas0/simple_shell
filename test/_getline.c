#include "myhell.h"


/**
 * expand_buffer - Expands the buffer size for dynamic memory allocation.
 *                 Doubles the size of the allocated memory block to accomodate
 *                 more characters or data.
 *
 * @lineptr: Pointer to the allocated memory block.
 *
 * @n: Pointer to the size of the allocated memory block.
 */

void expand_buffer(char **lineptr, size_t *n)
{
	char *temp;

	*n *= 2;
	temp = realloc(*lineptr, *n);
	if (temp == NULL)
	{
		perror("Buffer reallocation failed");
		exit(EXIT_FAILURE);
	}
	*lineptr = temp;
}





/**
 * _getline - Reads input from a file stream and stores it in a dynamically
 *            allocated buffer pointed to by lineptr.
 *
 * @lineptr: Pointer to a buffer that stores the read line.
 *
 * @n: Pointer to the size of the buffer.
 *
 * @stream: File stream from which input is read.
 *
 * Return: On success, returns the number of characters read, including the
 *         newline character if present. On failure or end of file, returns -1.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = *n;
	size_t position = 0;
	ssize_t bytes_read;
	char input;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(INITIAL_BUFFER_SIZE);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		buffer_size = INITIAL_BUFFER_SIZE;
	}
	while ((bytes_read = read(fileno(stream), &input, 1)) > 0)
	{
		if (position >= buffer_size - 1)
		{
			/* Expand buffer if needed */
			expand_buffer(lineptr, &buffer_size);
		}

		(*lineptr)[position++] = input;
		if (input == '\n')
		{
			break;
		}
	}

	(*lineptr)[position] = '\0';
	*n = buffer_size;
	if (position == 0 && bytes_read == 0)
	{
		return (-1); /* No characters read */
	}
	return (position);
}
