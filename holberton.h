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

/*auxfunctions_1*/
void splitter(char *, int, char **, int);
int wrdcounter(char *);
void *_calloc(int, int);

/*auxfunctions_2*/
void execute(char **, char *, char **, int);
void printnum(int);
void create_nonInterac_arg_array(int, char **, char ***);

/*auxfunctions_3*/
char *findpath(char *);
char *finddir(char *, char *);
char *_strcat(char *, char *);

/*auxfunctions_4*/
int _strlen(char *);
void notcommandfound(char **, char **, int);
void exitshell(char **, char *, int);

/*auxfunctions_5*/
void freearray(char **);
void check_error(int);
void envprint(void);

/*auxfunctions_6*/
int _strcmp(char *, char *);
void _strcpy(char *, char *);
void sigint_handler(int);

#endif
