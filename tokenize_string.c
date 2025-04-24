#include "shell.h"

/**
 * tokenize_string - Tokenizes a string into arguments separated by spaces.
 * @str: The string to tokenize.
 *
 * Return: A NULL-terminated array of strings (tokens), or NULL on failure.
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
