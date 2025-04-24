#include "shell.h"

/**
 * print_prompt - Displays a simple prompt with a lock emoji.
 *
 * Description: Prints the prompt "🔒 " to indicate the shell is ready.
 * for user input. No username or additional information is included.
 *
 * Return: Nothing (void).
 */

void print_prompt(void)
{
	write(1, "$ ", 2);
}
