#include "holberton.h"
int check_exit(char *);

/**
 * main - emulates a shell
 *
 * Return: 0 if success, -1 on error.
 */
int main(void)
{
	int characters = 0; /* checks for EOF */
	char *promt_sign = "$ ";
	size_t arguments_size = 0;
	char *arguments = NULL;  /* stores intial buffer */
	char **arg_array = NULL; /* stores array with arguments */
	int error = 0;           /* handle errors for syscalls*/
	int buffer_status = 0;   /* status of buffer, - 1 empty, 0 full*/
	int exit = 0;

	while (characters != EOF)
	{
		error = write(STDOUT_FILENO, promt_sign, _strlen(promt_sign));
		check_error(error);
		characters = getline(&arguments, &arguments_size, stdin);
		if (characters == EOF)
			break;
		if ((exit = check_exit(arguments)) == -1)
		{
			free(arguments);
			break; /* exit if typed "exit" */
		}
		buffer_status = get_arguments(&arguments, &arg_array);
		if (buffer_status != -1)
		{
			execute(arg_array, arguments);
			free_arguments(&arg_array, &arguments);
		}
	}
	if (exit != -1)
		error = write(STDOUT_FILENO, "\n", 1);
	check_error(error);
	return (0);
}

/**
 * check_exit - this function checks for exit arg.
 * @arguments: the arguments line.
 * Return: the status.
 */
int check_exit(char *arguments)
{
	char *exit = "exit";
	int i = 0;
	int bytes = 0;
	int status = 0;

	for (; arguments[i]; i++)
	{
		if (arguments[i] != ' ')
			if (arguments[i] == exit[bytes])
				bytes++;
	};
	if (bytes == 4)
		status = -1;
	return (status);
}
