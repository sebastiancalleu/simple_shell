#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void *_calloc(int, int);
int _strlen(char *);
int wrdcounter(char *);
void splitter(char *, int);
void notcommandfound(char **);
void printnum(int);
void execute(char **, char *);
char *finddir(char *, char *);
char *findpath(char *);
void _strcpy(char *, char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
void check_error(int);
void create_nonInterac_arg_array(int, char **, char ***);
void freearray(char **);

#endif
