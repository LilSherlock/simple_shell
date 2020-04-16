#include "shell.h"

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};
int lsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    /* Child process */
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    /* Error forking */
    perror("lsh");
  } else {
    /* */
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  if (!wpid)
        return(1);

  return 1;
}

int lsh_num_builtins() 
{
  return sizeof(builtin_str) / sizeof(char *);
}


int lsh_execute(char **args)
{
  int i;
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
  return (lsh_launch(args));
}