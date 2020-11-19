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
 * sigint_handler - prevent program from terminating
 * @signum: number of signal
 * Return: nothing
 */
void sigint_handler(int __attribute__((unused)) signum)
{
	signal(SIGINT, sigint_handler);
}
