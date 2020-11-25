#include "holberton.h"

/**
 * splitter - this function split a string into an array of strings.
 * @str: string to split.
 * @wrdc: number of words in the string.
 */

void splitter(char *str, int wrdc)
{
	int a = 0, b = 0;
	char *token = strtok(str, " \n");
	char **array;

	array = _calloc((wrdc + 1), sizeof(char *));
	for (a = 0; token != NULL; a++)
	{
		array[a] = _calloc((_strlen(token) + 1), sizeof(char));
		if (array[a] == NULL)
		{
			while (b < a)
				free(array[b]), b++;
			free(array);
		}
		_strcpy(array[a], token);
		token = strtok(NULL, " \n");
	}
	array[a] = NULL;
	execute(array, str);
	for (a = 0; a < wrdc; a++)
		free(array[a]);
	free(array);
}

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

