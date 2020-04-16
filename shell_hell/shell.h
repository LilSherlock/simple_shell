#ifndef SHELL_H_
#define SHELL_H_
/*   -----------------     */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
/*   -----------------     */
#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define DELIM " \t\r\n\a"
/*   -----------------     */
int main(int argc, char **argv);
void shell_loop(void);
char *_readline(void);
char **_tokenizer(char *buffer, const char *delim);
char **lsh_split_line(char *line);
int lsh_cd(char **args);
int lsh_exit(char **args);
int lsh_num_builtins();
int lsh_execute(char **args);

/*   -----------------     */

/* -----------------     */
#endif /* SHELL_H_ */