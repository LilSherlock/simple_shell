#include "shell.h"
/* sin implementar aun */
int noninteractive(char *av[])
{
	int status;
	status = _execve(av, av[1]);
	return (status);
}