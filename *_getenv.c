#include "shell.h"

char *_getenv(const char *name, char **env)
{
	int x = 0, y = 0, length = 0, tag = 0;

	while(env[x] != NULL)
	{
		tag = _strcmp(name, (const char * )env[i]);
		if (tag == 1)
		{
			length = _stlren(env[i]);
			while (env[x][y] != '=')
			y += 1;
			length -= j;
			return (env[i] + j + 1);
		}
		x++;
	}
	return (NULL);
}