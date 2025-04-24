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
    char *command = NULL;
    char **args = NULL;

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
            exit_shell(args, command, *last_status);
            free(args);
            free(command);
            break;
        }

        *last_status = execute_command(args, environ, (char *)shell_name);

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

    while ((command = read_command()) != NULL)
    {
        if (command && *command)
        {
            args = tokenize_string(command);
            if (args != NULL)
            {
                if (args[0] && strcmp(args[0], "exit") == 0)
                {
                    exit_shell(args, command, *last_status);
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
    signal(SIGINT, sigint_handler);

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
