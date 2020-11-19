#include "holberton.h"

/**
 * main - emulates a shell
 * @ac: arguments counter.
 * @av: array of arguments of the shell.
 * Return: 0 if success, -1 on error.
 */
int main(int ac, char **av)
{
	int characters = 0, exit = 0, glcount = 0, i = 0;
	size_t arguments_size = 0;
	char *arguments = NULL, **arg_array = NULL, *promt_sign = "$ ";

	signal(SIGINT, sigint_handler);
	if (ac > 1)
	{
		arg_array = malloc(sizeof(arg_array) * ac);
		for (; i < ac - 1; i++)
			arg_array[i] = av[i + 1];
		arg_array[i] = NULL;
		execute(arg_array, arguments, glcount, av);
		free(arg_array);
	}
	else
	{
		while (characters != EOF)
		{
			glcount++;
			check_error(write(STDOUT_FILENO, promt_sign, _strlen(promt_sign)));
			characters = getline(&arguments, &arguments_size, stdin);
			exit = check_exit(arguments);
			if (characters == EOF || exit == -1)
			{
				free(arguments);
				break;
			}
			if (get_arguments(&arguments, &arg_array) != -1)
			{
				execute(arg_array, arguments, glcount, av);
				free_arguments(&arg_array, &arguments);
			}
		}
		if (exit != -1)
			check_error(write(STDOUT_FILENO, "\n", 1));
	}
	return (0);
}
