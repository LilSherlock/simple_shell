#include "shell.h"
/**
 * main - This is the root of the shell
 * @argc: Number of arguments
 * @argv: File if is load
 * Return: (exit success)
 */
int main(int argc, char **argv)
{
	 /* Esta seccion es en caso que se cargue un archivo. */
	if (argc == 0 || argv == NULL)
	{
	shell_loop();
	}
	/* Run command loop. */
	shell_loop();

	/* Perform any shutdown/cleanup. */
	return (EXIT_SUCCESS);
}
