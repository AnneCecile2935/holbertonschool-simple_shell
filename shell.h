#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int interactive_shell(void);
void print_prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *read_command(void);
void execute_command(char **args, char **envp);
char tokenize_string(char *str);

#endif
