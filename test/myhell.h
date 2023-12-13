#ifndef MYHELL_H
#define MYHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define INITIAL_BUFFER_SIZE 128

/**  Prototype Functions, It's declarations  **/
int main();
int _atoi(char *s);

char *custom_getenv(const char *name, char **envp);
int custom_setenv(const char *name, const char *value, int overwrite);
int custom_unsetenv(const char *name);

char *read_prompt();
ssize_t write_char(const char *input);
void free_args(char **args);
void input_process(char *input);
void handle_commands(char **args, char *input);
void handle_env_command(char **args);
void execute_other_commands(char **args);
void execute_command(const char *path, const char *args[]);
void execute_ls(const char *args[]);
void execute_pwd(void);
void print_environment(void);
extern char **environ;
void clear_environment();

/** Custome _Strtok protopype, and helper Function **/
char **_strtok(const char *input);
char *_strndup(const char *first, size_t n);


char **process_arguments(const char *args[], const char *commands_args);


ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void expand_buffer(char **lineptr, size_t *n);

#endif /**  MYHELL_H  **/
