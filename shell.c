#include "shell.h"
#include <string.h>

/**
 * main - Programme de test pour la fonction getline.
 *
 * Return: 0 en cas de succès, 1 en cas d'erreur.
 */
int main(void)
{
	int interactive = interactive_shell();
	char *str;
	char **args;

	str = NULL;
	args = NULL;
	if (interactive)
	{
		while (1)
		{
			print_prompt();
			str = read_command();
			args = tokenize_string(str);
			execute_command(args, environ);
			free(str);
			free(args);

		}
	}
	return (0);
}



