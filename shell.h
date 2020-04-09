#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#define BUFFER_SIZE 1024

char *readline(void);
void hshloop(void);
char **tokenizer(char *buffer);
char *_strtok(char *str, char *deli);
char *_strchr(char *string, char b);
unsigned int _strcspn(char *s, char *accept);

#endif /* SHELL_H_ */
