#include "shell.h"

/**
 * read_command - Reads a line of input from the user.
 *
 * Description: This function uses getline to read a line from standard input,
 * removes the trailing newline character if present, and returns the input
 * string.
 *
 * Return: Pointer to the input string. NULL if EOF.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	ssize_t i;

	read = getline(&line, &len, stdin);
	/*read until \n ou EOF*/
	if (read == -1) /*nothing read*/
	{
		free(line);
		return (NULL);
	}

	for (i = 0; i < read; i++) /*delete return line, replace \n par '\0'*/
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
	}
	return (line);
}
