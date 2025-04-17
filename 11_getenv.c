#include <stdio.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name)
{
	size_t len;
	int i;
	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}

	}
	return (NULL) ;
}
int main(void)
{
    char *path = _getenv("PATH");

    if (path)
        printf("PATH = %s\n", path);
    else
        printf("PATH non trouvé.\n");

    return 0;
}