#include "holberton.h"

/**
 * _strcat - this function concatenates two strings.
 * @str1: first string.
 * @str2: second string.
 * Return: the concatened string.
*/

char *_strcat(char *str1, char *str2)
{
	int a, b;

	for (a = 0; str1[a]; a++)
	{
	}
	for (b = 0; str2[b]; b++)
	{
		str1[a] = str2[b];
		a++;
	}
	str1[a] = '\0';
	return (str1);
}
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

/**
 * _strlen - this function calculates the lenght of a string.
 * @str: the string.
 * Return: the lenght.
 */

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a]; a++)
		;
	return (a);
}

/**
 * wrdcounter - this function counts the words in a string.
 * @arguments: this is the string.
 * Return: number of words.
 */
int wrdcounter(char *arguments)
{
	int i, count = 0;

	for (i = 0; arguments[i] != '\0'; i++)
	{
		if ((arguments[i] != ' ' && arguments[i] != '\n') && (arguments[i + 1] == ' '
		|| arguments[i + 1] == '\0' || arguments[i + 1] == '\n'))
			count++;
	}
	return (count);
}