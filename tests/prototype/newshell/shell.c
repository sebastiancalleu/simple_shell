#include "holberton.h"

/**
 * main - emulates a shell
 * @ac: arguments count
 * @av: argouments values
 * Return: 0 if success, -1 on error.
 */
int main(int ac, char **av)
{
	int characters = 0, exit = 0, glcount = 0;
	char *promt_sign = "$ ", *arguments = NULL, **arg_array = NULL;
	size_t arguments_size = 0;

	signal(SIGINT, sigint_handler);
	if (ac > 1)
	{
		create_nonInterac_arg_array(ac, av, &arg_array);
		execute(&arg_array, glcount, av);
		free_arguments(&arg_array, &arguments);
	}
	else
	{
		while (characters != EOF)
		{
			glcount++;
			check_error(write(STDOUT_FILENO, promt_sign, _strlen(promt_sign)));
			characters = getline(&arguments, &arguments_size, stdin);
			if (characters != EOF)
				exit = check_exit(arguments);
			if (characters == EOF || exit == -1)
			{
				free(arguments);
				break;
			}
			if (get_arguments(&arguments, &arg_array) != -1)
			{
				execute(&arg_array, glcount, av);
				free_arguments(&arg_array, &arguments);
			}
		}
		if (exit != -1)
			check_error(write(STDOUT_FILENO, "\n", 1));
	}
	return (0);
}
