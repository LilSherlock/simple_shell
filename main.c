#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#define BUFFER_SIZE 1024

/* add functionality to main args */
int main(void)
{
	/* the program could be used on interactive mode  and non-interactive mode */
	/* for this features the shell program must check the args */
	/* and execve each command wioth its env variables */

	char **buffer, **tokens;
	size_t n = BUFFER_SIZE, words = 0, i = 0;
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
		tokens = malloc(sizeof(char *) * 2);
		*buffer = NULL;
		printf("$ ");
		if ((*buffer = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
		{	
			perror("Unable to allocate buffer");
			exit(1);
		}
		bytes = getline(buffer, &n, stdin);
		//*buffer = strtok(*buffer, "\n");
		/* get arguments with strtok or without it */
		/* IT's NECESARY FOR TASK 5.Simple shell 0.2 */
		/* try to do it wothout strtok  for advanced points */
		/* need to catch the strings in an array , maybe realloc */
		tokens[words] = strtok(*buffer, " ");
		while(tokens[words] != NULL)
		{	
			printf("$ %s\n", tokens[words]);
			tokens = realloc(tokens, words++ * sizeof(char *));
			tokens[words] = malloc(sizeof(char) * 1024);
			tokens[words] = strtok(NULL, " ");
		}
		/* while(tokens[i] != NULL)
		{
			free(tokens[i]);
			i++;
		} */
		/* execute the command */
		//free(tokens[0]);
		free(tokens);
		free(*buffer);
		if (bytes == -1)
			error = -1;
			
	}

	free(buffer);
	return (0);
}