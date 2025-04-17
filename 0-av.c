#include <stdio.h>
/**
 * main - function to print all arguments
 * @ac: number of arguments
 * @ag: arguments
 * Return: 0.
 */
int main(int ac, char **ag)
{
	int i;
		for (i = 0; ag[i] != NULL; i++)
		printf("Arguments %d, %s\n", i, ag[i]);
	return (0);
}
