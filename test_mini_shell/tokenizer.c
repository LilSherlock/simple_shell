/* retirar etiquetas y ponerlas en shell.h */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#define BUFFER_SIZE 1024
/* char **tokenizer(char *str) */
char main()
{
	/* Eliminar char str[16] */
	char str[16] = "Hola como estas";
	char **tokensAdress;
	char *token;
	int i = 0;

	tokensAdress = malloc(sizeof(char) * 1024);

	if (tokensAdress == NULL)
	{
		free(tokensAdress);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " ");

	while (token != NULL)
	{
		tokensAdress[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	tokensAdress[i] = NULL;
	/*return (tokensAdress); */
	return (0);
}
