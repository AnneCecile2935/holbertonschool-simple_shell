#include "shell.h"

/**
 * execute_command - Handles built-ins and executes external commands.
 * @args: Array of command and arguments.
 * @envp: Environment variables.
 * @shell: Shell name (argv[0]), used in error messages.
 *
 * Return: error code (0 = success, 127 = not found, other = error)
 */
int execute_command(char **args, char **envp, char *shell)
{
	char buffer_path[1024];
	int index;

	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		for (index = 0; environ[index]; index++)
			printf("%s\n", environ[index]);
		return (0);
	}

	if (strcmp(args[0], "path") == 0)
	{
		print_path();
		return (0);
	}

	if (strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) == 0)
			return (run_command(args[0], args, envp, shell));

		fprintf(stderr, "%s: 1: %s: not found\n", shell, args[0]);
		return (127);
	}

	if (find_command_in_path(args[0], buffer_path, shell))
	{
		return (run_command(buffer_path, args, envp, shell));
	}

	fprintf(stderr, "%s: 1: %s: not found\n", shell, args[0]);
	return (127);
}
