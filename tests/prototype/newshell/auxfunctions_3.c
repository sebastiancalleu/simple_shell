#include "holberton.h"

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
 * notfoundfunc - this function procede with a not-found command.
 * @arg_array: the array of args.
 * @arguments: the arguments.
 * @glcount: count of the getline cycles.
 * @av: array of arguments of the shell.
 */

void notfoundfunc(char **arg_array, char *arguments, int glcount, char **av)
{
	int a;

	write(1, av[0], _strlen(av[0]));
	write(1, ": ", 2);
	printnum(glcount);
	write(1, ": ", 2);
	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 10);
	for (a = 0; arg_array[a]; a++)
		free(arg_array[a]);
	free(arg_array);
	free(arguments);
}

/**
 * execute - this function executes commands in child process.
 * @arg_array: the array of strings.
 * @arguments: the arguments line.
 * @glcount: count of the getline cycles.
 * @av: array of arguments of the shell.
 */

void execute(char **arg_array, char *arguments, int glcount, char **av)
{
	int pid = 0;
	int wstatus; /* store status return signal */
	char *filepath, *notfound = "Command not found";
	struct stat st;

	pid = fork();
	if (pid == -1)
		check_error(pid);
	if (pid != 0)
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			WEXITSTATUS(wstatus);
	}
	if (pid == 0)
	{

		if (stat(arg_array[0], &st) == 0)
		{
			if (execve(arg_array[0], arg_array, environ) == -1)
				check_error(-1);

		}
		else
		{
			filepath = findpath(arg_array[0]);
			if (_strcmp(filepath, notfound) == 0)
			{
				notfoundfunc(arg_array, arguments, glcount, av);
			}
			else
			{
				if (execve(filepath, arg_array, environ) == -1)
					check_error(-1);
				free(filepath);
			}
		}
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
	char *token, *path, *notfound = "Command not found";
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
