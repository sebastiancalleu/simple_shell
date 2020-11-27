#include "holberton.h"

/**
 * findpath - this functions find the path.
 * @arg: this is the command.
 * Return: the path.
 */

char *findpath(char *arg)
{
	int a;
	char *token, *envline, *directories, *currentpath;

	for (a = 0; environ[a]; a++)
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
	return (currentpath);
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
		path = malloc(sizeof(char) * (_strlen(token) + _strlen(arg) + 2));
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
		return (notfound);
}


/**
 * _strcat - this function concatenates two strings.
 * @str1: first string.
 * @str2: second string.
 * Return: the concatened string.
*/

char *_strcat(char *str1, char *str2)
{
	int a, b;

	for (a = 0; str1[a]; a++)
	{
	}
	for (b = 0; str2[b]; b++)
	{
		str1[a] = str2[b];
		a++;
	}
	str1[a] = '\0';
	return (str1);
}
