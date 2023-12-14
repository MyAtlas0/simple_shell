#include "myhell.h"

/**
 * execute_command - Execute a command.
 *
 * @path: Path of the command to execute.
 *
 * @args: Arguments for the command.
 *
 * This function forks a child process to execute a command specified by the
 * path using execve system call. It waits for the child process to complete
 * and, returns the status.
 */

void execute_command(const char *path, const char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh: Fork error");
		exit(2);
	}
	else if (child_pid == 0)
	{
		/* Reset errno to zero to avoid printing "Success" message */
		if (execve(path, (char *const *)args, NULL) == -1)
		{
			perror("./hsh: Command not found(execute) ");
			exit(2);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Wait failed");
			exit(EXIT_FAILURE);
		}
	}
}




/**
 * process_arguments - Process the command arguments.
 *
 * @args: Array of command arguments.
 *
 * @commands_args: Additional command argument, if provided.
 *
 * Return: Handled arguments in a newly allocated array.
 */

char **process_arguments(const char *args[], const char *commands_args)
{
	size_t count = 0;
	size_t i;
	char **handled_args;

	while (args[count] != NULL)
	{
		count++;
	}
	/*Allocate memory for the array of arguments*/
	handled_args = malloc(sizeof(char *) * (count + 2));
	if (handled_args == NULL)
	{
		perror("Memory allocation failed(Allocate memory)");
		exit(1);
	}
	/*Copy the arguments into the new array*/
	for (i = 0; i < count; i++)
	{
		handled_args[i] = _strndup(args[i], strlen(args[i]));
		if (handled_args[i] == NULL)
		{
			perror("Memory allocation failed(copy argument)");
			exit(1);
		}
	}
	/*Add the additional command argument if provided*/
	if (commands_args != NULL)
	{
		handled_args[count] = _strndup(commands_args, strlen(commands_args));
		if (handled_args[count] == NULL)
		{
			perror("Memory allocation failed(additional argumnt)");
			exit(1);
		}
		count++;
	}
	handled_args[count] = NULL;     /*Terminate the array*/

	return (handled_args);
}





/**
 * execute_ls - Execute 'ls' command with arguments.
 *
 * @args: Arguments array passed to the 'ls' command.
 *
 * This function executes the 'ls' command using execute_command function with
 * provided arguments. If arguments are NULL or empty, it executes 'ls' without
 * arguments. It handles the memory allocation for 'ls' command and arguments.
 */

void execute_ls(const char *args[])
{
	const char *ls_path = "/usr/bin/ls";
	const char *ls_args[] = {"ls", NULL};
	char **ls_command = NULL;

	/* Check if the argument array is NULL or the first argument is NULL */
	if (args == NULL || args[0] == NULL)
	{
		ls_command = process_arguments(ls_args, NULL);
	}
	else
	{
		/* Process the arguments for ls command excluding the first argument("ls") */
		ls_command = process_arguments(args, NULL);
	}

	/* Ensure ls_command is not NULL before executing the command */
	if (ls_command == NULL)
	{
		perror("Memory allocation failed or invalid arguments.(execute_ls)");
		return;
	}
	execute_command(ls_path, (const char **)ls_command);
	free_args(ls_command);
}





/**
 * execute_pwd - Execute 'pwd' command.
 *
 * This function executes the 'pwd' command using the execute_command function
 * without any arguments. It calls execute_command with the path for 'pwd'
 * command and NULL for arguments.
 */

void execute_pwd(void)
{
	const char *pwd_path = "/usr/bin/pwd";
	const char *pwd_args[] = {"pwd", NULL};

	execute_command(pwd_path, pwd_args);
}
