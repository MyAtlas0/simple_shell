#include "myhell.h"

/**
 * _strtok - Function to tokenize the input string.
 *
 * @input: Represents the characters to be tokenized.
 *
 * Return: The arguments of the string.
 */

char **_strtok(const char *input)
{
	size_t count = 0;
	char **args = NULL;
	const char *first = input;
	const char *last = input;
	size_t max_inputs = MAX_INPUT;

	args = malloc(sizeof(char *) * (max_inputs + 1));
	if (args == NULL)
	{
		perror("Memory allocation failed(token)");
		exit(1);
	}

	while (*last != '\0' && count < max_inputs)
	{
		first = skip_spaces(first);
		last = last_input(last);

		if (first != last)
		{
			args[count] = _strndup(first, (last - first));
			count++;
		}
		first = last;
	}
	args[count] = NULL;
	return args;
}





const char *last_input(const char *last)
{
	while (*last && !(*last == ' ' || *last == '\0'))
	{
		last++;
	}
	return last;
}





const char *skip_spaces(const char *first)
{
	while (*first && (*first == ' ' || *first == '\0'))
	{
		first++;
	}
	return first;
}





char *_strndup(const char *first, size_t n)
{
	char *result;
	size_t str_len = strlen(first);

	if (n < str_len)
	{
		str_len = n;
	}

	result = malloc(str_len + 1);
	if (result == NULL)
	{
		return NULL;
	}

	memcpy(result, first, str_len);
	result[str_len] = '\0';
	return result;
}
