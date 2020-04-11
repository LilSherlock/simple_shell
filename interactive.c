#include "shell.h"
/**
 * interactive - 
 * 
 */
int interactive(void)
{
	/* store variables to execute */
	char *buffer, **arguments = NULL;
	const char *delim = " ";
	ssize_t status = 0;
	

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
		/* argumentos es un arreglo de strings */
		arguments = tokenizer(buffer, delim);
		/* aqui se deberia comprobar que el comando ingresado exista */
		
		
		/* liberando todos los argumentos */
		free(arguments);
		free(buffer);
	}
	return (status);
}
