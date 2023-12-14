#include "myhell.h"


/**
 * input_process - Process the input string.
 *
 * This function takes an input string and processes it.
 * If the input string is NULL, it immediately returns,
 * without performing any operations.
 *
 * @input: The input string to be processed.
 */

void input_process(char *input)
{
	if (input == NULL)
	{
		return; /*No input, return immediately*/
	}
}




/**
 * free_args - Free memory allocated for an array of strings.
 *
 * This function frees the memory allocated for each string in the array
 * and then frees the array itself.
 *
 * @args: The array of strings to be freed.
 */

void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]); /*Free memory allocated for each string*/
		i++;
	}
	free(args);
}
