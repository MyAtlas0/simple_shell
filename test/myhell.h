#ifndef MYHELL_H
#define MYHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024


/**  Prototype Functions, It's declarations  **/
int main();
char *read_prompt();
ssize_t write_char(const char *input);
void free_args(char **args);
void input_process(char *input);
void handle_commands(char **args, char *input);
void execute_ls(const char *args[]);
void execute_pwd(void);


/** Custome _Strtok protopype, and helper Function **/
char **_strtok(const char *input);
const char *last_input(const char *last);
const char *skip_spaces(const char *first);
char *_strndup(const char *first, size_t n);
/*
char *_strncpy(char *destination, const char *source, size_t n);
*/


char **process_arguments(const char *args[], const char *commands_args);


#endif /**  MYHELL_H  **/
