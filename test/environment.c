#include "myhell.h"


/**
 * print_environment - Prints the current environment variables to stderr.
 *
 * This function prints the current environment variables to stderr.
 * It retrieves the environment variables and writes it line by line to stderr.
 */

void print_environment(void)
{
	char **env = environ;
	const char *message = "Current Environment:\n";
	const int stderro = fileno(stderr); /*Get file descriptor for stderr*/

	/*Write the message to stderr*/
	write(stderro, message, _strlen(message));

	/*Print the current environment variables*/
	while (*env != NULL)
	{
		write(stderro, *env, _strlen(*env));
		write(stderro, "\n", 1);
		env++;
	}
}





/**
 * _getenv - Retrieve the value of an environment variable.
 *
 * @name: Name of the environment variable.
 *
 * @envp: Pointer to the environment variables.
 *
 * Return: Pointer to the value of the environment variable if found,
 * NULL otherwise.
 */

char *_getenv(const char *name, char **envp)
{
	size_t name_len = _strlen(name);
	char **env;

	if (name == NULL || envp == NULL)
	{
		return (NULL);
	}

	for (env = envp; *env != NULL; ++env)
	{
		if (_strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
	}

	return (NULL);
}




/**
 * _setenv - Set or update an environment variable.
 *
 * @name: Name of the environment variable.
 *
 * @value: Value to be assigned to the environment variable.
 *
 * @overwrite: Flag indicating whether to overwrite if the variable exists (1)
 * or not (0).
 *
 * Return: 0 on success, -1 on failure.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len = _strlen(name);
	size_t value_len = _strlen(value);
	size_t entry_len = name_len + value_len + 2;
	char *env_entry = (char *)malloc(entry_len);
	int result = putenv(env_entry);

	if (name == NULL || value == NULL)
	{
		errno = EINVAL;
		write(fileno(stderr), "Invalid arguments\n", _strlen("Invalid arguments\n"));
		return (-1);
	}
	if (!overwrite && _getenv(name, environ) != NULL)
	{
		return (0);
	}
	if (env_entry == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}

	/* Using write to concatenate strings into env_entry */
	write(fileno(stderr), name, name_len);
	write(fileno(stderr), "=", 1);
	write(fileno(stderr), value, value_len);

	env_entry[entry_len - 1] = '\0'; /* Null-terminate the string */
	if (result != 0)
	{
		perror("Failed to set environment variable");
		free(env_entry);
		return (-1);
	}
	return (0);
}




/**
 * _unsetenv - Unset or remove an environment variable.
 *
 * @name: Name of the environment variable to be unset.
 *
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(const char *name)
{
	int result = unsetenv(name);

	if (name == NULL)
	{
		errno = EINVAL;
		write(fileno(stderr), "Invalid argument\n", _strlen("Invalid argument\n"));
		return (-1);
	}

	/*Attempt to unset the environment variable*/
	if (result != 0)
	{
		perror("Failed to unset environment variable");
		return (-1);
	}

	return (0);
}
