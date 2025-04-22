#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * read_command - Reads a line of input from the user.
 *
 * Description: This function uses getline to read a line from standard input,
 * removes the trailing newline character if present, and returns the input
 * string.
 *
 * Return: Pointer to the input string. Exits on failure.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	ssize_t i;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		exit(0);
	}
	else
	{
		perror("getline");
		free(line);
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
/**
 * tokenize_string - Tokenizes a string into arguments separated by spaces
 * @str: The string to tokenize
 *
 * Return: A NULL-terminated array of strings (tokens), or NULL on failure
 */
char **tokenize_string(char *str)
{
	char **args = malloc(sizeof(char *) * 100);
	int i = 0;
	const char *div = " ";
	char *copy;

	if (args == NULL)
	{
		return (NULL);
	}

	copy = strtok(str, div);

	while (copy != NULL)
	{
		args[i++] = copy;
		copy = strtok(NULL, div);
	}
	args[i] = NULL;
	return (args);
}
