#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * interactive_shell - Vérifie si l'entrée standard est un terminal
 *
 * Return: 1 si le shell est en mode interactif, 0 sinon
 */
int interactive_shell(void)
{
	return (isatty(STDIN_FILENO));
}
/**
 * print_prompt - Affiche un prompt avec un emoji et le nom de l'utilisateur
 *
 * Description: Cette fonction récupère la variable d'environnement USER
 *              et affiche un prompt sous la forme "🔒 username $ ".
 *              Si USER n'est pas défini, elle affiche "🔒 $USER ".
 *
 * Return: Rien (void)
 */
void print_prompt(void)
{
	char *user = getenv("USER");

	if (user)
	{
		write(1, "🔒 ", 4);
		write(1, user, strlen(user));
		write(1, " $ ", 3);
	}
	else
	{
		write(1, "🔒 $USER ", 9);
	}
}
/**
 *
 *
 *
 */
int cutstring(int argc, char *argv[])
{
	
}
