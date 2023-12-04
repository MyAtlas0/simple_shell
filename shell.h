#ifndef SHELL_H
#define SHELL_H
/*
 *include libraries
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 *functions
 */
void shell_print_f(const char *message);
void display_prompt(void);
void read_instruct(char *instruct, size_t size);
void execute_instruct(const char *command);


#endif /* SHELL_H */
