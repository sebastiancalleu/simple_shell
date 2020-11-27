#include "holberton.h"

/**
 * _strlen - this function calculates the lenght of a string.
 * @str: the string.
 * Return: the lenght.
 */

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a]; a++)
	{
	}
	return (a);
}

/**
 * notcommandfound - this function procede with a not-found command.
 * @arg_array: the array of args.
 * @av: arguments array.
 * @count: cycle count.
 */
void notcommandfound(char **arg_array, char **av, int count)
{
	int freec;

	write(1, av[0], _strlen(av[0]));
	write(1, ": ", 2);
	printnum(count);
	write(1, ": ", 2);
	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 10);
	for (freec = 0; arg_array[freec]; freec++)
		free(arg_array[freec]);
	free(arg_array);
}

/**
 * exitshell - this function ends the shell.
 * @array: arg array.
 * @str: line with the args.
 * @exitstate: exit code.
 */

void exitshell(char **array, char *str, int exitstate)
{
	if (array[1])
		exitstate = _atoi(array[1]);
	freearray(array);
	free(str);
	exit(exitstate);
}

/**
 * _atoi - this function converts a char to int.
 * @s: the string.
 * Return: the int.
 */

int _atoi(char *s)
{
	unsigned int res = 0;
	int resNeg = 0;
	int signo = 1;

	while (*s)
	{
		/* compruebo si hay - o + y multiplica */
		if (*s == '-')
			signo *= -1;
		/* imprime números */
		if (*s >= '0' && *s <= '9')
		{
			/* Multiplica x 10 para agregar decena */
			res = res * 10 + *s - '0';
			/* salgo del loop cuando pasa número */
			if (s[1] < '0' || s[1] > '9')
				break;
		}
		s++;
	}
	/*Según el signo cambio de un unsiged a signed int*/
	if (signo < 0)
		return (resNeg = res * signo);
	else
		return (res * signo);
}