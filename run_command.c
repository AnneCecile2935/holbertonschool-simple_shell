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
	if (pid == -1) /*if fork fail*/
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /*fork succes, execve replace the*/
	/*current process in program*/
	{
		if (execve(cmd, args, envp) == -1)
		{
			perror(shell);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0); /*parent process wait child terminate*/
		if (WIFEXITED(status))	  /*child end success*/
			return (WEXITSTATUS(status));
		else
			return (1); /*child end failed*/
	}
	return (1); /*security*/
}
