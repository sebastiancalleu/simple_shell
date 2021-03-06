#include "holberton.h"

/**
 * main - this function work as a shell
 * @ac: arg counter.
 * @av: arg array.
 * Return: 0 if success.
 */

int main(int ac, char **av)
{
	char *buffer = NULL, **arg_array = NULL;
	size_t bufsize = 0;
	int characters = 0;
	int a = 0, count = 0;

	if (ac > 1)
	{
		create_nonInterac_arg_array(ac, av, &arg_array);
		execute(arg_array, buffer, av, count);
		freearray(arg_array);
		free(buffer);
	}
	else
	{
		while (characters != -1)
		{
			signal(SIGINT, sigint_handler);
			if (isatty(STDIN_FILENO) == 1)
				write(1, "$ ", 2);
			count++;
			characters = getline(&buffer, &bufsize, stdin);
			if (characters < 0)
			{
				free(buffer);
				exit(0);
			}
			a = wrdcounter(buffer);
			splitter(buffer, a, av, count);
			free(buffer);
			buffer = NULL;
		}
	}
	return (0);
}
