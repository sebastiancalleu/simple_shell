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

	check_error(write(1, promt_sign, _strlen(promt_sign)));
	signal(SIGINT, sigint_handler);
}

/**
 * check_file - checks if file exist
 * @file: file to check
 * Return: 0 on succes, -1 on failure, -2 if file exits
 * but has not executable instruction
 */
int check_file(char *file)
{
	struct stat st;
	int _return = -1;
	int i = 0;
	int bytes_exe = 0;
	int bytes_letters = 0;

	if (stat(file, &st) == 0)
	{
		for (i = 0; file[i]; i++)
		{
			if (file[i] == '.' || file[i] == '/')
				bytes_exe++;
			if (file[i] != '.' && file[i] != '/')
				bytes_letters++;
		}
		if (bytes_exe > 0 && bytes_letters == 0)
			_return = -2;
		if (bytes_exe == 0 && bytes_letters > 1)
			_return = -2;
		if (bytes_exe == 2 && bytes_letters > 1)
		{
			if ((file[0] != '.' && file[1] != '/') && file[0] != '/')
				_return = -2;
		}
	}
	return (_return);
}

/**
 * push_char - push a char into a string
 * @string: string to be appended with letter
 * @letter: letter to append
 * Return: nothing
 */
void push_char(char **string, char letter)
{
	int temp_length = 0;
	char *temp = NULL;

	if (*string == NULL)
	{
		*string = malloc(2 * sizeof(char));
		(*string)[0] = letter;
		(*string)[1] = '\0';
	}
	else
	{
		temp_length = _strlen(*string);
		temp = malloc((temp_length + 1) * sizeof(char));
		_strcpy(temp, *string);
		free(*string);
		*string = malloc((_strlen(temp) + 2) * sizeof(char));
		_strcpy(*string, temp);
		(*string)[_strlen(temp)] = letter;
		(*string)[_strlen(temp) + 1] = '\0';
		free(temp);
	}
}

/**
 * notfoundfunc - this function procede with a not-found command.
 * @arg_array: the array of args.
 * @glcount: count of the getline cycles.
 * @av: array of arguments of the shell.
 */
void notfoundfunc(char **arg_array, int glcount, char **av)
{

	write(1, av[0], _strlen(av[0]));
	write(1, ": ", 2);
	printnum(glcount);
	write(1, ": ", 2);
	write(1, arg_array[0], _strlen(arg_array[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 10);
}
