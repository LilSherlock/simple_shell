#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/* add functionality to main args */
int main(__attribute__((unused)) int ac, char *av[], char *env[])
{

	/* aqui estamos seleccionando el tipo de modod que se va a usar */
	int status = 0;
	if(isatty(STDIN_FILENO) == 1) /* esta funcion dice si esta en la terminal o no */
	{
		/* entrando al modo interactivo, retorna estado del programa */
		status = interactive();
	}
	else
	{
		/* entrando al modo no interactivo */
		status = noninteractive(av, env);
	}
	

	return (status);
}