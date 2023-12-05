#include "myhell.h"

char *read_prompt()
{
	char *input = NULL;
	size_t buffer = 0;
	ssize_t read;
	int interactive;

	interactive = isatty(STDIN_FILENO);
	if (interactive)
	{
		write_char("Rain^_^: ");
		fflush(stdout);
	}

	read = getline(&input, &buffer, stdin);
	if(read == -1)
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




int main()
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
	return (0);
}
