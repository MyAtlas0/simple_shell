#include "myhell.h"

/*
*
*/

void execute_instruct(const char *instruct)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		shell_print_f("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */

		/* Parse the command and its arguments */
		char *args[128]; /* Maximum 128 arguments (adjust as needed) */
		int arg_count = 0;

		char *token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Null-terminate the arguments array */

		/* Check if the command contains a '/' character */
		/* If it does, assume it's a full path and directly execute it */
		/* Otherwise, search for the command in the system's PATH */
		if (strchr(args[0], '/') == NULL)
		{
			char *env_path = getenv("PATH");
			char *path = strtok(env_path, ":");

			while (path != NULL)
			{
				char command_path[256];
				snprintf(command_path, sizeof(command_path), "%s/%s", path, args[0]);

				execve(command_path, args, NULL);
				path = strtok(NULL, ":");
			}
		}
		else
		{
			execve(args[0], args, NULL);
		}

		/* If execve fails, print an error message */
		shell_print_f("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}
