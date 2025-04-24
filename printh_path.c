#include "shell.h"
/**
 * print_path - Prints the value of the PATH environment variable.
 */
void print_path(void)
{
	char *path = _getenv("PATH");

	if (path)
		printf("%s\n", path);
}
