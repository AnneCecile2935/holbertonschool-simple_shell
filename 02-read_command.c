#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * read_command - function to read the command input
 * @len: len of lines to read
 * Return: line read
 */
char *read_command(size_t *len)
{
	char *line = NULL;
	ssize_t read;
	ssize_t i = 0;

	read = getline(&line, len, stdin);
	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < read; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
	}
	return (line);
}
