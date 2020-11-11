#include <stdio.h>
#include <stdlib.h>

int input(char *s,int length);

int main()
{
    char *buffer;
    size_t bufsize = 0;
    size_t characters;

    buffer = malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
	while (characters != -1)
	{
		printf("$ ");
    	characters = getline(&buffer,&bufsize,stdin);
		if (characters < 0)
		{
			free(buffer);
			exit;
		}
		/* code here */
		free(buffer);
		buffer = NULL;
	}
		printf("\n");
    return(0);
}