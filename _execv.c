#include "shell.h"

void _execve(char **command, char *arg)
{
	pid_t child;

	pid = fork();
	if (pid == 0)
	{
		if (execv(args, command, NULL) == -1)
		{
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (child == -1)
	{
		perror("CHILD PROCESS ERROR");
	}
	else 
	{
		wait(NULL);
	}
}