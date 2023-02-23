#ifndef SHELL_H
#define SHELL_H

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **tokenize_string(char *line);
extern int execute_cmd(char **args);
void shell_exit(char **args);
extern struct builtinStruct {
    char *name;
    void (*func)(char **args);
};

#endif
