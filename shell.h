#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;
void handle_interactive_mode(const char *shell_name);
void handle_non_interactive_mode(const char *shell_name);
int interactive_shell(void);
void print_prompt(void);
char *read_command(void);
char *_getenv(const char *path);
void print_path(void);
void exit_shell(char **args, char *str, int last_status);
int run_command(char *cmd, char **args, char **envp, char *shell);
int find_command_in_path(char *command, char *full_path, char *shell);
int execute_command(char **args, char **envp, char *shell);
char **tokenize_string(char *str);
void sigint_handler(int signum);

#endif
