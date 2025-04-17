#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
	int num_child;
	pid_t pid_child;
	int status;
	char *pathname; 
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	char *envp [] = {NULL};
	for (num_child = 0; num_child <= 5; num_child++)
	{
		pid_child = fork();
		if (pid_child < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid_child == 0)
		{
		pathname = "/bin/ls";
	
		if (execve(pathname, argv, envp) == -1)
		{
			perror ("execve");
			exit(EXIT_FAILURE);
		}
		printf("Je suis le processus enfant. Mon PID est : %d\n", getpid());
		printf("Le PID de mon parent est : %d\n", getppid());
		}
		else {
			waitpid(pid_child, &status, 0);
if (WIFEXITED(status))
{
	printf("le processu enfant %d sorti avec le statut : %d\n",pid_child, WEXITSTATUS(status));
}
else
{
	printf("Le processu enfant %d n'est pas sorti normalement\n", pid_child);
}
		}
		}
		return (0);	
	}