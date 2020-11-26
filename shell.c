#include "holberton.h"

/**
 * main - emulates a shell
 * @ac: arguments count
 * @av: argouments values
 * @environ: enviroment
 * Return: 0 if success, -1 on error.
 */
int main(int ac, char **av, char **environ)
{
	int characters = 0, exit = 0, glcount = 0;
	char *promt_sign = "$ ", *arguments = NULL, **arg_array = NULL;
	size_t arguments_size = 0;

	(void)ac;
	if (isatty(STDIN_FILENO))
	{
		/* interactive mode */
		signal(SIGINT, sigint_handler);
		shell_loop(&characters, &glcount, promt_sign, &arguments, &arguments_size,
				   &exit, &av, &arg_array, environ);
		if (exit == 0 || characters == EOF)
			check_error(write(STDOUT_FILENO, "\n", 1));
		if (exit == -1)
			exit = 0;
	}
	else
	{
		/* non interactive mode */
		arguments = malloc(2048 * sizeof(char));
		characters = read(STDIN_FILENO, arguments, 2048);
		create_nonInterac_arg_array(wrdcounter(arguments), &arguments, &arg_array);
		run_command(&arg_array, glcount, av, environ);
		free_arguments(&arg_array, &arguments);
	}
	return (exit);
}

/**
 * shell_loop - emulates the promt, capture and execute commands
 * @characters: number of chracters captured from stdin
 * @glcount: counter of loops for error display
 * @promt_sign: promt sign of the minishell
 * @arguments: arguments captured from stdin
 * @arguments_size: arguments size to handle getline()
 * @exit: store exit codes
 * @av: arguments values from non interactive mode
 * @arg_array: multidimensional array with the arguments given to the shell
 * @enviroment: multidimensional array with the arguments given to the shell
 * Return: nothing
 */
void shell_loop(int *characters, int *glcount, char *promt_sign,
				char **arguments, size_t *arguments_size, int *exit,
				char ***av, char ***arg_array, char **enviroment)
{
	while (*characters != EOF)
	{
		*glcount += 1;
		check_error(write(STDOUT_FILENO, promt_sign, _strlen(promt_sign)));
		*characters = getline(arguments, arguments_size, stdin);
		if (*characters != EOF)
			*exit = check_exit(*arguments);
		if (*characters == EOF || *exit != 0)
		{
			if (*exit == -2 && *characters != EOF)
			{
				exit_illegal_command((*av)[0], *glcount, *arguments);
				free(*arguments);
				*arguments = NULL;
				continue;
			}
			free(*arguments);
			break;
		}
		if (get_arguments(arguments, arg_array) != -1)
		{
			run_command(arg_array, *glcount, *av, enviroment);
			free_arguments(arg_array, arguments);
		}
	}
}
