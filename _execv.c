#include "shell.h"

int execve(char **argv, char *path)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == 0)
	{
		status = execve(path, argv, NULL);
		exit(status);
	}
	else
			wait(NULL);
	return (status);
}