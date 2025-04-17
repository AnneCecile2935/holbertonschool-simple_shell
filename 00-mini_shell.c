#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
/**
 * print_prompt - function to print a prompt
 * Return: Nothing
 */
void print_prompt(void)
{
	write(1, "$ ", 2);
}
/**
 * read_command - function to read the command input
 * @len: len of lines to read
 * Return: line read
 */
char *read_command(size_t *len)
{
	char *line = NULL;
	ssize_t read;
	ssize_t i;

	read = getline(&line, len, stdin);
	if (read == -1)
	{
		free(line);
		perror("getline");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < read; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
	}
	return (line);
}
void split_command(char *line, char ***args)
{
	char *token;
	const char *delimit = " ";
	int i = 0;
	int capacity = 10;
	char **temp;
	*args = malloc(capacity * sizeof(char *));
	if (*args == NULL)
	{
		perror("malloc args");
		exit(EXIT_FAILURE);
	}
token = strtok(line, delimit);
while (token != NULL)
{
	if (i >= capacity)
	{
		capacity *= 2;
		temp = realloc(*args, capacity * sizeof(char *));
		if (*temp == NULL)
		{
			free(*args);
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		*args = temp;
	}
	(*args)[i++] = token;
	token = strtok(NULL, delimit);
}
(*args)[i] = NULL;
}
void execute_command(char **args, char **envp)
{
	pid_t pid_child;
	int status;

	if (args[0] == NULL)
	return;
	pid_child = fork();
	if (pid_child < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid_child == 0)
	{
		if (strcmp(args[0], "./ppid") == 0)
		{
			printf("%d\n", getppid());
			exit(EXIT_SUCCESS);
		}
		else
		{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	}
	else
	{
		waitpid(pid_child, &status, 0);
	}
}
int main(int argc, char **argv, char **envp)
{
	
	char *line;
	char **args;
	size_t len;
	(void)argc;
	(void)argv;
line = NULL;
args = NULL;
len = 0;

	while (1)
	{
		print_prompt();
		line = read_command(&len);
		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}
		split_command(line, &args);
		execute_command(args, envp);
		free(args);
		free(line);
	}
	return (0);
}
