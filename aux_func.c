#include "shell.h"
/**
 * _strchr - locates a char in a string
 * @s: the string to check
 * @c: char to find
 *
 * Return: pointer to the first char ocurrency.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (&s[i]);
	if (s[i] == c)
		return (&s[i]);
	else
		return (0);
}
/**
 * _strtok - function to split
 * @str: string
 * @deli: limitador
 * Return: str
 */
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
/**
 * _strcpn - locates a char in a string
 * @s: the string to check
 * @accept: prefix to find
 * Return: integer with match amount.
 */
unsigned int _strcspn(char *s, char *accept)
{
	unsigned int i, j;

	i = 0;
	while (s[i] != '\0')
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
