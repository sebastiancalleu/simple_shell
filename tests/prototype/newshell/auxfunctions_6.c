#include "holberton.h"

/**
 * envprint - this function prints the environment.
 */

void envprint(void)
{
	int a;

	for (a = 0; environ[a] != NULL; a++)
		write(1, environ[a], _strlen(environ[a]));
}

/**
 * stringcomp - this function compares two strings.
 * @str1: the first string.
 * @str2: the second string.
 * Return: 1 if the strings are the same, 0 if not.
 */

int stringcomp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a]; a++)
	{
		if (str1[a] != str2[a])
			return (0);
	}
		if (str1[a] != str2[a])
			return (0);
	return (1);
}