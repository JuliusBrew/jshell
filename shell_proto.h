#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum command length
#define MAX_COMMAND_LENGTH 100

// Function prototypes
void shell();
void exit_shell();
void print_error(const char *);
void parse_args();
void execute_command(const char *);
// Declaration of the external environ variable
extern char **environ; 

#endif

