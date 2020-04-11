#include "shell.h"
/**
 * tokenizer - takes a string and splits it into different strings and return the array of strings
 * 
 * 
 */
char** tokenizer(char *buffer, const char * delim)
{
	char **tokens, *clone = NULL;
	size_t words = 0;
	int cloneLength;
	/* guardando en el heap el espacio para las palabras */
	tokens = malloc(sizeof(char *) * TOKEN_SIZE);
	if (!tokens)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	/* clone guarda cada palabra obtenida de strtok */
	clone = strtok(buffer, delim);
	for (; clone != NULL; clone = strtok(NULL, delim))
	{
		i = 0;
		while(clone[i] != '\0')
			i++;
		tokens[words] = malloc((i + 1)* sizeof(char));
		if(!tokens[words])
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		/* cada posicion de tokens se llena con el clon */
		tokens[words]= _strdup(clone);
		words++;
	}
	/* ULTIMA POSICION DEL ARREGLO EN NULL */
	tokens[words] = clone;
	return(tokens);
}