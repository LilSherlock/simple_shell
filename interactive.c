#include "shell.h"
/**
 * interactive - interactive function
 * Return: status
 */
int interactive(void)
{
	/* store variables to execute */
	char *buffer, **arguments = NULL;
	const char *delim = " ";
	ssize_t status = 0;
	int i;

	while (status == 0)
	{
		buffer = NULL;
		/* el buffer que va a almacenar el string del usuario */
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		printf("$ ");
		/* la funcion que captura la linea y la guarda en buffer */
		status = readline(buffer);
		if (status == -1)
		{
			break;
		}
		buffer = strtok(buffer, "\n");
		/* argumentos es un arreglo de strings */
		arguments = tokenizer(buffer, delim);
		/* aqui se deberia comprobar que el comando ingresado exista */
		if(path(arguments[0]) == NULL)
		{
			/* SAY COMMAND NOT FOUND */
		}
		status = _execve(arguments, arguments[0]);
		i = 0;
		while (arguments[i] != NULL)
		{
			free(arguments[i]);
			i++;
		}
		free(arguments);
		free(buffer);
	}
	return (status);
}
