#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int interactive_shell(void);
void print_prompt(void);
char *read_command(void);
char *_getenv(const char *path);
void print_path(void);
int find_command_in_path(char *command, char *full_path);
void execute_command(char **args, char **envp, char *shell);
char **tokenize_string(char *str);

#endif
