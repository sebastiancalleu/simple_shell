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
	char *promt_sign = "$ ";
	size_t arguments_size = 0;
	char *arguments = NULL;  /* stores intial buffer */
	char **arg_array = NULL; /* stores array with arguments */

	if (ac > 1)
	{
		arg_array = malloc(sizeof(arg_array) * ac);
		for (; i < ac - 1; i++)
			arg_array[i] = av[i + 1];
		arg_array[i] = NULL;
		execute(arg_array, NULL, glcount, av);
		free(arg_array);
	}
	else
	{
		while (characters != EOF)
		{
			glcount++;
			check_error(write(STDOUT_FILENO, promt_sign, _strlen(promt_sign)));
			characters = getline(&arguments, &arguments_size, stdin);
			if (characters == EOF)
				break;
			exit = check_exit(arguments);
			if (exit == -1)
			{
				free(arguments);
				break; /* exit if typed "exit" */
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
