#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * run_command - Forks and executes a command.
 * @cmd: Path to command.
 * @args: Arguments array.
 * @envp: Environment variables.
 * @shell: Program name (for error messages).
 * Return: Error code
 */
int run_command(char *cmd, char **args, char **envp, char *shell)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1) /*si le fork echoue*/
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /*le fork reussi, execve remplace le*/
	/*processus courant dans le programme*/
	{
		printf("Im forking la, laisse moi dormir");
		if (execve(cmd, args, envp) == -1)
		{
			perror(shell);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0); /*processus parent attend que l'enfant se termine*/
		if (WIFEXITED(status))	  /*l'enfant termine normalement*/
			return (WEXITSTATUS(status));
		else
			return (1); /*l'enfant se termine anormalement*/
	}
	return (1); /*sécurité*/
}

/**
 * print_path - Prints the value of the PATH environment variable.
 */
void print_path(void)
{
	char *path = _getenv("PATH");

	if (path)
		printf("%s\n", path);
}

/**
* find_command_in_path - Searches for an executable in PATH directories.
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
