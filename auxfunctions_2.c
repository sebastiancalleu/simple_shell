#include "holberton.h"


/**
 * execute - this function execute commands.
 * @arg_array: the strings of arrays.
 * @str: the buffer line.
 * @av: arguments array.
 * @count: cycle count.
 */

void execute(char **arg_array, char *str, char **av, int count)
{
	int pid = 0;
	int wstatus; /* store status return signal */
	char *filepath, *notfound = "command not found";
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
				notcommandfound(arg_array, av, count);
				free(str);
			}
			else
			{
				if (execve(filepath, arg_array, environ) == -1)
				{
					freearray(arg_array);
					check_error(-1);
				}
			}
		}
		kill(getpid(), SIGKILL);
	}
}

/**
 * printnum - this function prints a number to stdoutput
 * @a: the number to print
 */

void printnum(int a)
{
	int b;
	char c, d, e;

	if (a >= 10)
	{
		b = a % 10;
		a = a / 10;
		if (a >= 10)
		{
			printnum(a);
			c = b + '0';
			write(1, &c, 1);
		}
		else
		{
			d = a + '0';
			write(1, &d, 1);
			e = b + '0';
			write(1, &e, 1);
		}
	}
	else
	{
		d = a + '0';
		write(1, &d, 1);
	}
}

/**
 * create_nonInterac_arg_array - create arg_array for non interactive mode
 * @ac: arguments count
 * @av: argouments values
 * @arg_array: empty arg_array
 * Return: nothing
 */
void create_nonInterac_arg_array(int ac, char **av, char ***arg_array)
{
	int i = 0;

	*arg_array = malloc(ac * sizeof(char *));
	for (i = 0; i < ac - 1; i++)
	{
		(*arg_array)[i] = malloc((_strlen(av[i + 1]) + 1) * sizeof(char));
		_strcpy((*arg_array)[i], av[i + 1]);
	}
	(*arg_array)[i] = NULL;
}
