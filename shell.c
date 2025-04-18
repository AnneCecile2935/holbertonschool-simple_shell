#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Programme de test pour la fonction getline.
 *
 * Return: 0 en cas de succès, 1 en cas d'erreur.
 */
int main(void)
{
	int interactive = interactive_shell();
	char *buffer = NULL;
	size_t size = 0;
	ssize_t nread;

	if (interactive)
	{
		while (1)
		{
			print_prompt();
			nread = getline(&buffer, &size, stdin);
			if (nread == -1)
			{
				write (1, "\n", 1);
				free(buffer);
				exit(0);
			}
		}
	}
	free(buffer);
	return (0);
}
