#include "myhell.h"

ssize_t write_char(const char *input)
{
	size_t input_len = strlen(input);
	ssize_t result = 0;

	if (input_len == 0)
	{
		return 0;
	}

	result = write(STDOUT_FILENO, input, input_len);
	if (result == -1)
	{
		perror("Output Error Encountered");
	}
	return result;
}
