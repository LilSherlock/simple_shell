#include "shell.h"

char *_strdup(char *str)
{
	char *my_array;
	int i, len;

	my_array = malloc(sizeof(str));
	i = len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	if (my_array == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		my_array[i] = str[i];
		i++;
	}
	return (my_array);
}
/**
 * tokenizer - takes a string and splits it into different strings and return the array of strings
 * 
 * 
 */
char **tokenizer(char *buffer, const char *delim)
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
		tokens[words] = _strdup(clone);
		words++;
	}
	/* ULTIMA POSICION DEL ARREGLO EN NULL */
	tokens[words] = clone;
	free(clone);
	return (tokens);
}

