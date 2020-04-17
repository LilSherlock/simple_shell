#include "shell.h"
/**
 * builtin_str - commands to use
 */
char *builtin_str[] = 
{
  "cd",
  "exit"
};
/**
 * lsh_num_builtins - builts
 * Return: Always
 */
int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
int lsh_execute(char **args)
{
  int i, f;
  int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_exit
  };
  if (args[0] == NULL) {

    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
  f = lsh_launch(args);
  return (f);
}