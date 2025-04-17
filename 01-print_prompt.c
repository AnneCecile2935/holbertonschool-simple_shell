#include <unistd.h>
/**
 * print_prompt - function to print a prompt
 * Return: Nothing
 */
void print_prompt(void)
{
	write(1, "$ ", 2);
}
