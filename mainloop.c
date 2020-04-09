#include "shell.h"
void hshloop(void)
{
	/* store variables to execute */
	char *buffer, **arguments;
	size_t n = BUFFER_SIZE, words = 0, i = 0;
	ssize_t bytes = 0, error = 0;

	while(error == 0)
	{
		buffer = readline();
		arguments = tokenizer(buffer);
		if (buffer = NULL)
			error = -1;
		free(arguments);
	}
	free(buffer);
}

