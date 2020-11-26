#include "holberton.h"

/**
 * envprint - this function prints the environment.
 * @environ: enviroment
 */

void envprint(char **environ)
{
	int a;

	for (a = 0; environ[a] != NULL; a++)
	{
		write(STDOUT_FILENO, environ[a], _strlen(environ[a]));
		write(STDOUT_FILENO, "\n", 1);
	}
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

/**
 * create_nonInterac_arg_array - create arg_array for non interactive mode
 * @av: arguments values
 * @arg_array: empty arg_array
 * @offset_string: offset string
 * @current_paths_count: word count
 * Return: nothing
 */
void recursion_fill_arg_array(char *av, char ***arg_array,
							  int offset_string, int current_paths_count)
{
	int i = 0;
	int letters_count = 0;
	int letters_count_offset = 0;
	int j = 0;

	/* BASE CASE */
	if (av[i + offset_string] == '\0' || av[i + offset_string] == '\n')
		return;
	for (i = 0; av[i]; i++, letters_count++)
	{
		if (av[i + offset_string] == ' ' || av[(i + offset_string) + 1] == '\n' ||
			av[(i + offset_string) + 1] == '\0')
		{
			if (av[(i + offset_string) + 1] == '\0' ||
				av[(i + offset_string) + 1] == '\n')
				(*arg_array)[current_paths_count] = malloc(sizeof(char) *
														   (letters_count + 2));
			else
				(*arg_array)[current_paths_count] = malloc(sizeof(char) *
														   (letters_count + 1));
			letters_count_offset = letters_count;
			for (; letters_count > 0; letters_count--, j++)
				(*arg_array)[current_paths_count][j] =
					av[(i + offset_string) - letters_count];
			if (av[(i + offset_string) + 1] == '\0' ||
				av[(i + offset_string) + 1] == '\n')
			{
				(*arg_array)[current_paths_count][j] =
					av[(i + offset_string) - letters_count];
				(*arg_array)[current_paths_count][j + 1] = '\0';
			}
			else
				(*arg_array)[current_paths_count][j] = '\0';
			current_paths_count += 1;
			offset_string += letters_count_offset + 1;
			/* RECURSION CALL */
			recursion_fill_arg_array(av, arg_array, offset_string, current_paths_count);
			break;
		}
	}
}
