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
	freearray(array);
	free(str);
	exit(exitstate);
}
