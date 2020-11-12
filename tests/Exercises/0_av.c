#include <stdio.h>

/**
 * main - this function prints the arguments.
 * av: the args array.
 */

int main(int __attribute__((unused))ac, char *av[])
{
	int a;

	for(a = 0; av[a]; a++)
	{
		printf("%s ", av[a]);
	}
	printf("\n");
	return (0);
}