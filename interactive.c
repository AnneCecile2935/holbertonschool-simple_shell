#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * interactive_shell - Checks if the standard input is a terminal.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive_shell(void)
{
	return (isatty(STDIN_FILENO));
}
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
/**
 * sigint_handler - Handles the SIGINT signal (Ctrl+C).
 * @signum: Signal number (unused).
 *
 * Description: This function is called when the user presses Ctrl+C.
 * It prevents the shell from exiting and reprints the prompt.
 */
void sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n$ ", 3);
}
