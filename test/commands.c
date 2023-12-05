#include "myhell.h"


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
		/* Reset errno to zero to avoid printing "Success" message
		*/
		if (execve(path, (char *const *)args, NULL) == -1)
		{
			perror("./hsh: Command not found(execute)");
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




void execute_ls(const char *args[])
{
	const char *ls_path = "/bin/ls";
	const char *ls_args[] = {"ls", NULL};
	char **ls_command = NULL;

	/* Check if the argument array is NULL or the first argument is NULL */
	if (args == NULL || args[0] == NULL)
	{
		ls_command = process_arguments(ls_args, NULL);
	}
	else
	{
		/* Process the arguments for ls command excluding the first argument ("ls") */
		ls_command = process_arguments(ls_args, args[1]);
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





void execute_pwd(void)
{
	const char *pwd_path = "/bin/pwd";
	const char *pwd_args[] = {"pwd", NULL};

	execute_command(pwd_path, pwd_args);
}

