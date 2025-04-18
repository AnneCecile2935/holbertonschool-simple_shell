#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * read_command - Reads a line of input from the user.
 * @len: Pointer to a size_t that will store the allocated buffer size.
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
/**
 * execute_command - function to execute à partir d'un tableau d'arguments
 * @args: tableau de commande.
 * @envp: Pointeur vers tableau de variable d'environnement.
 * Return: Nothing.
 */
void execute_command(char **args, char **envp)
{
	pid_t pid_child;
	int status;

	if (args[0] == NULL)
	return;
pid_child = fork();
if (pid_child < 0)
{
	perror("processus enfant a échoué");
	exit(EXIT_FAILURE);
}
else if (pid_child == 0)
{
	execve(args[0], args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
else
{
	waitpid(pid_child, &status, 0);
}
}
/**
 * tokenize_string - Tokenizes a string into arguments separated by spaces
 * @str: The string to tokenize
 *
 * Return: A NULL-terminated array of strings (tokens), or NULL on failure
 */
char tokenize_string(char *str)
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
