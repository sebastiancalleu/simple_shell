#include "holberton.h"

/**
 * _strcmp - this function compares two strings.
 * @str1: first string.
 * @str2: second string.
 * Return: 0 if success, -1 if it fail
 */

int _strcmp(char *str1, char *str2)
{
	int a;

	for (a = 0; (str1[a] && str2[a]); a++)
	{
		if (str1[a] != str2[a])
			return (-1);
	}
	return (0);
}

/**
 * _strcpy - this function copies a string to other string.
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
