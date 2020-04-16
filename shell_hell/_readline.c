#include "shell.h"
/** COMENTARIOOOOOOOOS */

char *_readline(void)
{
	int bufsize = BUFFER_SIZE;
	int position = 0;
	int i = 0;

	char *buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		/* Lee el caracter */
		i = getchar();
		/* */
		if (i == EOF || i == '\n')
		{
			buffer[position] = '\n';
			return buffer;
		}
		else
		{
			buffer[position] = i;
		}
		position++;
		/* En caso que nos excedamos el buffer, solo realocamos */
		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
		}
	}
}
