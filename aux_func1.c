#include "shell.h"
#include "holberton.h"

/**
 * _strcmp - compares two strings
 * @s1: string one to compare
 * @s2: string two to compare
 * Return: an integer less than 0 if s1 is found
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >  s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _stlren - function strlen
 * @string: string
 * Return: always x
 */
int _stlren(char *string)
{
	int x = 0;

	while (string[x])
	{
		x++;
	}

	return (x);
}
