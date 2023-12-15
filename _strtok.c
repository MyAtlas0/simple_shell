#include "myhell.h"


/**
 * _strtok - Tokenizes the input string and splits it into separate arguments.
 *           This function creates an array of strings by splitting the input
 *           based on spaces, tabs, and newlines.
 *
 * @input: Input string to be tokenized.
 *
 * Return: An array of strings (arguments) obtained by splitting the input.
 */

char **_strtok(const char *input)
{
	size_t count = 0;
	size_t word_len;
	char **args = NULL;
	const char *start = input;

	args = malloc(sizeof(char *) * (MAX_INPUT + 1));
	if (args == NULL)
	{
		perror("Memory allocation failed(token)");
		exit(1);
	}
	while (*input != '\0' && count < MAX_INPUT)
	{
		while (*input == ' ' || *input == '\t' || *input == '\n')
		{
			input++;
			start = input; /*Mark the beginning of a new word*/
		}
		if (*input == '\0')
		{
			break;
		}
		while (*input != ' ' && *input != '\t' &&
				*input != '\n' && *input != '\0')
		{
			input++;
		}
		word_len = input - start; /*Calculate the length of the word*/
		/*Allocate memory for the word and copy it*/
		args[count] = _strndup(start, word_len);
		if (args[count] == NULL)
		{
			perror("Memory allocation failed(token)");
			free_args(args);
			exit(1);
		}
	/*	_memcpy(args[count], (char *)start, word_len);*/
		args[count][word_len] = '\0';
		count++;
	}
	args[count] = NULL; /* Null-terminate the args array */
	return (args);
}
