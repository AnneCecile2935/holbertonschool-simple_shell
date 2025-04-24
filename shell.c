#include "shell.h"
#include <string.h>
#include <signal.h>
/**
 * handle_interactive_mode - Handles the interactive mode of the shell
 * @shell_name: Name of the shell (argv[0]), used in error messages
 */
void handle_interactive_mode(const char *shell_name)
{
	char *command = NULL;
	char **args = NULL;
	int last_status = 0;

	while (1)
	{
		print_prompt();
		command = read_command();
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = tokenize_string(command);
		if (args == NULL)
		{
			free(command);
			continue;
		}

		if (args[0] && strcmp(args[0], "exit") == 0)
		{
			exit_shell(args, command, last_status);
			free(args);
			free(command);
			break;
		}

		execute_command(args, environ, (char *)shell_name);
		free(args);
		free(command);
	}
}
/**
 * handle_non_interactive_mode - Handles the non-interactive mode of the shell
 * @shell_name: Name of the shell (argv[0]), used in error messages
 */
void handle_non_interactive_mode(const char *shell_name)
{
	char *command = NULL;
	char **args = NULL;
	int last_status = 0;

	while ((command = read_command()) != NULL)
	{
		if (command && *command)
		{
			args = tokenize_string(command);
			if (args != NULL)
			{
				if (args[0] && strcmp(args[0], "exit") == 0)
				{
					exit_shell(args, command, last_status);
				}

				last_status = execute_command(args, environ, (char *)shell_name);
				free(args);
			}
		}
		free(command);
	}
}
/**
 * main - Entry point of the shell program
 * @argc: Argument count (unused)
 * @argv: Argument vector, used for shell name in error messages
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	(void)argc;
	signal(SIGINT, sigint_handler); /*Ctrl +C*/

	if (interactive_shell())
	{
		handle_interactive_mode(argv[0]);
	}
	else
	{
		handle_non_interactive_mode(argv[0]);
	}

	return (EXIT_SUCCESS);
}
