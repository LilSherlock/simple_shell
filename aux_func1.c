#include "shell.h"

int _strcmp(const char *s1, const char *s2) 
{
   while (*s1 != '\0' && *s2 != '\0'  && *s1 == *s2) 
   {
	  s1++;
	  s2++;
   }
   return *s1 - *s2;
}

int _stlren(char *string)
{
	int x = 0;

	while(string[x])
			x++;

	return (x);
}