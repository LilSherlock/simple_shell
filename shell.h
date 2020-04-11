#ifndef SHELL_H_
#define SHELL_H_
/*   -----------------     */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
/*   -----------------     */
#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
/*   -----------------     */
int readline(char *buffer);
int interactive(void);
int noninteractive(char *av[], char *env[]);
char ** tokenizer(char *buffer, const char *delim);
char *_strtok(char *str, char *deli);
char *_strchr(char *string, char b);
int _strcmp(const char *s1, const char *s2);
int _stlren(char *string);
unsigned int _strcspn(char *s, char *accept);
char *_strdup(char *str);
char *create_array(unsigned int size, char c);
/*   -----------------     */

#endif /* SHELL_H_ */
