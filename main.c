#include "shell.h"

/**
 * main - main function
 * @ac: number of argumments
 * @av: argumments
 * @env: env
 * Return: (status);
*/
int main(__attribute__((unused)) int ac, char *av[], char *env[])
{
	int status = 0;

	if (isatty(STDIN_FILENO) == 1)
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
