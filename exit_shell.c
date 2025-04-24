#include "shell.h"

/**
 * exit_shell - Frees memory and exits the shell.
 * @args: Array of arguments to free.
 * @str: Input string to free.
 * @last_status: Exit status to use if no explicit argument is provided.
 *
 * Return: Nothing, exits the program.
 */
void exit_shell(char **args, char *str, int last_status)
{

	int exit_status = 0;

	if (args[1])
		exit_status = atoi(args[1]);
	else
		exit_status = last_status;

	free(args);
	free(str);
	exit(exit_status);
}
