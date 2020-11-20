#include "holberton.h"

/**
 * check_exit - this function checks for exit arg.
 * @arguments: the arguments line.
 * Return: the status.
 */
int check_exit(char *arguments)
{
	char *exit = "exit";
	int i = 0;
	int bytes = 0;
	int status = 0;

	for (; arguments[i]; i++)
	{
		if (arguments[i] != ' ')
			if (arguments[i] == exit[bytes])
				bytes++;
	};
	if (bytes == 4)
		status = -1;
	return (status);
}

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
	}
}

/**
 * notfoundfunc - this function procede with a not-found command.
 * @arg_array: the array of args.
 * @glcount: count of the getline cycles.
 * @av: array of arguments of the shell.
 */
void notfoundfunc(char **arg_array, int glcount, char **av)
{

	write(1, av[0], _strlen(av[0]));
	write(1, ": ", 2);
	printnum(glcount);
	write(1, ": ", 2);
	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 10);
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
