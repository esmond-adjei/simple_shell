#include "shell.h"
#include <sys/wait.h>

#define CHILDPROCESS 0

/**
 * execute_cmd - executes the given command with the
 * given arguments in a child process
 * @args: a double pointer that holds the arguments for
 * the commandto be executed
 * Return: 1 (Successful), 0 (Otherwise)
 */
int execute_cmd(char **args)
{
	pid_t pid;
	int status;

    struct builtinStruct builtinStructs[] = {
            {"exit", shell_exit},
    };

    for (int i = 0; i < sizeof(builtinStructs) / sizeof(builtinStructs[0]); i++) {
        if (strcmp(args[0], builtinStructs[i].name) == 0) {
            builtinStructs[i].func(args);
            return (1);
        }
    }

	pid = fork();
	if (pid == CHILDPROCESS)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("command error: "); /* COULDN'T EXECUTE ARGUMENT */
		}
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
	{
		perror("fork error: ");
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
	return (1);
}
