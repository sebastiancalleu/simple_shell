#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> /* remove when make own version of strtok */
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
void check_error(int);
int _strlen(char *);
int wrdcounter(char *);
int get_arguments(char **, char ***);
/* set extern environ varibale */
extern char **environ;

/**---------- HELPER */
/**
 * check_error - checks status of error
 * @error: number to check
 * Description: if error is -1 then print
 * error message and errno description of
 * the error
 * 
 * Return: nothing
 */
void check_error(int error)
{
	if (error == -1)
	{
		perror("Error");
		exit(1);
	}
}

/**
 * _strlen - this function calculates the lenght of a string.
 * @str: the string.
 * Return: the lenght.
 */

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a]; a++)
		;
	return (a);
}

/**
 * wrdcounter - this function counts the words in a string.
 * @buffer: this is the string.
 * Description: the count of word stops when \n is found
 * 
 * Return: number of words.
 */
int wrdcounter(char *arguments)
{
	int i, count = 0;

	for (i = 0; arguments[i] != '\0'; i++)
	{
		if ((arguments[i] != ' ' && arguments[i] != '\n') && (arguments[i + 1] == ' ' || arguments[i + 1] == '\0' || arguments[i + 1] == '\n'))
			count++;
	}
	return (count);
}

void free_arguments(char ***arg_array, char **arguments)
{

	int i = 0;

	/* free array of arguments */
	for (; *(*arg_array + i); i++)
	{
		free(*(*arg_array + i));
	}
	free(*arg_array);
	*arg_array = NULL;
	/* free initial buffer allocated with get line */
	free(*arguments);
	*arguments = NULL;
}

/**------------ HANDLE_ARGUMENTS */
/**
 * create_memstrings - create memory allocation for new array elements
 * @arguments: string literal
 * @arg_array: array of pointers
 * @wrdc: number of words in the string
 * Description: the array must have enough space for the strings
 * 
 * Return: nothing
 */
void create_memstrings(char **arguments, char **new_array, int wrdc)
{
	int i = 0, bytes = 0;
	int current_wrdc = wrdc;

	while (*(*arguments + i))
	{
		if (*(*arguments + i) != ' ' && *(*arguments + i) != '\n')
			bytes += 1;
		if (*(*arguments + i) == ' ' || *(*arguments + i) == '\n' || *(*arguments + (i + 1)) == '\0')
		{
			if (bytes > 0)
			{
				new_array[wrdc - current_wrdc] = malloc(sizeof(char) * (bytes + 1));
				new_array[wrdc - current_wrdc][bytes] = '\0';
				if (new_array[wrdc - current_wrdc] == NULL)
				{
					perror("Error");
					exit(1);
					/* Free previous allocated memory if fails*/
				}
				bytes = 0;
				current_wrdc--;
			}
		}
		i++;
	}
}

/**
 * copybytes_memstrings - copy bytes from string to array
 * @arguments: string literal
 * @arg_array: array of pointers
 * @wrdc: number of words in the string
 * Description: the array must have enough space for the strings
 * to be copied
 * 
 * Return: nothing
 */
void copybytes_memstrings(char **arguments, char **new_array, int wrdc)
{
	int i = 0, bytes = 0;
	int current_wrdc = wrdc;

	while (*(*arguments + i))
	{
		if (*(*arguments + i) != ' ' && *(*arguments + i) != '\n')
		{
			new_array[wrdc - current_wrdc][bytes] = *(*arguments + i);
			bytes++;
		}
		if (*(*arguments + i) == ' ' || *(*arguments + i) == '\n' || *(*arguments + (i + 1)) == '\0')
		{
			if (bytes > 0)
			{
				bytes = 0;
				current_wrdc--;
			}
		}
		i++;
	}
}

/**
 * splitter - split a string into an array of strings.
 * @arguments: string to split.
 * @wrdc: number of words in the string.
 * 
 * Return: nothing
 */
void splitter(char **arguments, char ***arg_array, int wrdc)
{
	char **new_array = NULL;

	new_array = malloc(sizeof(new_array) * (wrdc + 1));
	new_array[wrdc] = NULL;
	if (new_array == NULL)
	{
		perror("Error");
		exit(1);
	}
	//allocate memory for strings
	create_memstrings(&(*arguments), &(*new_array), wrdc);
	//copy bytes to new memory
	copybytes_memstrings(&(*arguments), &(*new_array), wrdc);
	// asign new array to arg_array
	*arg_array = new_array;
}

/**
 * get_arguments - convert strings literals to an array
 * @arguments: string literal
 * 
 * Return: nothing
 */
int get_arguments(char **arguments, char ***arg_array)
{
	int wrdc = 0;
	int buffer_status = -1;

	wrdc = wrdcounter(*arguments);
	if (wrdc != 0)
	{
		splitter(&(*arguments), &(*arg_array), wrdc);
		buffer_status = 0;
	}
	return (buffer_status);
}

/**------------ EXECUTIONS */
void execute(char **arg_array)
{
	int pid = 0;
	int wstatus; /* store status return signal */

	/* define processes according to pipes */

	pid = fork();
	check_error(pid);
	wait(&wstatus);
	/* return exit code if process terminated ok */
	if (WIFEXITED(wstatus))
		WEXITSTATUS(wstatus);

	if (pid == 0)
	{
		/* child process */
		/**** use envieron to find paths ****/

		/**** use stat to look for file susing path
		 * handle error if file not found ****/

		/*** get new variable with found path and
		 * passit to execve as argument 1 ****/
		int i = 0;
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		execve(arg_array[0], arg_array, environ);

		/* kill child process at exit (provisional)*/
		kill(getpid(), SIGKILL);
	}
}

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

/**
 * main - emulates a shell
 * 
 * Return: 0 if success, -1 on error.
 */
int main()
{
	int characters = 0; /* checks for EOF */
	char *promt_sign = "$ ";
	size_t arguments_size = 0;
	char *arguments = NULL;  /* stores intial buffer */
	char **arg_array = NULL; /* stores array with arguments */
	int error = 0;           /* handle errors for syscalls*/
	int buffer_status = 0;   /* status of buffer, - 1 empty, 0 full*/

	while (characters != EOF)
	{
		error = write(STDOUT_FILENO, promt_sign, _strlen(promt_sign));
		check_error(error);
		characters = getline(&arguments, &arguments_size, stdin);
		if (characters == EOF)
			break;
		if (check_exit(arguments) == -1)
			break; /* exit if typed "exit" */
		buffer_status = get_arguments(&arguments, &arg_array);
		if (buffer_status != -1)
			execute(arg_array);
		if (buffer_status != -1)
			free_arguments(&arg_array, &arguments);
	}
	if (check_exit(arguments) != -1)
		error = write(STDOUT_FILENO, "\n", 1);
	check_error(error);
	return (0);
}
