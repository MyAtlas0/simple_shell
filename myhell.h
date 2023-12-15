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

/**  Prompt Prototype, And it's Helper Functions  **/

int main(void);
ssize_t write_char(const char *input);
char *read_prompt();
void free_args(char **args);
void input_process(char *input);


/** Custom_GetLine Function, It's declarations **/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void expand_buffer(char **lineptr, size_t *n);
void *_realloc(void *ptr, size_t new_size);



/** Custom_Strtok Function, It's declaration **/

char **_strtok(const char *input);



/** Custom_String Functions, Their declarations **/

size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strndup(const char *first, size_t n);
char *_strncpy(char *destination, const char *source, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);


/** Commands Prototype Functions, It's declarations **/

char **process_arguments(const char *args[], const char *commands_args);
void execute_command(const char *path, const char *args[]);
void execute_ls(const char *args[]);
void execute_pwd(void);



/** Environment Functions, It's declarations **/

extern char **environ;
void print_environment(void);
char *_getenv(const char *name, char **envp);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);



/** Handle_Commands Prototype, And it's Helper Functions. **/

int _atoi(char *s);
void handle_commands(char **args, char *input);
void handle_env_command(char **args);
void handle_other_commands(char **args);
/*void handle_semicolon_commands(char *input);
*/
#endif /**  MYHELL_H  **/
