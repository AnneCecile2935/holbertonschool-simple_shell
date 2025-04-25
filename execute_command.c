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

	if (strcmp(args[0], "env") == 0) /*compare arg 0 with env*/
	{
		for (index = 0; environ[index]; index++)
			printf("%s\n", environ[index]);/*print each env variable*/
		return (0);
	}

	if (strcmp(args[0], "path") == 0)/*compare arg 0 with path*/
	{
		print_path();
		return (0);
	}

	if (strchr(args[0], '/'))/* check that begin with '/'*/
	{
		if (access(args[0], X_OK) == 0) /*executable?*/
			return (run_command(args[0], args, envp, shell));

		fprintf(stderr, "%s: 1: %s: not found\n", shell, args[0]);
		return (127);
	}

	if (find_command_in_path(args[0], buffer_path, shell))
	{
		return (run_command(buffer_path, args, envp, shell));
	}

	fprintf(stderr, "%s: 1: %s: not found\n", shell, args[0]);
	/*no command found*/
	return (127);
}
