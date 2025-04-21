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
 * print_prompt - Displays a simple prompt with a lock emoji
 *
 * Description: Prints the prompt "🔒 " to indicate the shell is ready
 * for user input. No username or additional information is included.
 *
 * Return: Nothing (void)
 */

void print_prompt(void)
{
	write(1, "🔒 ", 5);
}
