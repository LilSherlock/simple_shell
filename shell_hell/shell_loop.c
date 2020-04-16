#include "shell.h"

void shell_loop(void)
{
  char *line;
  char **args;
  int status;
  do {
    printf("$ ");
    line = _readline();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}