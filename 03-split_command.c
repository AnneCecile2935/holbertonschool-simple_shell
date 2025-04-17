#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char **split_command(char *line)
{
	char * token;
	const char *delimit = " ";
	int i = 0;
	int capacity = 10;
	char **args = malloc(capacity * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
token = strtok(line, delimit);
while (token != NULL)
{
	if (i >= capacity)
	{
		capacity *= 2;
		args = realloc(args, capacity * sizeof(char *));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
	}
	args[i++] = token;
	token = strtok(NULL, delimit);
}
args[i] = NULL;
return (args);
}