#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
int main(void)
{
	char **buffer;
	size_t n = BUFFER_SIZE;
	ssize_t bytes = 0;

	buffer = malloc(sizeof(char *));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	while (1)
	{
		*buffer = NULL;
		printf("$ ");
		if ((*buffer = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
		{	
			perror("Unable to allocate buffer");
			exit(1);
		}
		bytes = getline(buffer, &n, stdin);
		printf("$ %s", *buffer);
 		free(*buffer);
		if (bytes == -1)
			break;
	}

	free(buffer);
	return (0);
}