#include "shell.h"

char **_tokenizer(char *buffer, const char *delim)
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
		tokens[words] = strdup(clone);
		words++;
	}
	/* ULTIMA POSICION DEL ARREGLO EN NULL */
	tokens[words] = clone;
	free(clone);
	return (tokens);
}
/*                */
char **lsh_split_line(char *line)
{
  int bufsize = BUFFER_SIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += BUFFER_SIZE
;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}