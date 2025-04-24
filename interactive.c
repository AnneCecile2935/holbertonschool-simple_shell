#include "shell.h"

/**
 * interactive_shell - Checks if the standard input is a terminal.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive_shell(void)
{
	return (isatty(STDIN_FILENO));
}
