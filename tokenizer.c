#include "shell.h"

char** tokenizer(char *buffer)
{
	char *tokens[4096], *clone, **tokAddress;
	size_t words = 0;

	for (; clone != NULL; clone = strtok(NULL, " "))
	{
		clone = strtok(NULL, " ");
		tokens[words] = clone;
		words++;
	}
	tokens[words] = clone;
	tokAddress = malloc(sizeof(char *) * words);
	if (tokAddress == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	tokAddress = tokens;
	return(tokAddress);
}