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
#include <sys/errno.h>

extern char **environ;
extern int errno;

/*auxfunctions_1*/
char *_strcat(char *, char *);
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
void execute(char ***, int, char **);
int find_path(char ***);
void create_paths(char *, char ***);
void recursion_fill_path(char *, char ***, int, int);
int compare_paths(char ***, char ***);

/*auxfunctions_4*/
void create_nonInterac_arg_array(int, char **, char ***);
void sigint_handler(int);
int check_file(char *);

/*auxfunctions_5*/
int check_exit(char *);
void check_error(int);
void notfoundfunc(char **, int, char **);
void printnum(int);

#endif
