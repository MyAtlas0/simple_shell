#include "myhell.h"

void handle_commands(char **args, char *input)
{
	int stderro = fileno(stderr);
	const char *error_message;

	if (args == NULL || args[0] == NULL)
	{
		return;
		/* No command entered or invalid command; return without further processing */
	}

	if (strcmp(args[0], "exit") == 0)
	{
		/* Handle 'exit' command: Free memory and terminate the shell */
		free_args(args);
		free(input);
		exit(0);
	}
	else if (strcmp(args[0], "ls") == 0)
	{
		/* Handle 'ls' command: Execute ls with provided arguments */
		execute_ls((const char **)args);
	}
	else if (strcmp(args[0], "pwd") == 0)
	{
		/* Handle 'pwd' command: Execute pwd to print current working directory */
		execute_pwd();
	}
	else
	{
		/* Command not recognized; Display an error message */
		error_message = "command not found: ";
		write(stderro, error_message, strlen(error_message));
		write(stderro, args[0], strlen(args[0]));
		write(stderro, "\n", 1);
	}
}





char **process_arguments(const char *args[], const char *commands_args)
{
	size_t count = 0;
	size_t i;
	char **handled_args;

	while (args[count] != NULL)
	{
		count++;
	}

	/* Allocate memory for the array of arguments
	*/
	handled_args = malloc(sizeof(char *) * (count + 2));
	if (handled_args == NULL)
	{
		perror("Memory allocation failed(Allocate memory)");
		exit(1);
	}

	/* Copy the arguments into the new array
	*/
	for (i = 0; i < count; i++)
	{
		handled_args[i] = strdup(args[i]);
		if (handled_args[i] == NULL)
		{
			perror("Memory allocation failed(copy argument)");
			exit(1);
		}
	}

	/* Add the additional command argument if provided
	*/
	if (commands_args != NULL)
	{
		handled_args[count] = strdup(commands_args);
		if (handled_args[count] == NULL)
		{
			perror("Memory allocation failed(additional argument)");
			exit(1);
		}
		count++;
	}
	handled_args[count] = NULL;     /* Terminate the array */

	return handled_args;
}
