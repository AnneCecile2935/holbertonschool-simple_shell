#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
int file_exists(const char *path)
{
	struct  stat st;
		if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
			return (1);
		return (0);
	}
int _which_filename(const char *filename)
{
	char *path_env;
	char *token;
	char *path_copy;
	size_t len;
	int found = 0;
	char *full_path;
if (strcmp(filename, "PATH") == 0)
{
	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "PATH not found\n");
		return (1);
	}
	printf("PATH=%s\n", path_env);
	return (0);
}
path_env = getenv("PATH");
if (path_env == NULL)
{
	fprintf(stderr, "PATH not found\n");
		return (1);
}
path_copy = strdup(path_env);
if(path_copy == NULL)
{
	perror("strdup");
	return (1);
}
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			len = strlen(token) + strlen(filename) + 2;
			full_path = malloc(len);
			if(!full_path)
			{
				perror("malloc");
				free(path_copy);
				return (1);
			}
			snprintf(full_path, len, "%s/%s", token, filename);
			printf("Checking: %s\n", full_path);
		if (file_exists(full_path))
		{
			printf("%s\n", full_path);
			found = 1;
			free(full_path);
			break;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	if (!found)
	{
		printf("%s not found in PATH\n", filename);
	
	}
	free(path_copy);
	return (found ? 0 : 1);
}
int main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s command1 [command2 ...]\n", argv[0]);
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		_which_filename(argv[i]);
	}

	return (0);
}