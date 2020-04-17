#include "shell.h"
/**
 * readline - function to read a line
 * @buffer: buffer
 * Return: always 0
 */
int readline(char *buffer)
{
	ssize_t bytes = 0;
	size_t n = BUFFER_SIZE;

	bytes = getline(&buffer, &n, stdin);
	/* si apretan ctrl + d debe parar el ciclo del prompt*/
	if (bytes == EOF)
	{
		return (-1);
	}
	return (0);
}
