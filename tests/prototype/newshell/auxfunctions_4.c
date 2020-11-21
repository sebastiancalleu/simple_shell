#include "holberton.h"

/**
 * create_nonInterac_arg_array - create arg_array for non interactive mode
 * @ac: arguments count
 * @av: argouments values
 * @arg_array: empty arg_array
 * Return: nothing
 */
void create_nonInterac_arg_array(int ac, char **av, char ***arg_array)
{
	int i = 0;

	*arg_array = malloc(ac * sizeof(char *));
	for (i = 0; i < ac - 1; i++)
	{
		(*arg_array)[i] = malloc((_strlen(av[i + 1]) + 1) * sizeof(char));
		_strcpy((*arg_array)[i], av[i + 1]);
	}
	(*arg_array)[i] = NULL;
}

/**
 * sigint_handler - prevent program from terminating
 * @signum: number of signal
 * Return: nothing
 */
void sigint_handler(int __attribute__((unused)) signum)
{
	char *promt_sign = "\n$ ";

	check_error(write(STDOUT_FILENO, promt_sign, _strlen(promt_sign)));
	signal(SIGINT, sigint_handler);
}

/**
 * check_file - checks if file exist
 * @file: file to check
 * Return: 0 on succes, -1 on failure
 */
int check_file(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
		return (0);
	else
		return (-1);
}
