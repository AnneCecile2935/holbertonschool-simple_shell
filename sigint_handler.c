#include "shell.h"

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
	fflush(stdout); /*force buffer empty*/
}
