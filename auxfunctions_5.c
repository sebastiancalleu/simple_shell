#include "holberton.h"


/**
 * freearray - this function frees and array of strings.
 * @arg_array: the array of strings.
 */

void freearray(char **arg_array)
{
	int freec;

	for (freec = 0; arg_array[freec]; freec++)
		free(arg_array[freec]);
	free(arg_array);
}

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
