#include "shell.h"
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
