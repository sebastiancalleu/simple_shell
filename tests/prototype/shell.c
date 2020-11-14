#include "holberton.h"

/**
 * main - this function work as a shell
 * Return: 0 if success.
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int characters;
	int a = 0;

	while (characters != -1)
	{
		printf("$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters < 0)
		{
			free(buffer);
			exit(0);
		}
		a = wrdcounter(buffer);
		splitter(buffer, a);
		free(buffer);
		buffer = NULL;
	}
	return (0);
}

/**
 * splitter - this function split a string into an array of strings.
 * @s: string to split.
 * @wrdc: number of words in the string.
 */

void splitter(char *s, int wrdc)
{
	int a = 0, b = 0;
	char *token = strtok(s, " \n");
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
		_strcopy(array[a], token);
		token = strtok(NULL, " \n");
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
