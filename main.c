#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
int main(int ac, char *av[], char *env[])
{
	/* the program could be used on interactive mode  and non-interactive mode */
	/* for this features the shell program must check the args */
	/* and execve each command wioth its env variables*/
	
	char *buffer[];
	size_t n = BUFFER_SIZE;
	ssize_t bytes = 0, error = 0;

	buffer = malloc(sizeof(char *));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}


	/* prompt  is necesary for task 3. Simple shell 0.1 */

	while (error == 0)
	{
		*buffer = NULL;
		printf("$ ");
		if ((*buffer = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
		{	
			perror("Unable to allocate buffer");
			exit(1);
		}
		bytes = getline(buffer, &n, stdin);
		/* get arguments with strtok or without it */
		/* IT's NECESARY FOR TASK 5.Simple shell 0.2, try to do it wothout strtok  for advanced points*/
		printf("$ %s", *buffer);
		/* execute the command */
 		free(*buffer);
		if (bytes == -1)
			error = 
			
	}

	free(buffer);
	return (0);
}