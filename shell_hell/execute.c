#include "shell.h"
/**
 * lsh_num_builtins - builts
 * Return: Always
 */
int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * lsh_launch - this is neccesary to use execute
 * @args: arguments
 * Return: always 1
 */
int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("lsh");
	}
	else
	{
		/* */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (wpid)
	{
		return (1);
	}
	return (1);
}
