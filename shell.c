#include "shell.h"
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * handle_interactive_mode - Handles the interactive mode of the shell
 * @shell_name: Name of the shell (argv[0]), used in error messages
 * @last_status: Pointer to last command's exit status
 */
void handle_interactive_mode(const char *shell_name, int *last_status)
{
	char *command = NULL; /*store line of command*/
	char **args = NULL;	  /*resutl of stroke line command array*/

	while (1) /*infinite loop for shell be active */
	{
		print_prompt();
		command = read_command(); /*read command and store*/
		if (command == NULL)
		{
			write(STDOUT_FILENO, "\n", 1); /*if NULL, \n*/
			break;						   /*exit to the loop*/
		}

		args = tokenize_string(command); /*store tokens */
		if (args == NULL)
		{
			free(command);
			continue; /*next command */
		}

		if (args[0] && strcmp(args[0], "exit") == 0)
		{
			exit_shell(args, command, *last_status);
			free(args);
			free(command);
			break; /*exit to the loop*/
		}

		*last_status = execute_command(args, environ, (char *)shell_name);
		/*execute command, store code result in*/
		free(args);
		free(command);
	}
}
/**
 * handle_non_interactive_mode - Handles the non-interactive mode of the shell
 * @shell_name: Name of the shell (argv[0]), used in error messages
 * @last_status: Pointer to last command's exit status
 */
void handle_non_interactive_mode(const char *shell_name, int *last_status)
{
	char *command = NULL;
	char **args = NULL;

	while ((command = read_command()) != NULL) /*if read command continue*/
	{
		if (command && *command)
		{
			args = tokenize_string(command); /*line is not empty*/
			if (args != NULL)
			{
				if (args[0] && strcmp(args[0], "exit") == 0)
				/*check command exit*/
				{
					exit_shell(args, command, *last_status); /*exit to shell*/
				}

				*last_status = execute_command(args, environ, (char *)shell_name);
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
 * Return: Last status code
 */
int main(int argc, char **argv)
{
	int last_status;
	(void)argc;
	signal(SIGINT, sigint_handler); /*CTR + C stop and return at new line*/

	if (interactive_shell())
	{
		handle_interactive_mode(argv[0], &last_status);
	}
	else
	{
		handle_non_interactive_mode(argv[0], &last_status);
	}

	return (last_status);
}
