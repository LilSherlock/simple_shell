#include "shell.h"
char *readline(void)
{
	char *buffer;
	ssize_t bytes = 0;
	size_t n = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	bytes = getline(&buffer, &n, stdin);
	if (bytes == EOF)
		return (NULL);
	return(buffer);
}