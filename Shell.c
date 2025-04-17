#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Programme de test pour la fonction getline.
 *
 * Return: 0 en cas de succès, 1 en cas d'erreur.
 */
int main(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t nread;

	while (1)
	{
		write(1, "$USER\n", 6);
		nread = getline(&buffer, &size, stdin);
		if (nread == -1)
	{
		free(buffer);
		exit(0);
	}
	}
	free(buffer);
	return (0);
}
