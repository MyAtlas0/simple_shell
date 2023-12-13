#include "myhell.h"


/**
 * handle_commands - Process and execute specific commands.
 *
 * @args: Array of strings containing command and arguments.
 *
 * @input: User input string.
 *
 * This function processes specific commands such as 'exit' and 'env'.
 * For 'exit', it handles the command and optional argument (exit status).
 * For 'env', it prints environment variables.
 * For other commands, it invokes the 'handle_other_commands' function.
 */

void handle_commands(char **args, char *input)
{
	int exit_status;

	if (args == NULL || args[0] == NULL)
	{
		return;
		/*No command entered or invalid command; return without further processing*/
	}

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			/*If an argument (exit status) is provided, convert it to an integer*/
			exit_status = _atoi(args[1]);
			free_args(args);
			free(input);
			exit(exit_status); /*Exit with the provided status*/
		}
		else
		{
			/*Handle 'exit' command: Free memory and terminate the shell*/
			free_args(args);
			free(input);
			exit(0);
		}
	}
	else if (strcmp(args[0], "env") == 0)
	{
		/*Handle 'env' command: Print environment variables*/
		handle_env_command(args);
	}
	else
	{
		handle_other_commands(args);
	}
}





/**
 * handle_other_commands - Executes various commands based on input arguments.
 *
 * @args: Array of strings representing command-line arguments.
 *
 * Function checks & executes different commands based on the input arguments.
 * If the command is an absolute or relative path,it's directly executed.
 * Otherwise, it handles specific commands like 'ls', 'pwd',
 * or displays an error message if the command is not recognized.
 */

void handle_other_commands(char **args)
{
	int stderro = fileno(stderr);
	const char *error_message;

	if (args[0][0] == '/' || strstr(args[0], "./") == args[0])
	{
		/*Check if the command contains an absolute or relative path*/
		execute_command(args[0], (const char **)args);
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





/**
 * handle_env_command - Handles 'env' command functionality based on arguments.
 *
 * @args: Arguments passed to the 'env' command.
 */

void handle_env_command(char **args)
{

	if (args[1] != NULL)
	{
		if (strcmp(args[1], "-i") == 0)
		{
			clearenv();
		}
		else if (strcmp(args[1], "-u") == 0 && args[2] != NULL)
		{
			_unsetenv(args[2]);
		}
		else if (args[2] != NULL)
		{
			_setenv(args[1], args[2], 1); /* Set or overwrite */
		}
		else
		{
			fprintf(stderr, "Invalid 'env' command format\n");
		}
	}
	else
	{
		print_environment();
	}
}






/**
 * _atoi - Converts a string to an integer.
 *
 * @s: The string to convert.
 *
 * This function converts a string to an integer.
 * It skips leading whitespace characters and checks for a sign (+ or -).
 * Then, it iterates through the string and converts characters to integers.
 *
 * Return: The resulting integer value(sign * result).
 */

int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/*Skip leading whitespace characters*/
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}

	/*Check for sign (+ or -)*/
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	/*Iterate through the string and convert characters to integers*/
	while (s[i] >= '0' && s[i] <= '9')
	{
		/*Convert character to integer and add to the result*/
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}
