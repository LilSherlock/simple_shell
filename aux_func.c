#include "shell.h"

char *_strchr(char *string, char b)
{
	while (*string != '\0')
	{
		if (*string == b)
				return (string);
		string++;
	}
	if (*string == b)
				return (string);
	return (0);
}
char *_strtok(char *str, char *deli)
{
	int c;
	static char *string;

	if (!str)
			str = string;
	c = *str++;
	while (_strchr(deli, c))
	{
		if  (c == 0)
				return (0);
		c = *str++;
	}
	--str;
	string = str + _strcspn(str, deli);
    if (*string != 0)
    {
        *string = 0;
        string++;
    }
    return (str);
}


unsigned int _strcspn(char *s, char *accept)
{
	unsigned int i, j;

	i = 0;
	while(s[i] != '\0')
	{
		j = 0;
		while (accept[j] == '\0' && s[i] != accept[j])
				j++;
		if (accept[j] == '\0')
				return (i);
		i++;
	}
	return (i);
}