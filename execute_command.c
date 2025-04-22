#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * run_command - Forks and executes a command
 * @cmd: Path to command
 * @args: Arguments array
 * @envp: Environment variables
 * @shell: Program name (for error messages)
 */
void run_command(char *cmd, char **args, char **envp, char *shell)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(cmd, args, envp);
		perror(shell);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * print_path - Prints the value of the PATH environment variable
 */
void print_path(void)
{
	char *path = _getenv("PATH");

	if (path)
		printf("%s\n", path);
}

/**
 * find_command_in_path - Searches for an executable in PATH directories
 * @command: Command to locate
 * @full_path: Buffer to store full path if found
 *
 * Return: 1 if command is found and executable, 0 otherwise
 */
int find_command_in_path(char *command, char *full_path)
{
	char *path = _getenv("PATH"), *path_copy, *token;

	if (!path)
		return (0);

	path_copy = strdup(path);
	if (!path_copy)
		return (0);

	token = strtok(path_copy, ":");
	while (token)
	{
		snprintf(full_path, 1024, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

/**
 * execute_command - Handles built-ins and executes external commands
 * @args: Array of command and arguments
 * @envp: Environment variables
 * @shell: Shell name (argv[0]), used in error messages
 */
void execute_command(char **args, char **envp, char *shell)
{
	char buffer_path[1024];
	int index;

	if (args[0] == NULL)
		return;

	if (strcmp(args[0], "env") == 0)
	{
		for (index = 0; environ[index]; index++)
			printf("%s\n", environ[index]);
		return;
	}
	if (strcmp(args[0], "path") == 0)
	{
		print_path();
		return;
	}
	if (access(args[0], X_OK) == 0)
	{
		run_command(args[0], args, envp, shell);
		return;
	}
	if (find_command_in_path(args[0], buffer_path))
	{
		run_command(buffer_path, args, envp, shell);
		return;
	}
	fprintf(stderr, "%s: 1: %s: not found\n", shell, args[0]);
}
