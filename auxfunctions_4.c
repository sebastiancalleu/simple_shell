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
 */
void notcommandfound(char **arg_array)
{
	int freec;

	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	printnum(1);
	write(1, ": ", 2);
	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 10);
	for (freec = 0; arg_array[freec]; freec++)
		free(arg_array[freec]);
	free(arg_array);
}
