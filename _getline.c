#include "myhell.h"

/**
 * _realloc - Resizes the memory block pointed to by ptr to new_size.
 *
 * @ptr: Pointer to the previously allocated memory block.
 *
 * @new_size: New size in bytes to resize the memory block to.
 *
 * Return: Pointer to the newly allocated memory block on success,
 * or NULL on failure.
 */

void *_realloc(void *ptr, size_t new_size)
{
	void *new_ptr;
	size_t old_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	old_size = sizeof(ptr);
	if (new_size < old_size)
	{
		old_size = new_size;
	}

	_memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}



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
	size_t buffer_size = *n;
	size_t new_size = buffer_size * 2;
	char *temp;

	temp = _realloc(*lineptr, new_size);
	if (temp == NULL)
	{
		free(*lineptr);
	}
	*lineptr = temp;
	buffer_size = new_size;
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
		*n = INITIAL_BUFFER_SIZE;
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

	if (position == 0 && bytes_read == 0)
	{
		return (-1); /* No characters read */
	}
	return (position);
}
