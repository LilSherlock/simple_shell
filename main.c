#include "shell.h"

/**
 * main - main function
 * @ac: number of argumments
 * @av: argumments
 * @env: env
 * Return: (status);
*/
int main(int ac, char *av[])
{
	int status = 0;

	if (ac == 1)
	{
		/* entrando al modo interactivo, retorna estado del programa */
		status = interactive();
	}
	else
	{
		/* entrando al modo no interactivo */
		status = noninteractive(av);
	}
	return (status);
}
