#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"


/* add functionality to main args */
int main(__attribute__((unused)) int ac, char *av[], char *env[])
{
	int status = 0;
	if(isatty(STDIN_FILENO) == 1)
	{
		status = interactive();
	}
	else
	{
		status = noninteractive(av, env);
	}
	

	return (status);
}