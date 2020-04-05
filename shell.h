#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/*typedef struct name
{
    /* data 
}; name */
char *_strtok(char *str, char *deli);
char *_strchr(char *string, char b);
unsigned int _strcspn(char *s, char *accept);
#endif /* SHELL_H_ */
