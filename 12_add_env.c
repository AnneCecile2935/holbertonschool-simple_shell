#include <stdio.h>
extern char **environ;
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	printf("Adresse env: %p\n", (void*)env);
	printf("Adresse environ: %p\n", (void*)environ);
	return (0);
}