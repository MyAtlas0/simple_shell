#include "myhell.h"


/**
 * read_prompt - Read input from the user.
 *
 * This function reads input from the user through the input stream (stdin).
 * It displays the prompt '$ ' if the input is interactive. It uses _getline to
 * read the input and adjusts the string if the last character is a newline.
 *
 * Return: Pointer to the input string.
 *          NULL if an error occurs or if reading fails.
 */

char *read_prompt()
{
	char *input = NULL;
	size_t buffer = 0;
	ssize_t read;
	int interactive;

	interactive = isatty(STDIN_FILENO);
	if (interactive)
	{
		write_char("$ ");
		fflush(stdout);
	}

	read = _getline(&input, &buffer, stdin);
	if (read == -1)
	{
		free(input);
		return (NULL);
	}
	if (input[read - 1] == '\n')
	{
		input[read - 1] = '\0';
	}

	return (input);
}





/**
 * main - Entry point of the shell program.
 *
 * The main function initializes variables, reads input from the user,
 * processes the input, and handles commands accordingly.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		input = read_prompt();
		if (input == NULL)
		{
			break;
		}
		args = _strtok(input);
		if (args == NULL || args[0] == NULL)
		{
			free(input);
			continue;
		}
		handle_commands(args, input);
		free_args(args);
		input_process(input);
		free(input);
	}
	free(input);
	return (0);
}
