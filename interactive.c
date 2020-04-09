#include "shell.h"
int interactive(void)
{
	/* store variables to execute */
	char *buffer, **arguments;
	ssize_t error = 0;

	while(error == 0)
	{
		buffer = readline();
		arguments = tokenizer(buffer);
		if (buffer == NULL)
			error = -1;
		free(arguments);
	}
	free(buffer);
	return(error);
}

