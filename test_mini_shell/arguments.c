#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	int i = 1;

	while (av[i] != '\0')
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}