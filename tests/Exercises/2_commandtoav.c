#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *_calloc(int, int);
int _strlen(char *);
void _strcopy(char *, char *);

/**
 * splitter - this function split a string into an array of strings.
 */
void splitter(char *s, int wrdc)
{
	int a = 0;
	char *token = strtok(s, " ");
	char **array;

	array = _calloc((wrdc + 1), sizeof(char *));
	for (a = 0; token != NULL; a++)
	{
		array[a] = _calloc((_strlen(token) + 1), sizeof(char));
		_strcopy(array[a], token);
		token = strtok(NULL, " ");
	}
	array[a] = NULL;
	/* esto de aqui es prueba de que el array salga bien */
	for (a = 0; array[a]; a++)
	{
		printf("%s\n", array[a]);
	}
	/* hasta aqui va la prueba */
	/* aqui debe ir nuestro codigo para seleccionar funcion segun el array*/
	for (a = 0; a < wrdc; a++)
		free(array[a]);
	free(array);
}

void *_calloc(int a, int b)
{
	char *str;
	int c;

	if (a == 0 || b == 0)
		return(NULL);
	str = malloc(a * b);
	if (str == NULL)
		return (NULL);
	for (c = 0; c < a; c++)
	{
		str[c] = '\0';
	}
	return (str);
}

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a]; a++)
	{
	}
	return (a);
}

void _strcopy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
}