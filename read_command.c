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
	if (feof(stdin))
	{
		free(line);
		write(1, "\n", 1);
		exit(0);
	}
	else
	{
		perror("getline");
		free(line);
		exit(EXIT_FAILURE);
	}
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
 * execute_command - Executes a command using fork and execve
 * @args: Array of command and arguments
 * @envp: Environment variables
 * @shell: Name of the shell (argv[0]), used in error messages
 *
 * Return: Nothing
 */
void execute_command(char **args, char **envp, char *shell)
{
	pid_t pid_child;
	int status;

	if (args[0] == NULL)
		return;

	pid_child = fork();

	if (pid_child < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid_child == 0)
	{
		execve(args[0], args, envp);
		perror(shell);
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
