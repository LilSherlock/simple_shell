#include "shell.h"
/**
 * lsh_cd - function to use cd
 * @args: direction
 * Return: always 1
 */

int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}
/**
 * lsh_exit - exit function
 * Return: (0)
 */
void lsh_exit(void)
{
	return (-1);
}
