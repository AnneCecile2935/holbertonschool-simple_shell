#include "shell.h"

/* find_command_in_path - Searches for an executable in PATH directories.
* @command: Command to locate.
* @full_path: Buffer to store full path if found.
* @shell: Shell name (unused here but for consistency)

* Return: 1 if command is found and executable, 0 otherwise.
*/
int find_command_in_path(char *command, char *full_path, char *shell)
{
	char *path = _getenv("PATH"), *path_copy, *token;
	(void)shell;

	if (!path || path[0] == '\0')
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
