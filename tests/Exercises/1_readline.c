#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
int wrdcounter(char *);

int main()
{
    char *buffer = NULL;
    size_t bufsize = 0;
    int characters;
	int a = 0;

	while (characters != -1)
	{
		printf("$ ");
    	characters = getline(&buffer,&bufsize,stdin);
		if (characters < 0)
		{
			free(buffer);
			exit(0);
		}
		a = wrdcounter(buffer);
		splitter(buffer, a);
		free(buffer);
		buffer = NULL;
	}
    return(0);
}

int wrdcounter(char *buffer)
{
	int a, count = 0;
 	if (buffer[count] != ' ')
		count++;
	for (a = 0; buffer[a] != '\0'; a++)
	{
		if (buffer[a] == ' ' && buffer[a + 1] != ' ')
			count++;
	}
	return (count);
}
