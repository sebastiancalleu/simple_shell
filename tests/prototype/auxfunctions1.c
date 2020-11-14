#include "holberton.h"

/**
 * wrdcounter - this function counts the words in a string.
 * @buffer: this is the string.
 * Return: number of words.
 */

int wrdcounter(char *buffer)
{
	int a, count = 0;

	if (buffer[count] != ' ')
		count++;
	for (a = 0; buffer[a] != '\0'; a++)
	{
		if (buffer[a] == ' ' && buffer[a + 1] != ' ')
			count++;
	}
	return (count);
}

/**
 * _calloc - this function allocate and verify the memory assignated.
 * @a: the size.
 * @b: size of the data type.
 * Return: the allocated memory.
 */

void *_calloc(int a, int b)
{
	char *str;
	int c;

	if (a == 0 || b == 0)
		return (NULL);
	str = malloc(a * b);
	if (str == NULL)
		return (NULL);
	for (c = 0; c < a; c++)
	{
		str[c] = '\0';
	}
	return (str);
}

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
 * _strcopy - this function copies a string to other string.
 * @dest: the destination string.
 * @src: the source string.
 */

void _strcopy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
}
