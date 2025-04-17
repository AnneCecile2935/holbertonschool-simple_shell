#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int interactive_shell(void);
void print_prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
