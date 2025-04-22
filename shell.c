#include "shell.h"
#include <string.h>

/**
 * main - Entry point of the shell program
 * @argc: Argument count (unused)
 * @argv: Argument vector, used for shell name in error messages
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int interactive = interactive_shell();
	char *str = NULL;
	char **args = NULL;

	(void)argc; /* unused, but avoids compiler warning */

	if (interactive)
	{
		while (1)
		{
			print_prompt();
			str = read_command();
			args = tokenize_string(str);
			execute_command(args, environ, argv[0]);
			free(args);
			free(str);
		}
	}
	else
	{
		while ((str = read_command()) != NULL)
		{
			if (str && *str)
			{
				args = tokenize_string(str);
				execute_command(args, environ, argv[0]);
				free(args);
			}
			free(str);
		}
	}
	return (0);
}
