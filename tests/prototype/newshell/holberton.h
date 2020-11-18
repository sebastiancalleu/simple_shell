#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/*auxfunctions_1*/
char *_strcat(char *, char *);
int _strcmp(char *, char *);
void _strcpy(char *, char *);
int _strlen(char *);
int wrdcounter(char *);

/*auxfunctions_2*/
void free_arguments(char ***, char **);
void create_memstrings(char **, char **, int);
void copybytes_memstrings(char **, char **, int);
void splitter(char **, char ***, int);
int get_arguments(char **, char ***);

/*auxfunctions_3*/
void check_error(int);
void notfoundfunc(char **, char *);
void execute(char **, char *);
char *findpath(char *);
char *finddir(char *, char *);

int check_exit(char *);

#endif
