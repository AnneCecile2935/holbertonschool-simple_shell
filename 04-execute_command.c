#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
void execute_command()
{
	pid_t pid_child;
	int status;
	char *pathname;
	char *argv[]=  {"ls", "-l", "/tmp", NULL};
	char *envp[]= {NULL};
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
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	
	else  
	{
		waitpid(pid_child, &status, 0);
	}
}