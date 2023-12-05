#include "myhell.h"

void input_process(char *input)
{
	if (input == NULL)
	{
		return;
	}
}





void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

