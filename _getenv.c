#include <stdio.h>
#include <string.h>
#include "shell.h"
/**
 * _getenv - Retrieves the value of an environment variable.a64l
 * @path: Name of the environment variable to find (e.g., "PATH").
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if the variable is not found.
 */
char *_getenv(const char *path)
{
	size_t len;
	int i;

	len = strlen(path);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], path, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
			/*return each value after = of environ*/
		}
	}
	return (NULL);
}
