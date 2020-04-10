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
		/* cada posicion de tokens se llena con el clon */
		tokens[words] = clone;
		words++;
	}
	/* ULTIMA POSICION DEL ARREGLO EN NULL */
	tokens[words] = clone;
	return(tokens);
}