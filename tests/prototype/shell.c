#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> /* remove when make own version of strtok */
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

void execute(char **);
char *finddir(char *, char *);
char *findpath(char *);
void _strcpy(char *, char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
void check_error(int);

extern char **environ;
/**
 * main - this function work as a shell
 * Return: 0 if success.
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int characters = 0;
	int a = 0;

	while (characters != -1)
	{
		printf("$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters < 0)
		{
			free(buffer);
			exit(0);
		}
		a = wrdcounter(buffer);
		splitter(buffer, a);
		free(buffer);
		/* buffer = NULL; */
	}
	return (0);
}

/**
 * splitter - this function split a string into an array of strings.
 * @s: string to split.
 * @wrdc: number of words in the string.
 */

void splitter(char *s, int wrdc)
{
	int a = 0, b = 0;
	char *token = strtok(s, " \n");
	char **array;

	array = _calloc((wrdc + 1), sizeof(char *));
	for (a = 0; token != NULL; a++)
	{
		array[a] = _calloc((_strlen(token) + 1), sizeof(char));
		if (array[a] == NULL)
		{
			while (b < a)
				free(array[b]), b++;
			free(array);
		}
		_strcopy(array[a], token);
		token = strtok(NULL, " \n");
	}
	array[a] = NULL;
	/* aqui debe ir nuestro codigo para seleccionar funcion segun el array*/
	execute(array);
	for (a = 0; a < wrdc; a++)
		free(array[a]);
	free(array);
}

/**------------ EXECUTIONS */
void execute(char **arg_array)
{
	int pid = 0, freec = 0;
	int wstatus; /* store status return signal */
	char *filepath, *notfound = "Command not found";
	struct stat st;

	/* define processes according to pipes */

	pid = fork();
	if (pid == -1)
		check_error(pid);
	if (pid != 0)
	{
	wait(&wstatus);
	/* return exit code if process terminated ok */
	if (WIFEXITED(wstatus))
		WEXITSTATUS(wstatus);
	}
	if (pid == 0)
	{
		/* child process */
		/**** use envieron to find paths ****/

		/**** use stat to look for file susing path
		 * handle error if file not found ****/

		/*** get new variable with found path and
		 * passit to execve as argument 1 ****/
		if (stat(arg_array[0], &st) == 0)
		{
			if(execve(arg_array[0], arg_array, environ) == -1)
				printf("Error\n");
				/* check_error(-1); */

		}
		else
		{
			filepath = findpath(arg_array[0]);
			if(_strcmp(filepath, notfound) == 0)
			{
				for (freec = 0; arg_array[freec]; freec++)
					free(arg_array[freec]);
				free(arg_array);
				/*free(filepath);*/
				printf("command not found\n");
			}
			else
			{
			if(execve(filepath, arg_array, environ) == -1)
			free(filepath);
			printf("Error\n");
			/* check_error(-1); */
			}
		}
		/* kill child process at exit (provisional)*/
		kill(getpid(), SIGKILL);
	}
}

/**
 * findpath - this functions find the path.
 * @arg: this is the command.
 * Return: the path.
 */

char *findpath(char *arg)
{
	int a;
	char *token, *envline, *directories, *currentpath;

	for(a = 0; environ[a]; a++)
	{
		envline = malloc(sizeof(char) * (_strlen(environ[a]) + 1));
		_strcpy(envline, environ[a]);
		token = strtok(envline, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			directories = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(directories, token);
			currentpath = finddir(directories, arg);
			free(directories);
		}
		free(envline);
	}
	return(currentpath);
}

/**
 * finddir - this function finds the dir for the file.
 * @directories: the directories in the PATH
 * @arg: the file.
 * Return: the path.
 */

char *finddir(char *directories, char *arg)
{
	char *token, *path, *notfound = "command not found";
	int count = 0;
	struct stat st;

	token = strtok(directories, ":");
	while (token != NULL)
	{
		path = malloc(sizeof(char) * (_strlen(token) + _strlen (arg) + 2));
		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, arg);
		if (stat(path, &st) == 0)
		{
			count++;
			break;
		}
		token = strtok(NULL, ":");
		free(path);
	}
	if (count == 1)
		return (path);
	else
		return(notfound);
}

/**---------- HELPER */
/**
 * check_error - checks status of error
 * @error: number to check
 * Description: if error is -1 then print
 * error message and errno description of
 * the error
 *
 * Return: nothing
 */
void check_error(int error)
{
	if (error == -1)
	{
		perror("Error");
		exit(1);
	}
}

/**
 * _strcat - this function concatenates two strings.
 * @str1: first string.
 * @str2: second string.
 * Result: the concatened string.
*/

char *_strcat(char *str1, char *str2)
{
	int a, b;

	for(a = 0; str1[a]; a++)
	{
	}
	for(b = 0; str2[b]; b++)
	{
		str1[a] = str2[b];
		a++;
	}
	str1[a] = '\0';
	return(str1);
}
/**
 * _strcmp - this function compares two strings.
 * @str1 = first string.
 * @str2 = second string.
 * Return = 0 if success, -1 if it fail
 */

int _strcmp(char *str1, char *str2)
{
	int a;

	for(a = 0; (str1[a] && str2[a]); a++)
	{
		if (str1[a] != str2[a])
			return (-1);
	}
	return (0);
}

/**
 * _strcopy - this function copies a string to other string.
 * @dest: the destination string.
 * @src: the source string.
 */

void _strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
}